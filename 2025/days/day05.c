#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "days.h"

typedef struct {
    int64_t start;
    int64_t end;
} Range;

static size_t get_input_separator(InputFile* file);
static int is_in_any_range(int64_t id, Range* ranges, size_t range_count);

static char* part1(const char* input_path) {
    InputFile* file = read_file_lines(input_path);
    if (!file) {
        return strdup("error: reading file");
    }

    int sum = 0;

    size_t separator = get_input_separator(file);
    
    Range* ranges = malloc(separator * sizeof(Range));
    if (!ranges) {
        free_file_lines(file);
        return strdup("error: allocating ranges");
    }
    
    for (size_t range_idx = 0; range_idx < separator; range_idx++) {
        char* line_copy = strdup(file->lines[range_idx]);
        char* start_str = strtok(line_copy, DASH);      
        char* end_str = strtok(NULL, DASH);

        ranges[range_idx].start = atoll(start_str);
        ranges[range_idx].end = atoll(end_str);
        
        free(line_copy);
    }

    for (size_t id_idx = separator+1; id_idx < file->count; id_idx++) {
        int64_t id = atoll(file->lines[id_idx]);
        if (is_in_any_range(id, ranges, separator)) {
            sum++;
        }
    }

    int n = snprintf(NULL, 0, "%d", sum);
    if (n < 0) {
        free(ranges);
        free_file_lines(file);
        return strdup("error: formatting output");
    }

    char* result = malloc(n + 1);
    if (!result) {
        free(ranges);
        free_file_lines(file);
        return strdup("error: allocating output string");
    }
    snprintf(result, n + 1, "%d", sum);

    free(ranges);
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

static size_t get_input_separator(InputFile* file) {
    for (size_t line_idx = 0; line_idx < file->count; line_idx++) {
        if (strlen(file->lines[line_idx]) > 1) continue;
        
        return line_idx;
    }

    return file->count;
}

static int is_in_any_range(int64_t id, Range* ranges, size_t range_count) {
    for (size_t i = 0; i < range_count; i++) {
        if (id >= ranges[i].start && id <= ranges[i].end) {
            return 1;
        }
    }
    return 0;
}

AOC_DAY(day05)
