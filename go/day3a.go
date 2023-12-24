package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func processNumber(r int, c int, lines [][]string) int {

	for isInt(string(lines[r][c])) {
		c -= 1
		if c == -1 {
			break
		}
	}

	c += 1
	k := c
	line := lines[r]
	sn := "0"

	for _, val := range line[c:] {
		if isInt(string(val)) {
			sn = sn + string(val)
			lines[r][k] = "-"
			k += 1
		} else {
			break
		}
	}

	s, err := strconv.Atoi(sn)
	if err != nil {
		log.Fatal(err)
	}

	return s
}

func day3a() {
	fmt.Println("Day3a")

	input := "../inputs/input3.txt"

	file, err := os.Open(input)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	var lines [][]string

	for scanner.Scan() {

		line := scanner.Text()

		var num []string

		// collect nums in line and simplify
		for _, ch := range line {
			sch := string(ch)

			if isInt(sch) {
				num = append(num, sch)
			} else if ch == '.' {
				num = append(num, "-")
			} else {
				num = append(num, "+")
			}
		}

		lines = append(lines, num)
	}

	sum := 0
	rmax := len(lines)

	for i, line := range lines {
		for j, val := range line {
			if i == 0 || i == rmax {
				continue
			}

			if val != "+" {
				continue
			}

			if isInt(string(lines[i][j-1])) { // back
				r := i
				c := j - 1

				sum += processNumber(r, c, lines)
			}
			if isInt(string(lines[i][j+1])) { // forward
				r := i
				c := j + 1

				sum += processNumber(r, c, lines)
			}
			if isInt(string(lines[i-1][j])) { // up
				r := i - 1
				c := j

				sum += processNumber(r, c, lines)
			}
			if isInt(string(lines[i+1][j])) { // down
				r := i + 1
				c := j

				sum += processNumber(r, c, lines)
			}
			if isInt(string(lines[i-1][j-1])) { // up left
				r := i - 1
				c := j - 1

				sum += processNumber(r, c, lines)
			}
			if isInt(string(lines[i-1][j+1])) { // up right
				r := i - 1
				c := j + 1

				sum += processNumber(r, c, lines)
			}
			if isInt(string(lines[i+1][j-1])) { // down left
				r := i + 1
				c := j - 1

				sum += processNumber(r, c, lines)
			}
			if isInt(string(lines[i+1][j+1])) { // down right
				r := i + 1
				c := j + 1

				sum += processNumber(r, c, lines)
			}
		}
	}

	fmt.Println(sum)
}
