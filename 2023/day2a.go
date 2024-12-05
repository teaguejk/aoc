package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

const redLimit = 12
const greenLimit = 13
const blueLimit = 14

func checkRounds(rounds []string) bool {
	for _, round := range rounds {
		roundValues := strings.Split(round, ",") // n color

		cmap := map[string]int{
			"red":   0,
			"green": 0,
			"blue":  0,
		}

		for _, v := range roundValues {

			split := strings.Split(v, " ") // _ <count> <color>

			count, err := strconv.Atoi(split[1])

			if err != nil {
				log.Fatal(err)
			}

			cmap[split[2]] = count
		}

		if cmap["red"] > redLimit || cmap["green"] > greenLimit || cmap["blue"] > blueLimit {
			return false
		}
	}

	return true
}

func day2a() {
	fmt.Println("Day2a")

	var games []int

	input := "../inputs/input2.txt"

	file, err := os.Open(input)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := scanner.Text()
		lineSplit := strings.Split(line, ":")

		game := lineSplit[0]    // Game <id>
		results := lineSplit[1] // n green, n blue, n red; ...

		rounds := strings.Split(results, ";") // n green, n blue, n red
		passed := checkRounds(rounds)

		if passed {
			gnum, err := strconv.Atoi(strings.Split(game, " ")[1]) // <id>

			if err != nil {
				log.Fatal(err)
			}

			games = append(games, gnum)
		}
	}

	sum := 0
	for _, v := range games {
		sum += v
	}

	fmt.Println(sum)
}
