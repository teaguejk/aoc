#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "days.h"

static char* part1(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    if (file->count != 1) {
        free_file_lines(file);
        return strdup("error: expected only one line");
    }

    const char* COMMA = ",";
    const char* DASH = "-";

    char* line = strdup(file->lines[0]);

    char* block_saveptr = NULL;
    char* block = strtok_r(line, COMMA, &block_saveptr);

    while (block != NULL) {
        char* range = strdup(block);

        char* range_saveptr = NULL;
        char* start = strtok_r(range, DASH, &range_saveptr);
        char* end = strtok_r(NULL, DASH, &range_saveptr); 

        printf("%s -- %s -- %s\n", block, start, end);
        
        free(range);
        block = strtok_r(NULL, COMMA, &block_saveptr);
    }

    free(line);
    free_file_lines(file);

    return strdup("part not implemented");
}

static char* part2(const char* input_path) {
      (void)input_path;
    return strdup("part not implemented");
}

AOC_DAY(day02)
