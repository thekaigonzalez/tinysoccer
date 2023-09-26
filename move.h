// Copyright 2019-2023 Kai D. Gonzalez

#include "grid.h"

// move coordinates from one spot to another (set a->x and a->y to b->x and
// b->y)
void cset (coordinates *a, coordinates *b); /* simply set coordinates a to b*/

// using cset, set a point on a grid to another
void
move (xygrid *g, coordinates *o, coordinates *n);

/* if the space to move is 1, move, otherwise do nothing */
void move1(xygrid *s, coordinates * o, coordinates * n);

/* to clamp movement to 1 */
void move1clamp(xygrid *s, coordinates *o, coordinates *n);
