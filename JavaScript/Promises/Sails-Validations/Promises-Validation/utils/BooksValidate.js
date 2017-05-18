var BooksModel = require('../api/models/Books');
var ValidateUtils = require('./ValidateUtils.js');

module.exports = {
    ModelParams: Object.keys(BooksModel.attributes),

    validateParams: function(params) {
        
        var attributesReceived = Object.keys(params);

        var validateFunctions = {
            "isbn": [
                ValidateUtils.validateISBN,
            ],

            "author": [
                ValidateUtils.validateName,
            ],

            "emailAddressAuthor": [
                ValidateUtils.validateEmailAddress,
            ],

            "name": [
                ValidateUtils.validateName,
            ]
        };

        var complexValidateFunctions = {

            publisherCostNotApplicableToSelfPublish: {
                function: ValidateUtils.validatePublisherAndCost,
                activateIf: ['publisherCost'],
                contingencyReq: ['id'],
                error: "Publisher cost is not applicable is the book is self published",
                arguments: ['publisher', 'publisherCost'],
                contigencyResolve: function(params) {
                    Books.findOne({id: params['id']}).exec(function(err, result) {
                        if (err) return {arguments: {}};
                        else {
                            return {
                                arguments: {
                                    publisher: result['publisher'],
                                    publisherCost: result['publisherCost']
                                }
                            };
                        }
                    });

                }
            },
            
        };

        console.log("Book Validate Params Function");
        return ValidateUtils.createControllerLevelErrorDict(params, validateFunctions);
    }
}