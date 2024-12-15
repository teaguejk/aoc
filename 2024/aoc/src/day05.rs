use std::fs::read_to_string;

pub const INPUT: &str = "./inputs/05.txt";

type Input = (Vec<(i32, i32)>, Vec<Vec<i32>>);

pub fn parse(path: &str) -> Input {

    let lines = read_to_string(path)
        .expect("error: could not read input file");
    
    let (rules, messages): (Vec<String>, Vec<String>) = lines.split_once("\n\n")
        .map(|(r, m)| (
            r.lines().map(String::from).collect(),
            m.lines().map(String::from).collect()
        ))
        .expect("to be loaded");

    let parsed_rules: Vec<(i32, i32)> = rules
        .iter()
        .map(|rule| {
            let (l, r) = rule.split_once("|").unwrap();
            (l.parse::<i32>().unwrap(), r.parse::<i32>().unwrap())
        })
        .collect();

    let parsed_messages: Vec<Vec<i32>> = messages
        .iter()
        .map(|message| {
            message.split(",").map(|n| n.parse::<i32>().unwrap()).collect()
        })
        .collect();
    
    (parsed_rules, parsed_messages)
}

pub fn part1(input: &Input) -> i32 {
    let rules = &input.0;
    let messages = &input.1;

    let mut valid = Vec::new();

    for message in messages {
        let mut pass = true;

        for (before, after) in rules {
            if let Some(before_index) = message.iter().position(|x| x == before) {
                if let Some(after_index) = message.iter().position(|x| x == after) {
                    if before_index > after_index {
                        pass = false;
                        break;
                    }
                }
            }
        }

        if pass {
            valid.push(message.clone());
        }
    }
    
    valid
        .iter()
        .map(|message| message[message.len() / 2] )
        .sum()
}

pub fn part2(input: &Input) -> i32 {
    0
}
