package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func day3b() {
	fmt.Println("Day3b")

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
			} else if ch == '*' {
				num = append(num, "+")
			} else {
				num = append(num, "-")
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

			gearCount := 0
			var vals []int

			if isInt(string(lines[i][j-1])) { // back
				gearCount += 1

				r := i
				c := j - 1

				vals = append(vals, processNumber(r, c, lines))
			}
			if isInt(string(lines[i][j+1])) { // forward
				gearCount += 1

				r := i
				c := j + 1

				vals = append(vals, processNumber(r, c, lines))
			}
			if isInt(string(lines[i-1][j])) { // up
				gearCount += 1

				r := i - 1
				c := j

				vals = append(vals, processNumber(r, c, lines))
			}
			if isInt(string(lines[i+1][j])) { // down
				gearCount += 1

				r := i + 1
				c := j

				vals = append(vals, processNumber(r, c, lines))
			}
			if isInt(string(lines[i-1][j-1])) { // up left
				gearCount += 1

				r := i - 1
				c := j - 1

				vals = append(vals, processNumber(r, c, lines))
			}
			if isInt(string(lines[i-1][j+1])) { // up right
				gearCount += 1

				r := i - 1
				c := j + 1

				vals = append(vals, processNumber(r, c, lines))

			}
			if isInt(string(lines[i+1][j-1])) { // down left
				gearCount += 1

				r := i + 1
				c := j - 1

				vals = append(vals, processNumber(r, c, lines))

			}
			if isInt(string(lines[i+1][j+1])) { // down right
				gearCount += 1

				r := i + 1
				c := j + 1

				vals = append(vals, processNumber(r, c, lines))

			}

			if gearCount > 1 {
				gearRatio := 1
				for _, val := range vals {
					gearRatio = gearRatio * val
				}
				sum += gearRatio
			}
		}
	}

	fmt.Println(sum)
}
