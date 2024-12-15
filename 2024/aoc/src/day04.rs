use std::fs::read_to_string;

pub const INPUT: &str = "./inputs/04.txt";

pub const XMAS: &str = "XMAS";
pub const SAMX: &str = "SAMX";

type Input = Vec<String>;

pub fn parse(path: &str) -> Input {
    read_to_string(path)
    .expect("error: could not read input file")
    .lines()
    .map(|line| line.chars().collect())
    .collect()
}

pub fn part1(input: &Input) -> i32 {
    let mut count = 0;
    
    let height = input.len();
    let width = input[0].len();
    
    // horizontal
    // for each line, check the each 4 character substring for the target or its reverse
    for line in input {
        for i in 0..(line.len() - 3) {
            let curr = &line[i..(i + 4)];
            
            if curr == XMAS || curr == SAMX {
                count += 1;
            }
        }
    }
    
    // other directions
    // for each letter, check the 4 character substring in each direction
    for line in 0..(height - 3) {
        // vertical
        for col in 0..width {
            if check_substring_for_xmas(input, line, col, 1, 0) {
                count += 1;
            }
        }
        
        // down right
        for col in 0..(width - 3) {
            if check_substring_for_xmas(input, line, col, 1, 1) {
                count += 1;
            }
        }
        
        // down left
        for col in 3..width {
            if check_substring_for_xmas(input, line, col, 1, -1) {
                count += 1;
            }
        }
    }
    
    count
}


pub fn part2(input: &Input) -> i32 {
    let mut count = 0;
    
    let height = input.len();
    let width = input[0].len();
    
    for line in 1..(height - 1) {
        for col in 1..(width - 1) {
            let letter = input[line].chars().nth(col).unwrap();
            
            if letter != 'A' {
                continue;
            }
            
            let left_diag = (
                input[line - 1].chars().nth(col - 1).unwrap(),
                input[line + 1].chars().nth(col + 1).unwrap(),
            );
            
            let right_diag = (
                input[line - 1].chars().nth(col + 1).unwrap(),
                input[line + 1].chars().nth(col - 1).unwrap(),
            );
            
            // each diag have one of each 'M' and 'S'
            if  (left_diag == ('M', 'S') || left_diag == ('S', 'M')) &&
            (right_diag == ('M', 'S') || right_diag == ('S', 'M')) {
                count += 1;
            }
        }
    }
    
    count
}

fn check_substring_for_xmas(input: &Input, start_row: usize, start_col: usize, row_step: isize, col_step: isize) -> bool {
    let substring: String = (0..4)
        .map(|i| {
            let row = (start_row as isize + i * row_step) as usize;
            let col = (start_col as isize + i * col_step) as usize;
            input[row].chars().nth(col).unwrap()
        })
        .collect();

    substring == XMAS || substring == SAMX
}
