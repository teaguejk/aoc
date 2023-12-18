package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func day4a() {
	fmt.Println("Day4a")

	input := "../inputs/input4.txt"

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
