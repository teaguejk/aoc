use crate::read_lines;

pub const INPUT: &str = "./inputs/02.txt";

type Input = Vec<String>;

pub fn parse(path: &str) -> Input {
    let lines = read_lines(path)
        .expect("error: could not read input file");

    lines.flatten().collect()
}

pub fn part1(input: &Input) -> i32 {
    input
        .into_iter()
        .map(|line| {
            let nums: Vec<i32> = line
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();
            is_report_safe(&nums)
        })
        .sum()
}

pub fn part2(input: &Input) -> i32 {
    input
        .into_iter()
        .map(|line| {
            let nums: Vec<i32> = line
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();
            is_report_safe2(&nums)
        })
        .sum()
}

fn is_report_safe(report: &Vec<i32>) -> i32 {
    let start_increasing = report[0] < report[1];

    // go through the list 2 at a time, the row safe if all return true
    let safe = report.windows(2).all(|window| {
        let (a, b) = (window[0], window[1]);
        let curr_increasing = a < b;
        
        if start_increasing != curr_increasing {
            return false;
        }

        if (a - b).abs() > 3 || a == b {
            return false;
        }

        true
    });

    if safe {
        return 1;
    }

    0
}

fn is_report_safe2(report: &Vec<i32>) -> i32 {
    if is_report_safe(&report) == 1 {
        return 1;
    }

    // brute force it
    for skip_idx in 0..report.len() {
        let subset: Vec<i32> = report
            .iter()
            .enumerate()
            .filter(|(i, _)| *i != skip_idx)
            .map(|(_, &n)| n)
            .collect();

        // return is_report_safe(&subset);
        if is_report_safe(&subset) == 1 {
            return 1;
        }
    }
    0
}