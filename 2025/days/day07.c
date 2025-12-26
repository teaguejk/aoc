#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "days.h"

static char* part1(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    int sum = 0;

    for (size_t line_idx = 0; line_idx < file->count; line_idx++) {
        char* line = strdup(file->lines[line_idx]);
        if (!line || line[0] == '\0') {
            continue;
        }

        free(line);
    }

    int n = snprintf(NULL, 0, "%d", sum);
    if (n < 0) {
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = malloc(n + 1);
    if (!result) {
        free_file_lines(file);
        return strdup("error: allocating output string");
    }
    snprintf(result, n + 1, "%d", sum);

    free_file_lines(file);
    
    return result;
}

static char* part2(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    int sum = 0;

    for (size_t line_idx = 0; line_idx < file->count; line_idx++) {
        char* line = strdup(file->lines[line_idx]);
        if (!line || line[0] == '\0') {
            continue;
        }

        free(line);
    }

    int n = snprintf(NULL, 0, "%d", sum);
    if (n < 0) {
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = malloc(n + 1);
    if (!result) {
        free_file_lines(file);
        return strdup("error: allocating output string");
    }
    snprintf(result, n + 1, "%d", sum);

    free_file_lines(file);
    
    return result;
}

AOC_DAY(day07)
