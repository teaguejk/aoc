package main

import (
	"bufio"
	"errors"
	"fmt"
	"log"
	"os"
	"strconv"
)

func findFirstInt(line string) (string, error) {
	for _, ch := range line {
		if isInt(string(ch)) {
			return string(ch), nil
		}
	}

	return "", errors.New("Not found")
}

func findLastInt(line string) (string, error) {
	length := len(line) - 1

	for i := length; i >= 0; i -= 1 {
		if isInt(string(line[i])) {
			return string(line[i]), nil
		}
	}

	return "", errors.New("Not found")
}

func day1a() {
	fmt.Println("Day1a")

	input := "../inputs/input1.txt"

	file, err := os.Open(input)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	sum := 0

	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println(line)

		first, err := findFirstInt(line)
		if err != nil {
			log.Fatal(err)
		}

		last, err := findLastInt(line)
		if err != nil {
			log.Fatal(err)
		}

		concat := first + last

		num, err := strconv.Atoi(concat)

		if err != nil {
			log.Fatal("Bad")
		}

		sum += num
	}

	fmt.Println(sum)
}
