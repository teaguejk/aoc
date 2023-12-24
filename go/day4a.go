package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"regexp"
	"slices"
	"strings"
)

func processSingleCard(line string) int {
	split := strings.Split(line, ":")

	all := split[1]

	nsplit := strings.Split(all, " | ")

	win := nsplit[0]
	num := nsplit[1]

	re := regexp.MustCompile("[0-9]+")
	winning := re.FindAllString(win, -1)
	nums := re.FindAllString(num, -1)

	score := 0

	for _, n := range nums {
		if slices.Contains(winning, n) {
			score++
		}
	}
	return score
}

func day4a() {
	fmt.Println("Day4a")

	input := "../inputs/input4.txt"

	file, err := os.Open(input)

	if err != nil {
		log.Fatal(err)
	}

	sum := 0

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := scanner.Text()

		sum += int(math.Pow(float64(2), float64(processSingleCard(line)-1))) // ugh
	}

	fmt.Println(sum)
}
