#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aoc.h"

#define DAYS_TABLE \
    DAY_ENTRY(1, day01) \
    DAY_ENTRY(2, day02)

#define DAY_ENTRY(num, name) \
    extern char* name##_part1(const char* input_path); \
    extern char* name##_part2(const char* input_path);
DAYS_TABLE
#undef DAY_ENTRY

Day days[] = {
#define DAY_ENTRY(num, name) (Day){num, name##_part1, name##_part2},
DAYS_TABLE
#undef DAY_ENTRY
    (Day){0, NULL, NULL}
};

static double elapsed_ms(struct timespec a, struct timespec b) {
    return (b.tv_sec - a.tv_sec) * 1000.0 + (b.tv_nsec - a.tv_nsec) / 1e6;
}

static void run_part(int day_number, int part_number, Solution fn) {
    if (!fn) {
        printf("day %d part %d: no solution\n", day_number, part_number);
        return;
    }

    char input_path[64];
    snprintf(input_path, sizeof(input_path), "inputs/%02d.txt", day_number);

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    char *result = fn(input_path);
    clock_gettime(CLOCK_MONOTONIC, &t1);

    printf("day %d: part %d -> took: %.2f ms -> %s\n",
        day_number, part_number, elapsed_ms(t0, t1), result ? result : "(null)");

    free(result);
}

static void run_all(void) {
    for (int i = 0; days[i].number != 0; i++) {
        run_part(days[i].number, 1, days[i].part1);
        run_part(days[i].number, 2, days[i].part2);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "usage:\n  %s all\n  %s <day_number> <part_number>\n", argv[0], argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "all") == 0) {
        run_all();
        return 0;
    }

    int day = atoi(argv[1]);
    if (day < 1 || day > 12) {
        fprintf(stderr, "error: invalid day (1-12)\n");
        return 1;
    }

    int part = 0;
    if (argc == 3) {
        part = atoi(argv[2]);
        if (part != 1 && part != 2) {
            fprintf(stderr, "error: invalid part (1 or 2)\n");
            return 1;
        }
    }

    Solution fn1 = NULL, fn2 = NULL;
    for (int i = 0; days[i].number != 0; i++) {
        if (days[i].number == day) {
            fn1 = days[i].part1;
            fn2 = days[i].part2;
            break;
        }
    }

    if (part == 0) {
        run_part(day, 1, fn1);
        run_part(day, 2, fn2);
    } else {
        run_part(day, part, (part == 1) ? fn1 : fn2);
    }

    return 0;
}
