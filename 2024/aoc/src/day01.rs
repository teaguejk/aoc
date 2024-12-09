use crate::read_lines;
use std::collections::HashMap;

pub const INPUT: &str = "./inputs/01.txt";

type Input = (Vec<i32>, Vec<i32>);

pub fn parse(path: &str) -> Input {
    let mut left: Vec<i32> = Vec::new();
    let mut right: Vec<i32> = Vec::new();

    let lines = read_lines(path)
        .expect("error: could not read input file");

    for line in lines.flatten() {
        let nums: Vec<i32> = line
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
                            
        left.push(nums[0]);
        right.push(nums[1]);
    }
    
    (left, right)
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