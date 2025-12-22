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

    int64_t sum = 0;

    // need to tokenize rather than index directly
    char* first_line_copy = strdup(file->lines[0]);
    size_t cols = 0;

    char* token = strtok(first_line_copy, SPACE);
    while (token != NULL) {
        cols++;
        token = strtok(NULL, SPACE);
    }
    free(first_line_copy);

    for (size_t col_idx = 0; col_idx < cols; col_idx++) {
        int64_t answer = 0;

        char* op_line_copy = strdup(file->lines[file->count - 1]);
        char* op_token = strtok(op_line_copy, SPACE);
        for (size_t i = 0; i < col_idx; i++) {
            op_token = strtok(NULL, SPACE);
        }

        char op = op_token[0];
        free(op_line_copy);

        for (size_t row_idx = 0; row_idx < file->count - 1; row_idx++) {
            char* num_line_copy = strdup(file->lines[row_idx]);

            char* num_str = strtok(num_line_copy, SPACE);

            for (size_t i = 0; i < col_idx; i++) {
                num_str = strtok(NULL, SPACE);
            }

            int64_t num = atoll(num_str);    

            if (row_idx == 0) {
                answer += num;
                continue;
            }
            
            switch (op) {
                case STAR:
                    answer *= num;
                    break;
                case PLUS:
                    answer += num;
                    break;
            }

            free(num_line_copy);
        }

        sum += answer;
    }

    int64_t n = snprintf(NULL, 0, "%" PRId64, sum);
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

static char* part2(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    free_file_lines(file);
    return strdup("part not implemented");
}

AOC_DAY(day06)
