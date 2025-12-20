#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "days.h"

#define PAPER '@'

typedef struct {
    int x;
    int y;
} Coordinate;

static char* part1(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    Coordinate  directions[] = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Up-Left
        {-1, 1},  // Up-Right
        {1, -1},  // Down-Left
        {1, 1}    // Down-Right
    };

    int sum = 0;

    for (size_t line_idx = 0; line_idx < file->count; line_idx++) {
        char* line = file->lines[line_idx];
        if (!line || line[0] == '\0') {
            continue;
        }

        size_t len = strlen(line);

        for (size_t char_idx = 0; char_idx < len; char_idx++) {
            char pos = line[char_idx]; 

            if (pos != PAPER) {
                continue;
            }

            int paper_count = 0;

            for (size_t dir_idx = 0; dir_idx < sizeof(directions) / sizeof(directions[0]); dir_idx++) {
                Coordinate dir = directions[dir_idx];

                int ny = (int)line_idx + dir.y;
                int nx = (int)char_idx + dir.x;

                // prevent oob on file lines
                if (ny < 0 || ny >= (int)file->count) {
                    continue;
                }

                char *nline = file->lines[ny];
                if (!nline) {
                    continue;
                }

                size_t nlen = strlen(nline);

                // prevent oob on line characters
                if (nx < 0 || (size_t)nx >= nlen) {
                    continue;
                }

                if (nline[nx] == PAPER) {
                    paper_count++;
                }
            }

            if (paper_count < 4) {
                sum ++;
            }
        }
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

    free_file_lines(file);
    return strdup("part not implemented");
}

AOC_DAY(day04)
