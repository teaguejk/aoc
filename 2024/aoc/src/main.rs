use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

mod day01;

fn main() {
    let day1 = || {
        use day01::*;

        let input = parse(INPUT_01);
        let part1 = day1a(&input);
        let part2 = day1b(&input);

        (part1.to_string(), part2.to_string())
    };
    println!("day 1: {:?}", day1());

}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

