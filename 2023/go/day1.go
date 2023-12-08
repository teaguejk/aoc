package main

import (
	"fmt"
	"os"
    "bufio"
	"log"
)

func day1a() {
	fmt.Println("Day1a")
	
	input := "../inputs/input1a.txt"

	file, err := os.Open(input)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	// stringToIntMap

	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println(line)
		// for _, ch := range line {
		// 	if string(ch)
		// }
	}
}