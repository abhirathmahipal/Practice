package main

import (
    "fmt"
)

// Go doesn't allow unused packages and unused variables

func main() {
    var power int

    // by default go assigns zero to ints
    // false to bools, "" to strings and so on
    power = 9000

    // power := 9000 dynamic typing 
    name, power2 := "Goku", 9000
    fmt.Printf("It's over %d\n", power)
    fmt.Printf("%s's power is over %d\n", name, power2)

}