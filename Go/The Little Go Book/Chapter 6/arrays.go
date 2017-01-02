package main

import "fmt"

func main() {

	var scores [10]int
	scores[0] = 339

	fmt.Println(scores[0])
	fmt.Println(scores[1])

	array := [4]int{9001, 9, 10, 33}

	for index := range array {
		
		fmt.Println(array[index])
	
	}


}

