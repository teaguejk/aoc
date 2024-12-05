# AOC Day 1
# Jaracah Teague

####################################################################################################
# Part 1

list = []
sum = 0
elf = 0

with open('./inputs/day1.txt', 'r') as file:
    for line in file.readlines():

        if line != '\n':
            sum = sum + int(line)
        else:
            list.append(sum)
            sum = 0

max_1 = max(list)
print(f"[PART 1]: {max_1}")

####################################################################################################
# Part 2

list.remove(max_1)
max_2 = max(list)

list.remove(max_2)
max_3 = max(list)

sum_top_three = max_1 + max_2 + max_3
print(f'[PART 2]: {sum_top_three}')
