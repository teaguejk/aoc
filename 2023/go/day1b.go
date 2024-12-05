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
		return 0, errors.New("not found")
	}

}

func findFirstNumber(line string) (string, error) {
	for i, ch := range line {
		if isInt(string(ch)) {
			return string(ch), nil
		}

		possible := ""

		for _, ch := range line[i:] {
			possible = possible + string(ch)
			value, err := convertStringNumberToInt(possible)
			if err != nil {
				continue
			} else {
				return strconv.Itoa(value), nil
			}
		}
	}

	return "", errors.New("not found")
}

func findLastNumber(line string) (string, error) {
	length := len(line) - 1

	for i := length; i >= 0; i -= 1 {
		if isInt(string(line[i])) {
			return string(line[i]), nil
		}

		possible := ""

		for _, ch := range line[i:] {
			possible = possible + string(ch)
			value, err := convertStringNumberToInt(possible)
			if err != nil {
				continue
			} else {
				return strconv.Itoa(value), nil
			}
		}
	}

	return "", errors.New("not found")
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

		first, err := findFirstNumber(line)
		if err != nil {
			log.Fatal(err)
		}

		last, err := findLastNumber(line)
		if err != nil {
			log.Fatal(err)
		}

		concat := first + last

		num, err := strconv.Atoi(concat)

		if err != nil {
			log.Fatal("bad")
		}

		sum += num
	}

	fmt.Println(sum)
}
