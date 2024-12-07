use crate::read_lines;
use std::collections::HashMap;

pub const INPUT_01: &str = "./inputs/01.txt";

pub fn parse(path: &str) -> (Vec<i32>, Vec<i32>) {
    let mut left: Vec<i32> = Vec::new();
    let mut right: Vec<i32> = Vec::new();

    if let Ok(lines) = read_lines(path) {
        let vec_lines: Vec<String> = lines
                .flatten()
                .collect();

        for line in vec_lines {
            let nums: Vec<i32> = line
                                .split("   ")
                                .map(|x| x.parse().unwrap())
                                .collect();
            
            left.push(nums[0]);
            right.push(nums[1]);
        }
    }
    
    (left, right)
}

pub fn day1a(left: &Vec<i32>, right: &Vec<i32>) -> i32 {
    let mut left = left.clone();
    let mut right = right.clone();

    left.sort();
    right.sort();

    left.iter().zip(right.iter()).map(|(l, r)| (l - r).abs()).sum()
}

pub fn day1b(left: &Vec<i32>, right: &Vec<i32>) -> i32 {
    let mut similarities: HashMap<i32, i32> = HashMap::new();

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