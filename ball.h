// Copyright 2019-2023 Kai D. Gonzalez

// ball code
#include "grid.h" // BALL
#include "dist.h"

/* kick the ball if the player is close enough to the ball */
void kick(xygrid * field, coordinates *player, coordinates *ball, int HEADER);

/* set the ball point */
void bpoint(xygrid * field, int x, int y);
