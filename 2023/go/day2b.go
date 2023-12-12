package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func findMinimumPerGame(rounds []string) map[string]int {
	cmap := map[string]int{
		"red":   0,
		"green": 0,
		"blue":  0,
	}

	for _, round := range rounds {
		roundValues := strings.Split(round, ",") // n color

		for _, v := range roundValues {

			split := strings.Split(v, " ") // _ <count> <color>

			count, err := strconv.Atoi(split[1])

			if err != nil {
				log.Fatal(err)
			}

			if cmap[split[2]] < count {
				cmap[split[2]] = count
			}
		}
	}

	fmt.Println(cmap)

	return cmap
}

func day2b() {
	fmt.Println("Day2b")

	var powers []int

	input := "../inputs/input2.txt"

	file, err := os.Open(input)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := scanner.Text()
		lineSplit := strings.Split(line, ":")

		results := lineSplit[1]               // n green, n blue, n red; ...
		rounds := strings.Split(results, ";") // n green, n blue, n red

		cmap := findMinimumPerGame(rounds)

		power := cmap["red"] * cmap["green"] * cmap["blue"]
		powers = append(powers, power)

	}

	sum := 0
	for _, v := range powers {
		sum += v
	}

	fmt.Println(sum)
}
