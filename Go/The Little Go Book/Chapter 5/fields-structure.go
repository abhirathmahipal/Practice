package main

import "fmt"

type Saiyan struct {
	Name string
	Power int
	Father *Saiyan
}

func main() {
	gohan := &Saiyan{
		Name: "Gohan",
		Power: 1000,
		Father: &Saiyan {
			Name: "goku",
			Power: 9001,
			Father: nil,
		},
	}

	fmt.Println(gohan.Name, gohan.Power)
	fmt.Println(gohan.Father.Name, gohan.Father.Power)
}

