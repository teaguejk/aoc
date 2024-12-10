use std::fs::read_to_string;
use regex::Regex;

pub const INPUT: &str = "./inputs/03.txt";

type Input = String;

pub fn parse(path: &str) -> Input {
    read_to_string(path)
        .expect("error: could not read input file")
}

pub fn part1(input: &Input) -> i32 {
    let regex = Regex::new(r"mul\((\d+),(\d+)\)").unwrap();

    regex
        .captures_iter(input)
        .map(|group| group[1].parse::<i32>().unwrap() * group[2].parse::<i32>().unwrap())
        .sum()
}

pub fn part2(input: &Input) -> i32 {
    0
}
