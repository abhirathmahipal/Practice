var Promise = require('bluebird');
var MpEmailAddress = require('machinepack-emailaddresses');

module.exports = {

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
            MpEmailAddress.validate({
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

    promisify: function() {
        var promisesToRun = [this.validateEmailAddress("asfjds"), this.validateISBN("1234567891111"), this.validateName("rockydsafasdfassf")];
        // console.log(promisesToRun);
        
        
        return Promise.all(promisesToRun).then(function(result) {
            console.log("1");
        });        
    },

    run: function() {
        var x = this.promisify();
        x.then(function(result) {
            console.log("2");
        });
    }
}