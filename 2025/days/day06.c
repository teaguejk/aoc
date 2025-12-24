#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include "days.h"

#define MAX_COLUMNS 1000
#define MAX_ROWS 5
#define MAX_DIGIT_WIDTH 4
#define MAX_DIGIT_POSITIONS 4

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
        char* op_line_copy = strdup(file->lines[file->count - 1]);
        char* op_token = strtok(op_line_copy, SPACE);
        for (size_t i = 0; i < col_idx; i++) {
            op_token = strtok(NULL, SPACE);
        }
        
        char op = op_token[0];
        free(op_line_copy);
        
        int64_t answer = op == PLUS ? 0 : 1;

        for (size_t row_idx = 0; row_idx < file->count - 1; row_idx++) {
            char* num_line_copy = strdup(file->lines[row_idx]);

            char* num_str = strtok(num_line_copy, SPACE);

            for (size_t i = 0; i < col_idx; i++) {
                num_str = strtok(NULL, SPACE);
            }

            int64_t num = atoll(num_str);    
            
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

    int64_t sum = 0;

    // count columns using tokens
    char* first_line_copy = strdup(file->lines[0]);
    size_t cols = 0;

    char* token = strtok(first_line_copy, SPACE);
    while (token != NULL) {
        cols++;
        token = strtok(NULL, SPACE);
    }
    free(first_line_copy);

    // calculate all column widths based on largest numbers
    int col_widths[MAX_COLUMNS] = {0};
    
    for (size_t row_idx = 0; row_idx < file->count - 1; row_idx++) {
        char* line_copy = strdup(file->lines[row_idx]);
        char* num_token = strtok(line_copy, SPACE);
        int current_col = 0;
        
        while (num_token != NULL && current_col < (int)cols) {
            int len = strlen(num_token);
            if (len > col_widths[current_col]) {
                col_widths[current_col] = len > MAX_DIGIT_WIDTH ? MAX_DIGIT_WIDTH : len;
            }
            current_col++;
            num_token = strtok(NULL, SPACE);
        }
        
        free(line_copy);
    }

    // calculate column start positions
    int col_positions[MAX_COLUMNS];
    col_positions[0] = 0;
    for (int i = 1; i < (int)cols; i++) {
        col_positions[i] = col_positions[i-1] + col_widths[i-1] + 1;
    }

    // process each column right-to-left
    for (int col_idx = cols - 1; col_idx >= 0; col_idx--) {
        // get op for the column
        char* op_line_copy = strdup(file->lines[file->count - 1]);
        char* op_token = strtok(op_line_copy, SPACE);
        for (int i = 0; i < col_idx; i++) {
            op_token = strtok(NULL, SPACE);
        }
        char op = op_token[0];
        free(op_line_copy);

        // get column data based on fixed positions and widths
        char col_data[MAX_DIGIT_POSITIONS][MAX_DIGIT_WIDTH + 1];
        int row_count = 0;
        
        for (size_t row_idx = 0; row_idx < file->count - 1; row_idx++) {
            const char* line = file->lines[row_idx];
            int start_pos = col_positions[col_idx];
            int width = col_widths[col_idx];
            
            if (start_pos < (int)strlen(line)) {
                int actual_width = width;
                if (start_pos + width > (int)strlen(line)) {
                    actual_width = strlen(line) - start_pos;
                }
                
                strncpy(col_data[row_count], &line[start_pos], actual_width);
                col_data[row_count][actual_width] = '\0';
                row_count++;
            }
        }

        // make the vertical numbers by reading each character position
        char vertical_numbers[MAX_DIGIT_POSITIONS][MAX_DIGIT_WIDTH + 1] = {{0}};

        for (int num_idx = 0; num_idx < col_widths[col_idx]; num_idx++) {
            for (int row = 0; row < row_count; row++) {
                if (num_idx < (int)strlen(col_data[row]) && col_data[row][num_idx] != ' ') {
                    char digit = col_data[row][num_idx];
                    size_t curr_len = strlen(vertical_numbers[num_idx]);
                    vertical_numbers[num_idx][curr_len] = digit;
                    vertical_numbers[num_idx][curr_len + 1] = '\0';
                }
            }
        }

        // do the math right-to-left
        int64_t result = op == PLUS ? 0 : 1;
        
        for (int i = col_widths[col_idx] - 1; i >= 0; i--) {
            if (strlen(vertical_numbers[i]) > 0) {
                int64_t num = atoll(vertical_numbers[i]);
                
                switch (op) {
                    case STAR:
                        result *= num;
                        break;
                    case PLUS:
                        result += num;
                        break;
                }
            }
        }
        
        sum += result;
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

AOC_DAY(day06)
