use std::fs::read_to_string;
use std::collections::HashMap;

pub const INPUT: &str = "./inputs/01.txt";

type Input = (Vec<i32>, Vec<i32>);

pub fn parse(path: &str) -> Input {
    read_to_string(path)
        .expect("error: could not read input file")
        .lines()
        .map(|line| {
            let nums: Vec<i32> = line
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

            (nums[0], nums[1])
        })
        .unzip()
}

pub fn part1(input: &Input) -> i32 {
    let mut left = input.0.clone();
    let mut right = input.1.clone();

    left.sort_unstable();
    right.sort_unstable();

    left.iter().zip(right.iter()).map(|(l, r)| (l - r).abs()).sum()
}

pub fn part2(input: &Input) -> i32 {
    let mut similarities: HashMap<i32, i32> = HashMap::new();

    let left = input.0.clone();
    let right = input.1.clone();

    for i in 0..left.len() {
        similarities.insert(left[i], 0);
    }

    for i in 0..right.len() {
        if let Some(count) = similarities.get_mut(&right[i]) {
            *count += 1;
        }
    }

    similarities.iter().filter(|&(_, &count)| count > 0).map(|(&value, &count)| value * count).sum()
}