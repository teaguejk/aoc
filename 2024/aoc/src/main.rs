use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

mod day01;


fn main() {
    use day01::*;

    let (left, right) = parse(INPUT_01);

    let res1a = day1a(&left, &right);
    let res1b = day1b(&left, &right);

    println!("{}", res1a);
    println!("{}", res1b);
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
