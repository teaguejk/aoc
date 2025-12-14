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
    
    int* joltages = NULL;
    size_t joltages_count = 0;
    size_t joltages_capacity = 0;

    for (size_t i = 0; i < file->count; i++) {
        char* line = file->lines[i];
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

        if (joltages_count >= joltages_capacity) {
            joltages_capacity = joltages_capacity == 0 ? 10 : joltages_capacity * 2;
            int* temp = realloc(joltages, sizeof(int) * joltages_capacity);
            if (temp == NULL) {
                free(joltages);
                free_file_lines(file);
                return strdup("error: could not allocate memory");
            }
            joltages = temp;
        }

        if (max_combination == -1) {
            continue;
        }

        joltages[joltages_count++] = max_combination;
    }

    int sum = 0;
    for (size_t i = 0; i < joltages_count; i++) {
        sum += joltages[i];
    }

    int n = snprintf(NULL, 0, "%d", sum);
    if (n < 0) {
        free(joltages);
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = malloc(n + 1);
    if (!result) {
        free(joltages);
        free_file_lines(file);
        return strdup("error: allocating output string");
    }
    snprintf(result, n + 1, "%d", sum);

    free(joltages);
    free_file_lines(file);

    return result;
}

static char* part2(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    int64_t* joltages = NULL;
    size_t joltages_count = 0;
    size_t joltages_capacity = 0;

    for (size_t i = 0; i < file->count; i++) {
        char* line = file->lines[i];
        if (!line || line[0] == '\0') {
            continue;
        }

        size_t len = strlen(line);
        int64_t max_combination = -1;

        for (size_t i = 0; i < len; i++) {
            int64_t first_digit = line[i] - '0';
            
            for (size_t j = i + 1; j < len; j++) {
                int64_t second_digit = line[j] - '0';

                int64_t combination = first_digit * 10 + second_digit;
                if (combination > max_combination) {
                    max_combination = combination;
                }
            }
        }

        if (joltages_count >= joltages_capacity) {
            joltages_capacity = joltages_capacity == 0 ? 10 : joltages_capacity * 2;
            int64_t* temp = realloc(joltages, sizeof(int64_t) * joltages_capacity);
            if (temp == NULL) {
                free(joltages);
                free_file_lines(file);
                return strdup("error: could not allocate memory");
            }
            joltages = temp;
        }

        if (max_combination == -1) {
            continue;
        }

        joltages[joltages_count++] = max_combination;
    }

    int64_t sum = 0;
    for (size_t i = 0; i < joltages_count; i++) {
        sum += joltages[i];
    }

    int n = snprintf(NULL, 0, "%" PRId64, sum);
    if (n < 0) {
        free(joltages);
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = malloc(n + 1);
    if (!result) {
        free(joltages);
        free_file_lines(file);
        return strdup("error: allocating output string");
    }
    snprintf(result, n + 1, "%" PRId64, sum);

    free(joltages);
    free_file_lines(file);

    return result; 
}

AOC_DAY(day03)
