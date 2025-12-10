#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char** lines;
    int count;
} InputFile;

InputFile* read_file_lines(const char* file_path);
void free_file_lines(InputFile* file_lines);

#endif
