angular.module('brushfire', ['ngRoute', 'toastr', 'compareTo'])
  .config(['$sceDelegateProvider', function($sceDelegateProvider) {
    $sceDelegateProvider.resourceUrlWhitelist([
      'self',
      '*://www.youtube.com/**'
    ]);
  }])

.filter('spaceless', function() {
  return function(input) {
    if (input) {
      return input.replace(/\s+/g, '-');
    }
  };
})

.config(['$routeProvider', function($routeProvider) {

  $routeProvider

    .when('/', {
    templateUrl: '/templates/home.html'
  })

  .when('/signup', {
    templateUrl: '/templates/signup.html',
    controller: 'signupPageController'
  })

    .when('/administration', {
    templateUrl: '/templates/adminUsers.html',
    controller: 'adminUsersPageController'
  })

  .when('/videos', {
    templateUrl: '/templates/videos.html',
    controller: 'videosPageController'
  })

  .when('/profile/:id', {
    templateUrl: '/templates/profile.html',
    controller: 'profilePageController'
  })

  .when('/profile/edit/:id', {
    templateUrl: '/templates/edit-profile.html',
    controller: 'editProfilePageController'
  })

  .when('/restore', {
    templateUrl: '/templates/restore-profile.html',
    controller: 'restorePageController'
  });
}]);