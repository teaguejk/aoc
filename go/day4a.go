package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"slices"
	"strconv"
	"strings"
)

func processSingleCard(line string) int {
	split := strings.Split(line, ":")

	all := split[1]

	nsplit := strings.Split(all, " | ")

	win := nsplit[0]
	num := nsplit[1]

	lwin := len(win)
	lnum := len(num)

	var winning []int
	var nums []int

	for i := 0; i < lwin; i++ {

		sn := string(win[i])

		if isInt(string(sn)) {
			if i < lwin-1 && isInt(string(win[i+1])) {
				concat := sn + string(win[i+1])

				add, err := strconv.Atoi(concat)

				if err != nil {
					log.Fatal(err)
				}

				winning = append(winning, add)
			} else if i > 0 && !isInt(string(win[i-1])) {
				add, err := strconv.Atoi(sn)

				if err != nil {
					log.Fatal(err)
				}

				winning = append(winning, add)
			}
		}
	}

	for i := 0; i < lnum; i++ {

		sn := string(num[i])

		if isInt(string(sn)) {
			if i < lnum-1 && isInt(string(num[i+1])) {
				concat := sn + string(num[i+1])

				add, err := strconv.Atoi(concat)

				if err != nil {
					log.Fatal(err)
				}

				nums = append(nums, add)
			} else if i > 0 && !isInt(string(num[i-1])) {
				add, err := strconv.Atoi(sn)

				if err != nil {
					log.Fatal(err)
				}

				nums = append(nums, add)
			}
		}
	}

	score := 0

	for _, n := range nums {
		if slices.Contains(winning, n) {
			if score == 0 {
				score++
			} else {
				score *= 2
			}
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

		sum += processSingleCard(line)
	}

	fmt.Println(sum)
}
