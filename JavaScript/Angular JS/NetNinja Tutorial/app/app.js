var app = angular.module('myNinjaApp', []);

app.controller('NinjaController', ['$scope', function($scope) {
	$scope.message = "Hey";
	$scope.ninjas = [
		{
			name:"Yoshi",
			belt:"Green",
			rate:50
		},
		{
			name:"Crystal",
			belt:"Yellow",
			rate: 30
		},
		{
			name:"Shaun",
			belt:"Black",
			rate: 40
		},
		{
			name:"Naruto",
			belt:"Black",
			rate: 100
		}
	];

}])
