#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "days.h"

static char* part1(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    int sum = 0;

    for (size_t line_idx = 0; line_idx < file->count; line_idx++) {
        char* line = file->lines[line_idx];
        if (!line || line[0] == '\0') {
            continue;
        }

        size_t len = strlen(line);
        int max_combination = -1;

        for (size_t i = 0; i < len; i++) {
            int first_digit = line[i] - '0';

            for (size_t j = i + 1; j < len; j++) {
                int second_digit = line[j] - '0';

                int combination = first_digit * 10 + second_digit;
                if (combination > max_combination) {
                    max_combination = combination;
                }
            }
        }

        if (max_combination != -1) {
            sum += max_combination;
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

    int64_t sum = 0;

    for (size_t line_idx = 0; line_idx < file->count; line_idx++) {
        char* line = file->lines[line_idx];
        if (!line || line[0] == '\0') {
            continue;
        }

        size_t len = strlen(line);
        size_t to_remove = (len > 12) ? (len - 12) : 0;

        char stack_buf[256];
        size_t stack_len = 0;

        for (size_t char_idx = 0; char_idx < len; char_idx++) {
            char d = line[char_idx];
            while (to_remove > 0 && stack_len > 0 && stack_buf[stack_len - 1] < d) {
                stack_len--;
                to_remove--;
            }
            stack_buf[stack_len++] = d;
        }

        if (to_remove > 0 && stack_len > to_remove) {
            stack_len -= to_remove;
            to_remove = 0;
        }

        char selected[13] = {0};
        int selected_count = 0;
        for (size_t j = 0; j < stack_len && selected_count < 12; j++) {
            selected[selected_count++] = stack_buf[j];
        }

        if (selected_count == 12) {
            int64_t joltage = atoll(selected);
            sum += joltage;
        }
    }

    int n = snprintf(NULL, 0, "%" PRId64, sum);
    if (n < 0) {
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = malloc(n + 1);
    if (!result) {
        free_file_lines(file);
        return strdup("error: allocating output string");
    }
    snprintf(result, n + 1, "%" PRId64, sum);

    free_file_lines(file);

    return result; 
}

AOC_DAY(day03)
