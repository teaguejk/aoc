use std::collections::HashSet;
use std::fs::read_to_string;

pub const GUARD: char = '^';
pub const OBSTACLE: char = '#';

pub const INPUT: &str = "./inputs/06.txt";

type Input = Vec<Vec<char>>;

pub fn parse(path: &str) -> Input {
    read_to_string(path)
        .expect("error: could not read input file")
        .lines()
        .map(|line| line.chars().collect::<Vec<char>>())
        .collect()
}

pub fn part1(input: &Input) -> i32 {
    let rows = input.len();
    let cols = input[0].len();
    
    let guard = find_guard(input);
    let (mut x, mut y) = guard.expect("guard to be found");
    
    let mut visited = HashSet::new();
    let mut dir = 0;

    let directions: [(isize, isize); 4] = [(-1, 0), (0, 1), (1, 0), (0, -1)];

    loop {
        visited.insert((x, y));
        
        let (dx, dy) = directions[dir];
        let new_x = x as isize + dx;
        let new_y = y as isize + dy;
        
        if new_x < 0 || new_x >= rows as isize || new_y < 0 || new_y >= cols as isize {
            break;
        }
        
        let new_x = new_x as usize;
        let new_y = new_y as usize;
        
        if input[new_x][new_y] == OBSTACLE {
            dir = (dir + 1) % 4;
        } else {
            x = new_x;
            y = new_y;
        }
    }
    
    visited.len() as i32
}

pub fn part2(_input: &Input) -> i32 {
    0
}

pub fn find_guard(input: &Input) -> Option<(usize, usize)> {
    for (x, row) in input.iter().enumerate() {
        if let Some(y) = row.iter().position(|&c| c == GUARD) {
            return Some((x, y));
        }
    }

    None
}
