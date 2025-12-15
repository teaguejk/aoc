#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "days.h"

#define COMMA ","
#define DASH "-"

static char* part1(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    if (file->count != 1) {
        free_file_lines(file);
        return strdup("error: expected only one line");
    }

    int64_t sum = 0;

    char* line = strdup(file->lines[0]);

    char* block_saveptr = NULL;
    char* block = strtok_r(line, COMMA, &block_saveptr);

    while (block != NULL) {
        char* range = strdup(block);

        char* range_saveptr = NULL;
        char* startStr = strtok_r(range, DASH, &range_saveptr);
        char* endStr = strtok_r(NULL, DASH, &range_saveptr); 

        int64_t start = strtoll(startStr, NULL, 10);
        int64_t end = strtoll(endStr, NULL, 10);

        for (int64_t i = start; i <= end; i++) {
            int len = snprintf(NULL, 0, "%" PRId64, i);

            if (len % 2 != 0) {
                continue;
            }

            int middle = len / 2;
            
            char* numStr = (char*)malloc(sizeof(char) * (len + 1));
            if (numStr == NULL) {
                return strdup("error: could not allocate memory");
            }

            snprintf(numStr, len + 1, "%" PRId64, i);
            
            char* p1 = (char*)malloc(sizeof(char) * (middle + 1));
            if (p1 == NULL) {
                free(numStr);
                return strdup("error: could not allocate memory");
            }

            strncpy(p1, numStr, middle);
            p1[middle] = '\0';

            char* p2 = (char*)malloc(sizeof(char) * (len - middle + 1));
            if (p2 == NULL) {
                free(p1);
                free(numStr);
                return strdup("error: could not allocate memory");
            }

            strncpy(p2, numStr + middle, len - middle);
            p2[len - middle] = '\0';

            int result = strcmp(p1, p2);
            if (result == 0) {
                sum += i;
            }

            free(p1);
            free(p2);
            free(numStr);
        }

        free(range);
        block = strtok_r(NULL, COMMA, &block_saveptr);
    }

    int n = snprintf(NULL, 0, "%" PRId64, sum);
    if (n < 0) {
        free(line);
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = malloc(n + 1);
    if (!result) {
        free(line);
        free_file_lines(file);
        return strdup("error: allocating output string");
    }
    snprintf(result, n + 1, "%" PRId64, sum);

    free(line);
    free_file_lines(file);

    return result;
}

static char* part2(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    if (file->count != 1) {
        free_file_lines(file);
        return strdup("error: expected only one line");
    }

    int64_t sum = 0;

    char* line = strdup(file->lines[0]);

    char* block_saveptr = NULL;
    char* block = strtok_r(line, COMMA, &block_saveptr);

    while (block != NULL) {
        char* range = strdup(block);

        char* range_saveptr = NULL;
        char* startStr = strtok_r(range, DASH, &range_saveptr);
        char* endStr = strtok_r(NULL, DASH, &range_saveptr); 

        int64_t start = strtoll(startStr, NULL, 10);
        int64_t end = strtoll(endStr, NULL, 10);

        for (int64_t i = start; i <= end; i++) {
            int len = snprintf(NULL, 0, "%" PRId64, i);

            char* numStr = (char*)malloc(sizeof(char) * (len + 1));
            if (numStr == NULL) {
                return strdup("error: could not allocate memory");
            }

            snprintf(numStr, len + 1, "%" PRId64, i);

            int has_repeat = 0;
            for (int segment_len = 1; segment_len <= len / 2; segment_len++) {
                if (len % segment_len != 0) {
                    continue;
                }
                
                int is_repeating = 1;
                for (int pos = segment_len; pos < len; pos++) {
                    if (numStr[pos] != numStr[pos % segment_len]) {
                        is_repeating = 0;
                        break;
                    }
                }
                
                if (is_repeating) {
                    has_repeat = 1;
                    break;
                }
            }

            if (has_repeat) {
                sum += i;
            }

            free(numStr);
        }

        free(range);
        block = strtok_r(NULL, COMMA, &block_saveptr);
    }

    int n = snprintf(NULL, 0, "%" PRId64, sum);
    if (n < 0) {
        free(line);
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = malloc(n + 1);
    if (!result) {
        free(line);
        free_file_lines(file);
        return strdup("error: allocating output string");
    }
    snprintf(result, n + 1, "%" PRId64, sum);

    free(line);
    free_file_lines(file);

    return result;
}

AOC_DAY(day02)
