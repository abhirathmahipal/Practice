package main

import "fmt"

type Saiyan struct {
    Name string
    Power int
}
func main() {
    // This seems to be the equivalent
    // of malloc in c
    goku := &Saiyan{"goku", 9000}
    Super(goku)
    fmt.Println(goku.Power)
    fmt.Println(goku.Name) 
}

func Super(s *Saiyan) {
    s.Power += 10000
}