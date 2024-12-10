
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
