package main

import (
	"fmt"
	"os"
	"time"
)

func main() {
	tic := time.Now()

	var s, sep string
	for i := 1; i < len(os.Args); i++ {
		s += sep + os.Args[i]
		sep = " "
	}

	fmt.Println(s)
	fmt.Printf("\n%.2f seconds", time.Since(tic).Seconds())
}
