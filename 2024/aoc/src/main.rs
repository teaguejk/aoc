use std::time::Instant;

mod day01;
mod day02;
mod day03;
mod day04;

fn main() {
    let day1 = || {
        use day01::*;

        let input = parse(INPUT);
        let part1 = part1(&input);
        let part2 = part2(&input);

        (part1.to_string(), part2.to_string())
    };
    let now = Instant::now();
    println!("day 1: {:?}", day1());
    let elapsed = now.elapsed();
    println!("took: {:.2?}", elapsed);

    let day2 = || {
        use day02::*;

        let input = parse(INPUT);
        let part1 = part1(&input);
        let part2 = part2(&input);

        (part1.to_string(), part2.to_string())
    };
    let now = Instant::now();
    println!("day 2: {:?}", day2());
    let elapsed = now.elapsed();
    println!("took: {:.2?}", elapsed);

    let day3 = || {
        use day03::*;

        let input = parse(INPUT);
        let part1 = part1(&input);
        let part2 = part2(&input);

        (part1.to_string(), part2.to_string())
    };
    let now = Instant::now();
    println!("day 3: {:?}", day3());
    let elapsed = now.elapsed();
    println!("took: {:.2?}", elapsed);

    let day4 = || {
        use day04::*;

        let input = parse(INPUT);
        let part1 = part1(&input);
        let part2 = part2(&input);

        (part1.to_string(), part2.to_string())
    };

    let now = Instant::now();
    println!("day 4: {:?}", day4());
    let elapsed = now.elapsed();
    println!("took: {:.2?}", elapsed);

    // timing
    // let now = Instant::now();
    // let elapsed = now.elapsed();
    // println!("took: {:.2?}", elapsed);
} 
