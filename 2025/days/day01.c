#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "days.h"

static char* part1(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    const int MAX = 100;
    int zero_count = 0;
    int position = 50;

    for (int i = 0; i < file->count; i++) {
        char* line = file->lines[i];
        if (!line || line[0] == '\0') {
            continue;
        }

        char dir = line[0];
        if (dir != 'L' && dir != 'R') {
            continue;
        }

        char* end = NULL;
        errno = 0;
        long value = strtol(line + 1, &end, 10);
        if (errno != 0 || end == (line + 1)) {
            continue;
        }

        int step = (int)(value % MAX);
        if (step == 0) {
            continue;
        }

        if (dir == 'L') {
            position = (position - step) % MAX;
            if (position < 0) position += MAX;
        } else {
            position = (position + step) % MAX;
        }

        if (position == 0) {
            zero_count++;
        }
    }

    char tmp[32];
    int n = snprintf(tmp, sizeof(tmp), "%d", zero_count);
    if (n < 0 || n >= (int)sizeof(tmp)) {
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = strdup(tmp);
    if (!result) {
        free_file_lines(file);
        return strdup("error: allocating output string");
    }

    free_file_lines(file);
    return result;
}

static char* part2(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    const int MAX = 100;
    int zero_count = 0;
    int position = 50;

    for (int i = 0; i < file->count; i++) {
        char* line = file->lines[i];
        if (!line || line[0] == '\0') {
            continue;
        }

        char dir = line[0];
        if (dir != 'L' && dir != 'R') {
            continue;
        }

        char* end = NULL;
        errno = 0;
        long value = strtol(line + 1, &end, 10);
        if (errno != 0 || end == (line + 1)) {
            continue;
        }

        int step = (int)(value % MAX);
        int full_rotations = (int)(value / MAX);
        zero_count += full_rotations;

        if (dir == 'L') {
            int new_position = (position - step) % MAX;
            if (new_position < 0) new_position += MAX;
            
            if (step > 0 && position > 0 && position <= step) {
                zero_count++;
            }
            
            position = new_position;
        } else {            
            int new_position = (position + step) % MAX;
            
            if (step > 0 && position + step >= MAX) {
                zero_count++;
            }
            
            position = new_position;
        }
    }

    char tmp[32];
    int n = snprintf(tmp, sizeof(tmp), "%d", zero_count);
    if (n < 0 || n >= (int)sizeof(tmp)) {
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = strdup(tmp);
    if (!result) {
        free_file_lines(file);
        return strdup("error: allocating output string");
    }

    free_file_lines(file);
    return result;
}

AOC_DAY(day01)
