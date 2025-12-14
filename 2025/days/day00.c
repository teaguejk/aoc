#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "days.h"

static char* part1(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    free_file_lines(file);
    return strdup("part not implemented");
}

static char* part2(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    free_file_lines(file);
    return strdup("part not implemented");
}

AOC_DAY(day00)
