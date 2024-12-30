use std::time::Instant;

mod day01;
mod day02;
mod day03;
mod day04;
mod day05;

macro_rules! run_day {
    ($day:ident) => {
        (
            stringify!($day), || {
                use $day::*;
                let input = parse(INPUT);
                let part1 = part1(&input);
                let part2 = part2(&input);
                (part1.to_string(), part2.to_string())
            },
        )
    };
}

fn main() {
    let days: Vec<(&str, fn() -> (String, String))> = vec![
        run_day!(day01),
        run_day!(day02),
        run_day!(day03),
        run_day!(day04),
        run_day!(day05),
    ];

    for (day, run) in days {
        let now = Instant::now();
        let res = run();
        let took = now.elapsed();
        println!("{:<6}: took {:<10.2?} -> {:?}", day, took, res);
    }
}
