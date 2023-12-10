package main

import (
	"fmt"
)

func main() {
	var d string

	fmt.Println("Enter the problem to run")
	fmt.Scanln(&d)

	// not the best way but it works
	fs := map[string]func(){
		"1a": day1a,
		"1b": day1b,
	}

	if d == "all" {
		for i := range fs {
			fs[i]()
		}
	} else {
		fs[d]()
	}
}
