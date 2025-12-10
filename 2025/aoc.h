#ifndef AOC_H
#define AOC_H

typedef char* (*Solution)(const char* input_path);

typedef struct {
    int number;
    Solution part1;
    Solution part2;
} Day;

#endif
