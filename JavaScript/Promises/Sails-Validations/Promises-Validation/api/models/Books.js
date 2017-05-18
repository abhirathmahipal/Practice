/**
 * Books.js
 *
 * @description :: TODO: You might write a short summary of how this model works and what it represents here.
 * @docs        :: http://sailsjs.org/documentation/concepts/models-and-orm/models
 */

module.exports = {

  attributes: {
    "isbn": {
      required: true,
      minLength: 13,
      type: "string",
      unique: true
    },
    "name": {
      required: true,
      minLength: 1,
      type: "string"
    },
    "author": {
      required: true,
      minLength: 1,
      type: "string"
    },

    "publisher": {
      type: "string",
    },

    "emailAddressAuthor": {
      type: "email",
    },
    
    "publisherCost": {
      type: "integer",
    }
  }
};

