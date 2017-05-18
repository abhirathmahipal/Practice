// var Promise = require('bluebird');
var MpEmailAddresses = require('machinepack-emailaddresses');

module.exports = {
    validateServerReject: function(value) {
        return 500;
    },

    validateResolve: function(value) {
        return value;
    },

    validateISBN: function(isbn){
        return new Promise(function(resolve) {
            // Dumb validation
            if (isbn.replace("-", "").length !== 13) resolve("ISBN should be 13 characters long");
            else resolve();
        })
    },

    validateName: function(name) {

        return new Promise(function(resolve) {
            if (name.length > 10) resolve("Name is too long");
            else resolve();
        })

    },

    validateEmailAddress: function(email) {
        return new Promise (function(resolve, reject) {
            MpEmailAddresses.validate({
            string: email
        }).exec({
                error: function(err) {
                    reject(err);
                },
                invalid: function() {
                    resolve("Please enter a valid email address");
                },
                success: function() {
                    resolve();
                }
          });
       });
    },

    validatePublisherAndCost: function(publisher, publisherCost) {
        return new Promise(function(resolve) {
            if (publisher === 'SELF'){
                if (publisherCost !== 0) resolve("If the book is self published, cost should be zero");
            }
        })
    },

    checkRequiredParams: function(requiredParamsList, params) {
        var errorDict = {};

        _.forEach(requiredParamsList, function(requiredParam) {
            if (_.isUndefined(params[requiredParam]))
                errorDict[requiredParam] = "Missing " + requiredParam;
        });

        return errorDict;

    },

    createControllerLevelErrorDict: function(suppliedParams, validateFunctions) {
        var errorDict = {};
        var listOfParams = Object.keys(suppliedParams);
        // console.log(suppliedParams);
        // check if any extra params are passed in. Add to error dict
        // var unsupportedParams = listOfParams.filter(function(field) {return acceptedAttributes.indexOf(field) < 0;})
        // if (unsupportedParams.length)
        //     errorDict['unsupportedParams'] = unsupportedParams;

        // Validations that require only one parameter
        var tempErrorHolder = [];
        var promisesToRun = [];


        _.forEach(listOfParams, function(param) {

            
            // Continue only if validation rules exist for that param
            if(!_.isUndefined(validateFunctions[param])) {
                // tempErrorHolder = [];
                // var validationSetParticularField = validateFunctions[param];
                // _.forEach(validationSetParticularField, function(validateRule) {
                //     var errorMessage = validateRule(suppliedParams[param],errorCallBack);
                //     if (errorMessage)
                //         tempErrorHolder.push(errorMessage);
                // });

                _.forEach(validateFunctions[param], function(validateRule) {
                    promisesToRun.push(validateRule(suppliedParams[param]));
                });
            }
            // if (tempErrorHolder.length)
            //     errorDict[param] = tempErrorHolder;
                       
        });

        // console.log(promisesToRun);


        Promise.all(promisesToRun).then(function(results) {
                tempErrorHolder = results;
                console.log(results);
                console.log("Just before return in ValidateErrorCreation");                
        });
        // validateFunctions['isbn'][0]('dsfasfasfs').then(function(result) {
        //     console.log("manual promise");
        //     console.log(result);
        // }).then(function() {
        //     console.log("hi");
        // });

        return "hi";

    }
}