angular.module('brushfire').controller('profilePageController', ['$location', '$routeParams', '$scope', '$http', function($location, $routeParams, $scope, $http){

  // Just a hack so we can type `SCOPE` in the Chrome inspector.
  SCOPE=$scope;

  /////////////////////////////////////////////////////////////////////////////////
  // When HTML is rendered... (i.e. when the page loads)
  /////////////////////////////////////////////////////////////////////////////////

  // Set up initial objects
  // (kind of like our schema for the page)
  $scope.userProfile = {
    properties: {},
    errorMsg: '',
    saving: false,
    loading: false,
    noProfile: false
  };

  $scope.userProfile.loading = true;

  // Build up route
  var theRoute = '/user/profile/' +  $routeParams.id;

  // Submit GET request to /user/profile/:id
  $http.get(theRoute)
  .then(function onSuccess(sailsResponse){

    // If deleted profile remove interface and show message.
    if (sailsResponse.data.deleted === true) {
      $scope.userProfile.errorMsg = 'No profile found.';
      return $scope.userProfile.noProfile = true;
    }
    // window.location = '#/profile/' + sailsResponse.data.id;
    $scope.userProfile.properties.email = sailsResponse.data.email;
    $scope.userProfile.properties.username = sailsResponse.data.username;
    $scope.userProfile.properties.admin = sailsResponse.data.admin;
    $scope.userProfile.properties.banned = sailsResponse.data.banned;
    $scope.userProfile.properties.gravatarURL = sailsResponse.data.gravatarURL;
    $scope.userProfile.properties.id = sailsResponse.data.id;

    $scope.userProfile.loading = false;
  })
  .catch(function onError(sailsResponse){

    // If no profile found remove interface and show error message.    
    if(sailsResponse.status === 404) {
      $scope.userProfile.noProfile = true;
      $scope.userProfile.errorMsg = 'No profile found.';
      return;
    }

    // Handle all other errors
    $scope.userProfile.errorMsg = 'An unexpected error occurred: '+(sailsResponse.data||sailsResponse.status);

  })
  .finally(function eitherWay(){
    $scope.userProfile.loading = false;
  });

  $scope.removeProfile = function() {

    var theRoute = '/user/removeProfile/' + $scope.userProfile.properties.id;
    $http.put(theRoute, {
        deleted: true
      })
      .then(function onSuccess(sailsResponse) {

          window.location = '#/signup';

        $scope.userProfile.loading = false;
      })
      .catch(function onError(sailsResponse) {
        $scope.userProfile.errorMsg = 'An unexpected error occurred: ' + (sailsResponse.data || sailsResponse.status);

      })
      .finally(function eitherWay() {
        $scope.loading = false;
      });
  };

  $scope.deleteProfile = function() {

    var theRoute = 'user/delete/' + $routeParams.id;

    $http.delete(theRoute)
    .then(function onSuccess(deletedProfile){
      window.location = '#/signup';
    })
    .catch(function onError(err){
      $scope.userProfile.errorMsg = 'An unexpected error occurred: ' + err;
    });
  };
}]);