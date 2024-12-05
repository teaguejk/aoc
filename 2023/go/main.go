package main

import (
	"fmt"
	"strconv"
)

func isInt(s string) bool {
	_, err := strconv.Atoi(s)
	return err == nil
}

func main() {
	var d string

	fmt.Println("Run: ")
	fmt.Scanln(&d)

	// not the best way but it works
	fs := map[string]func(){
		"1a": day1a,
		"1b": day1b,
		"2a": day2a,
		"2b": day2b,
		"3a": day3a,
		"3b": day3b,
		"4a": day4a,
	}

	if d == "all" {
		for i := range fs {
			fs[i]()
		}
	} else {
		fs[d]()
	}
}
