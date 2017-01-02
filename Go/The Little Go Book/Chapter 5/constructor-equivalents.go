package main

import "fmt"

type Saiyan struct {
	Name string
	Power int
}

func main() {
	goku := NewSaiyan("Goku", 9000)
	pickalo := new(Saiyan)
	pickalo.Name = "Pickalo"
	pickalo.Power = 5000

	PrintSaiyan(goku)
	PrintSaiyan(pickalo)

}

func NewSaiyan(name string, power int) *Saiyan {
	return &Saiyan{
		Name: name,
		Power: power,
	}
}

func PrintSaiyan(saiyan *Saiyan) {
	fmt.Printf("%s's power is %d\n", saiyan.Name, saiyan.Power)
}


