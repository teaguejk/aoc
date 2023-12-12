package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func day3a() {
	fmt.Println("Day3a")

	input := "../inputs/input3.txt"

	file, err := os.Open(input)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println(line)
	}
}
