package main

import "fmt"

type Person struct {
	Name string
}

func (p *Person) Introduce() {
	fmt.Printf("Hi, I'm %s\n", p.Name)
}

type Saiyan struct {
	*Person
	Power int
}

func main() {
	goku := &Saiyan {
		Person: &Person{"goku"},
		Power: 9001,
	}

	goku.Introduce()
	fmt.Println(goku.Name) // Accesses Name inside Person
	fmt.Println(goku.Person.Name) // Even though takes no name we gave the person field a name and it accepts it
}
