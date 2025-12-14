#include "utils.h"
#include <string.h>

InputFile* read_file_lines(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (!file) {
        return NULL;
    }

    InputFile* result = malloc(sizeof(InputFile));
    if (!result) {
        fclose(file);
        return NULL;
    }
    
    result->lines = NULL;
    result->count = 0;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    size_t capacity = 16;
    result->lines = malloc(capacity * sizeof(char*));
    if (!result->lines) {
        free(result);
        fclose(file);
        return NULL;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[read - 1] = '\0';
            read--;
        }

        if (result->count >= capacity) {
            capacity *= 2;
            char** new_lines = realloc(result->lines, capacity * sizeof(char*));
            if (!new_lines) {
                free(line);
                free_file_lines(result);
                fclose(file);
                return NULL;
            }
            result->lines = new_lines;
        }

        result->lines[result->count] = strdup(line);
        if (!result->lines[result->count]) {
            free(line);
            free_file_lines(result);
            fclose(file);
            return NULL;
        }
        result->count++;
    }

    free(line);
    fclose(file);
    return result;
}

void free_file_lines(InputFile* file_lines) {
    if (!file_lines) return;
    
    for (size_t i = 0; i < file_lines->count; i++) {
        free(file_lines->lines[i]);
    }
    
    free(file_lines->lines);
    free(file_lines);
}
