use std::fs::read_to_string;

pub const INPUT: &str = "./inputs/03.txt";

type Input = Vec<String>;

pub fn parse(path: &str) -> Input {
    read_to_string(path)
        .expect("error: could not read input file")
        .lines()
        .map(|line| line.to_string())
        .collect()
}

pub fn part1(input: &Input) -> i32 {
    
}

pub fn part2(input: &Input) -> i32 {

}
