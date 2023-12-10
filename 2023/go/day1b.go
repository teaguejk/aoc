package main

import (
	"bufio"
	"errors"
	"fmt"
	"log"
	"os"
	"strconv"
)

func convertStringNumberToInt(s string) (int, error) {
	stoimap := map[string]int{
		"one":   1,
		"two":   2,
		"three": 3,
		"four":  4,
		"five":  5,
		"six":   6,
		"seven": 7,
		"eight": 8,
		"nine":  9,
		"ten":   10,
	}

	value, exists := stoimap[s]

	if exists {
		return value, nil
	} else {
		return 0, errors.New("Not found")
	}

}

func findFirstNumber(line string) string {
	var first string
	for _, ch := range line {
		if isInt(string(ch)) {
			first = string(ch)
			break
		}
	}
	return first
}

func findLastNumber(line string) string {
	var last string
	length := len(line) - 1

	for i := length; i >= 0; i -= 1 {
		if isInt(string(line[i])) {
			last = string(line[i])
			break
		}
	}
	return last
}

func day1b() {
	fmt.Println("Day1b")

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

		// TODO replace using new logic
		// ? loop through line, check for ints, check for substrings containing string numbers
		// first := findFirstInt(line)
		// last := findLastInt(line)

		first := ""
		last := ""

		concat := first + last

		num, err := strconv.Atoi(concat)

		if err != nil {
			log.Fatal("Bad")
		}

		sum += num
	}

	fmt.Println(sum)
}
