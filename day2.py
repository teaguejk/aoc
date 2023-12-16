# AOC Day 2
# Jaracah Teague

####################################################################################################
# Part 1

# result scores
# win = 6
# tie = 3
# loss = 0

# move scores
# rock = 1
# paper = 2
# scissors = 3

# move mappings
# A = X = rock
# B = Y = paper
# C = Z = scissors

# win conditions
# rock > scissors
# paper > rock
# scissors > paper

win_score = 6
tie_score = 3
total_score = 0

move_score = {
    "X":1,
    "Y":2,
    "Z":3
}

move_map = {
    "A":"X", # rock
    "B":"Y", # paper
    "C":"Z"  # scissors
}

win_conditions = {
    "A":"Y", # rock < paper,
    "B":"Z", # paper < scissors,
    "C":"X"  # scissors < rock
}

loss_conditions = {
    "A":"Z", # rock > scissors
    "B":"X", # paper > rock
    "C":"Y"  # scissors > paper
}

games = []

# open file
with open('inputs/day2.txt', 'r') as file:
    for game in file.readlines():
        games.append(game)

# compute scores for each game
for game in games:
    elf_move = game[0]
    my_move = game[2] 

    if win_conditions[elf_move] == my_move: # win
        total_score = total_score + win_score + move_score[my_move]
    elif my_move == move_map[elf_move]: # tie
        total_score = total_score + tie_score + move_score[my_move]
    else: # loss
        total_score = total_score + move_score[my_move]

# done with part 1
print(f'[PART 1]: {total_score}')

####################################################################################################
# Part 2

# X = lose
# Y = tie
# Z = win

total_score = 0

# compute scores for each game
for game in games:
    elf_move = game[0]
    outcome = game[2]

    if outcome == 'X': # loss
        my_move = loss_conditions[elf_move]
        total_score = total_score + move_score[my_move]

    elif outcome == 'Y': # tie
        my_move = move_map[elf_move]
        total_score = total_score + tie_score + move_score[my_move]

    else: # win
        my_move = win_conditions[elf_move]
        total_score = total_score + win_score + move_score[my_move]

# done with part 2
print(f'[PART 2]: {total_score}')
