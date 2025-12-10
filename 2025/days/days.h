#ifndef DAYS_H
#define DAYS_H

#include "utils.h"

#define AOC_DAY(day) \
    char* day##_part1(const char* input_path) { return part1(input_path); } \
    char* day##_part2(const char* input_path) { return part2(input_path); }

#endif
