/**
 * UserController
 *
 * @description :: Server-side logic for managing users
 * @help        :: See http://sailsjs.org/#!/documentation/concepts/Controllers
 */
var Emailaddresses = require('machinepack-emailaddresses');
var Passwords = require('machinepack-passwords');
var Gravatar = require('machinepack-gravatar');

module.exports = {
  signup: function(req, res) {
    if (_.isUndefined(req.param('email')))
      return res.badRequest("An email is required");

    if (_.isUndefined(req.param('password')))
      return res.badRequest("Password missing");

    if (req.param('password').length < 6)
      return res.badRequest("At least 6 characters please");

    if (_.isUndefined(req.param('username')))
      return res.badRequest("A username is required");

    if (req.param('username').length < 6)
      return res.badRequest("Username must be at least 6 characters!");

    if (!_.isString(req.param('username')) ||
        req.param('username').match(/[^a-z0-9]/i))
      return res.badRequest("username must consist of numbers and letters only");

    Emailaddresses.validate({
      string: req.param('email')

    }).exec({
      error: function(err) {
        return res.serverError(err);
      },
      invalid: function() {
        return res.badRequest("Doesn't look like a valid email address to me!");
      },
      success: function() {
        Passwords.encryptPassword({
          password: req.param('password'),
        }).exec({
          error: function(err) {
            return res.serverError(err);
          },
          success: function(result) {
            try {
              var gravatarURL = Gravatar.getImageUrl({
                emailAddress: req.param('email'),
              }).execSync();
            } catch (err) {
              return res.serverError(err);
            }

            var options = {
              email: req.param('email'),
              username: req.param('username'),
              encryptedPassword: result,
              gravatarURL: gravatarURL
            };

            User.create(options).exec(function(err, createdUser) {
              if (err) {
                if (err.invalidAttribute && err.invalidAttributes.email
                  && err.invalidAttributes.email[0] && err.invalidAttributes.email[0].rule === 'unique') {
                    return res.alreadyInUse(err);
                  }

                if (err.invalidAttributes && err.invalidAttributes.username && err.invalidAttributes.username[0] && err.invalidAttributes.username[0].rule === 'unique')
                  return res.send(409, "username is already taken");

                return res.alreadyInUse(err);
              }
              return res.json(createdUser);
            });

          }
        });
      }
    });
  },


  profile: function(req, res) {
    User.findOne(req.param('id')).exec(function  foundUser(err, user) {
      if (err) return res.negotiate(err);
      if (!user) return res.notFound();

      var options = {
        email: user.email,
        username: user.username,
        gravatarURL: user.gravatarURL,
        deleted: user.deleted,
        admin: user.admin,
        banned: user.banned,
        id: user.id
      };
      return res.json(user);
    });
  },


  delete: function(req, res) {
    if (!req.param('id'))
      return res.badRequest('id is a required parameter');

    User.destroy({
      id: req.param('id')
    }).exec(function (err, usersDestroyed) {
      if (err) return res.negotiate(err);
      if (usersDestroyed.length === 0)
        return res.notFound();

      return res.ok();
    });
  },

  removeProfile: function(req, res) {
    if (!req.param('id'))
      return res.badRequest('id is a required parameter');

    User.update({
      id: req.param('id')
    }, {
      deleted: true
    }, function(err, removedUser) {
      if (err) return res.negotiate(err);
      if (removedUser.length === 0) {
        return res.notFound();
      }

      return res.ok();
    });
  },

  restoreProfile: function(req, res) {

    User.findOne({
      email: req.param('email')
    }, function foundUser(err, user) {
      if (err) return res.negotiate(err);
      if (!user) return res.notFound();

      Passwords.checkPassword({
        passwordAttempt: req.param('password'),
        encryptedPassword: user.encryptedPassword
      }).exec({
        error: function(err) {
          return res.negotiate(err);
        },

        incorrect: function() {
          return res.notFound();
        },

        success: function() {
          User.Update({
            id: user.id
          }, {
            deleted: false
          }).exec(function(err, updatedUser) {
            return res.json(updatedUser);
          });
        }
      })
    })
  },

  restoreGravatarURL: function(req, res) {
    try {
      var restoredGravatarURL = gravatarURL = Gravatar.getImageUrl({
        emailAddress: req.param('email')
      }).execSync();
      return res.json(restoredGravatarURL);
    } catch (err) {
      return res.serverError(err);
    }
  },

  changePassword: function(req, res) {
    if (_.isUndefined(req.param('password')))
      return res.badRequest('A password is required');

    if (req.param('password').length < 6) {
      return res.badRequest('Password must be at least 6 characters');

      Password.encryptPassword({
        password: req.param('password'),
      }).exec({
        error: function(err) {
          return res.serverError(err);
        },

        success: function(result) {
          User.update({
            id: req.param('id')
          }, {
            encryptPassword: result
          }).exec(function(err, updatedUser) {
            if (err) {
              return res.negotiate(err);
            }
            return res.json(updatedUser);
          })
        }
      })
    }
  },

  adminUsers: function(req, res) {
    User.find().exec(function(err, users) {
      if (err) return res.negotiate(err);
      return res.json(users);
    });
  },

  updateAdmin: function(req, res) {
    User.update(req.param('id'), {
        admin: req.param('admin')
    }).exec(function(err, udpate) {
      if (err) return res.negotiate(err);

      res.ok();
    });
  },

  updateBanned: function(req, res) {

    User.update(req.param('id'), {
        banned: req.param('banned')
    }).exec(function(err, udpate) {
      if (err) return res.negotiate(err);

      res.ok();
    });
  },

  updateDeleted: function(req, res) {

    User.update(req.param('id'), {
        deleted: req.param('deleted')
    }).exec(function(err, udpate) {
      if (err) return res.negotiate(err);

      res.ok();
    });
  },

  updateProfile: function(req, res) {
    User.update({
      id: req.param('id')
    }, {
      gravatarURL: req.param('gravatarURL')
    }, function(err, updatedUser) {
      if (err) return res.negotiate(err);

      return res.json(updatedUser);
    });
  }

};


