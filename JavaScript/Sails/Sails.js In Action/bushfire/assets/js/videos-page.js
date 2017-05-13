angular.module('brushfire_videosPage', [])
    .config(function($sceDelegateProvider) {
        $sceDelegateProvider.resourceUrlWhitelist([
            'self',
            '*://www.youtube.com**'
        ]);
    });

angular.module('brushfire_videosPage').controller('PageCtrl', [
        '$scope', '$timeout',
    function ($scope, $timeout) {
        $scope.videosLoading = true;

        $timeout(function afterRetrievingVideos() {
            var _videos = [{
                title: 'FUNNY BABY VIDEOS',
                src: 'https://www.youtube.com/embed/_FvTVWjLiHM'
            }, {
                title: 'Justin Bieber - Baby Ft Ludacris',
                src: 'https://www.youtube.com/embed/kffacxfA7G4'
            }, {
                title: 'Charlie bit my finger - again!',
                src: 'https://www.youtube.com/embed/_OB1gSz8sSM'
            }];

            $scope.videosLoading = false;
            $scope.videos = _videos;
        }, 750);
    }
    
]);
