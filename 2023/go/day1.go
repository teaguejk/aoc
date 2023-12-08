package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func isInt(s string) bool {
	_, err := strconv.ParseInt(s, 10, 64)
	return err == nil
}

func findFirstInt(line string) string {
	var first string
	for _, ch := range line {
		if isInt(string(ch)) {
			first = string(ch)
			break
		}
	}
	return first
}

func findLastInt(line string) string {
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

func day1a() {
	fmt.Println("Day1a")

	input := "../inputs/input1a.txt"

	file, err := os.Open(input)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	sum := 0

	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println(line)

		first := findFirstInt(line)
		last := findLastInt(line)

		concat := first + last

		num, err := strconv.Atoi(concat)

		if err != nil {
			log.Fatal("Bad")
		}

		sum += num
	}

	fmt.Println(sum)
}
