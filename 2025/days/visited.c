#include "visited.h"
#include <stdlib.h>

static int visit_counts[1000000] = {0}; // 1000 * 1000

static int encode(int x, int y) {
    return x * 1000 + y;
}

int check_visited(int x, int y) {
    if (x < 0 || y < 0 || x >= 1000 || y >= 1000) return 0;
    return visit_counts[encode(x, y)] > 0 ? 1 : 0;
}

void mark_visited(int x, int y) {
    if (x < 0 || y < 0 || x >= 1000 || y >= 1000) return;
    visit_counts[encode(x, y)]++;
}