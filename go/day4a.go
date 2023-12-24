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

		split := strings.Split(line, ":") // [Card N , All Numbers]

		all := split[1]

		nsplit := strings.Split(all, " | ") // [Winning Numbers, Card Numbers]

		win := nsplit[0]
		num := nsplit[1]

		var winning []int

		lwin := len(win)

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

		fmt.Println(winning)

		var nums []int

		lnum := len(num)

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
					score = 1
				} else {
					score *= 2
				}
			}
		}
		sum += score
	}

	fmt.Println(sum)
}
