#include "disp.h"
#include <stdio.h>

// Copyright 2019-2023 Kai D. Gonzalez
void
print_grid (xygrid *s)
{
    for (int y = 0 ; y < GRID_BOUND; ++ y) {
        for (int x = 0; x < GRID_BOUND; ++ x) {
            printf("%i ", s->_space[y][x]);
        }
        printf("\n");
    }
}
