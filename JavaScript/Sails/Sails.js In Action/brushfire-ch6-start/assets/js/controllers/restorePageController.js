angular.module('brushfire').controller('restorePageController', ['$scope', '$http', 'toastr', function($scope, $http, toastr){

  $scope.restoreForm = {
    loading: false,
    errorMsg: ''
  };

  $scope.restoreProfile = function() {
    
    $scope.restoreForm.loading = true;

    $http.put('/user/restoreProfile', {
      email: $scope.restoreForm.email,
      password: $scope.restoreForm.password
    })
    .then(function onSuccess(sailsResponse){
      console.log(sailsResponse);

      window.location = '#/profile/' + sailsResponse.data[0].id;
    })
    .catch(function onError(sailsResponse) {
      console.log('sailsresponse: ', sailsResponse)
      if (sailsResponse.data.status >= 400 < 404) {
        $scope.restoreForm.errorMsg = 'An unexpected error occurred: ' + (sailsResponse.data || sailsResponse.status);
        toastr.error('The email/password combination did not match a user profile.','', { timeOut: 1000 });
        return;
      }

    })
    .finally(function eitherWay() {
      $scope.restoreForm.loading = false;
    });
  };
}]);