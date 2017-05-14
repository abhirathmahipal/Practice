angular.module('brushfire').controller('editProfilePageController', ['$location', '$routeParams', '$scope', '$http', 'toastr', function($location, $routeParams, $scope, $http, toastr) {

  // Just a hack so we can type `SCOPE` in the Chrome inspector.
  SCOPE = $scope;

  /////////////////////////////////////////////////////////////////////////////////
  // When HTML is rendered... (i.e. when the page loads)
  /////////////////////////////////////////////////////////////////////////////////

  // Set up initial objects
  // (kind of like our schema for the page)
  $scope.editProfile = {
    properties: {},
    errorMsg: '',
    error: false,
    saving: false,
    loading: false,
    changePassword: {}
  };

  $scope.editProfile.loading = true;
  
  var theRoute = '/user/profile/' + $routeParams.id;

  // Submit GET request to Sails.
  $http.get(theRoute)
    .then(function onSuccess(sailsResponse) {

      $scope.editProfile.properties.gravatarURL = sailsResponse.data.gravatarURL;
      $scope.editProfile.properties.email = sailsResponse.data.email;
      $scope.editProfile.properties.username = sailsResponse.data.username;
      $scope.editProfile.properties.admin = sailsResponse.data.admin;
      $scope.editProfile.properties.banned = sailsResponse.data.banned;
      $scope.editProfile.properties.id = sailsResponse.data.id;
      $scope.editProfile.loading = false;
    })
    .catch(function onError(sailsResponse) {
      console.log(sailsResponse);

      // set error state
      $scope.editProfile.error = true;

      // If 404 not found display message
      if (sailsResponse.status === 404) {
        $scope.editProfile.errorMsg = 'The user profile you were searching for does not exist.';

      } else {

        // Otherwise, display generic error if the error is unrecognized.
        $scope.editProfile.errorMsg = 'An unexpected error occurred: ' + (sailsResponse.data || sailsResponse.status);
      }
    })
    .finally(function eitherWay() {
      $scope.editProfile.loading = false;
    });

  $scope.updateProfile = function() {

    var theRoute = '/user/updateProfile/' + $routeParams.id;

    // Submit PUT request to Sails.
    $http.put(theRoute, {
        gravatarURL: $scope.editProfile.properties.gravatarURL
      })
      .then(function onSuccess(sailsResponse) {

        // Notice that the sailsResponse is an array and not a single object
        // The .update() model method returns an array and not a single record.
        window.location = '#/profile/' + sailsResponse.data[0].id;

        $scope.editProfile.loading = false;
      })
      .catch(function onError(sailsResponse) {
        $scope.editProfile.errorMsg = 'An unexpected error occurred: ' + (sailsResponse.data || sailsResponse.status);

      })
      .finally(function eitherWay() {
        $scope.editProfile.loading = false;
      });
  };

  $scope.restore = function() {

    // Submit PUT request to Restore GravatarURL.
    $http.put('/user/restoreGravatarURL', {
        email: $scope.editProfile.properties.email
      })
      .then(function onSuccess(sailsResponse) {

        // Restore the current gravatarURL
        $scope.editProfile.properties.gravatarURL = sailsResponse.data;

        $scope.editProfile.loading = false;
      })
      .catch(function onError(sailsResponse) {
        $scope.editProfile.errorMsg = 'An unexpected error occurred: ' + (sailsResponse.data || sailsResponse.status);
      })
      .finally(function eitherWay() {
        $scope.editProfile.loading = false;
      });
  };

  $scope.changeMyPassword = function() {
    $http.put('/user/changePassword', {
        id: $scope.editProfile.properties.id,
        password: $scope.editProfile.properties.password
      })
      .then(function onSuccess(sailsResponse) {

        window.location = '#/profile/' + $scope.editProfile.properties.id;

        $scope.editProfile.loading = false;
      })
      .catch(function onError(sailsResponse) {
        $scope.editProfile.changePassword.errorMsg = 'An unexpected error occurred: ' + (sailsResponse.data || sailsResponse.status);
      })
      .finally(function eitherWay() {
        $scope.editProfile.loading = false;
      });
  };
}]);