package main

import "fmt"

func main() {


	type Saiyan struct {
		Name string
		Power int
	}

	goku := Saiyan{
			Name: "Goku",
			Power: 9000,
		}

	pickalo := Saiyan{}
	fmt.Printf("Pickalo - Probably Empty\n")
	fmt.Printf("%s:- %d\n", pickalo.Name, pickalo.Power)
	vegeta := Saiyan{Name: "Vegeta"}
	vegeta.Power = 8000

	fmt.Printf("%s:-  %d", goku.Name, goku.Power)

}
