use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
// use std::time::Instant;

mod day01;
mod day02;

fn main() {
    let day1 = || {
        use day01::*;

        let input = parse(INPUT);
        let part1 = part1(&input);
        let part2 = part2(&input);

        (part1.to_string(), part2.to_string())
    };
    println!("day 1: {:?}", day1());

    let day2 = || {
        use day02::*;

        let input = parse(INPUT);
        
        let part1 = part1(&input);
        let part2 = part2(&input);

        (part1.to_string(), part2.to_string())
    };
    println!("day 2: {:?}", day2());

    // timing
    // let now = Instant::now();
    // let elapsed = now.elapsed();
    // println!("took: {:.2?}", elapsed);
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

