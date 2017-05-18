/**
 * BooksController
 *
 * @description :: Server-side logic for managing books
 * @help        :: See http://sailsjs.org/#!/documentation/concepts/Controllers
 */

var ValidateHelpers = require('../../utils/ValidateUtils.js');
var BooksValidate = require('../../utils/BooksValidate.js');

module.exports = {

    create: function(req, res){

        var requiredList = ['author', 'isbn', 'name'];
        var paramsWeCareAbout = {};

        _.forEach(BooksValidate.ModelParams, function(param) {
            var value = req.param(param);
            if (!_.isUndefined(value))
                paramsWeCareAbout[param] = value;
        });

        var requiredMissing = ValidateHelpers.checkRequiredParams(requiredList, paramsWeCareAbout);

        if(Object.keys(requiredMissing).length)
            return res.badRequest(requiredMissing);

        
        res.ok(BooksValidate.validateParams(paramsWeCareAbout));

        // Books.create(paramsWeCareAbout, function(err, createdBook) {

        //     if (err) return res.serverError("Could not create this new book");
            
        //     return res.ok("Book created");
        // });

        return
        
    },
	
};

