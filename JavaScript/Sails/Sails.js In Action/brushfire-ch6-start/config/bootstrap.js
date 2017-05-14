/**
 * Bootstrap
 * (sails.config.bootstrap)
 *
 * An asynchronous bootstrap function that runs before your Sails app gets lifted.
 * This gives you an opportunity to set up your data model, run jobs, or perform some special logic.
 *
 * For more information on bootstrapping your app, check out:
 * http://sailsjs.org/#!/documentation/reference/sails.config/sails.config.bootstrap.html
 */

module.exports.bootstrap = function(cb) {

  // Return the number of records in the video model
  Video.count().exec(function(err, numVideos) {
    if (err) {
      return cb(err);
    }

    // If there's at least one log the number to the console.
    if (numVideos > 0) {
      console.log('Existing video records: ', numVideos)
      return cb();
    }

    // Add machinepack-youtube as a depedency
    var Youtube = require('machinepack-youtube');

    // List Youtube videos which match the specified search query.
    Youtube.searchVideos({
      query: 'grumpy cat',
      apiKey: sails.config.google.apiKey,
      limit: 15,
    }).exec({
      // An unexpected error occurred.
      error: function(err) {

      },
      // OK.
      success: function(foundVideos) {
        _.each(foundVideos, function(video) {
          video.src = 'https://www.youtube.com/embed/' + video.id;
          delete video.description;
          delete video.publishedAt;
          delete video.id;
          delete video.url;
        });

        Video.create(foundVideos).exec(function(err, videoRecordsCreated) {
          if (err) {
            return cb(err);
          }
          console.log(foundVideos);
          return cb();
        });
      },
    });
  });
};
