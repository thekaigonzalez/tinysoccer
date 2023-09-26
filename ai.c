#include "ai.h"
#include "ball.h"
#include "dist.h"
#include "move.h"
// Copyright 2019-2023 Kai D. Gonzalez

void
nextmove (xygrid *grid, coordinates *tm, coordinates *ball)
{
  coordinates meandball; // distance between me (the ai) and the ball

  dist (tm, ball, &meandball); // calculate distance between me and the ball

  coordinates normalized = normal(&meandball);

  normalized.x = tm->x + normalized.x;
  normalized.y = tm->y + normalized.y;

  if (is1 (&meandball))
    {
      kick (grid, tm, ball, TEAM2);
    }
  else
    {
      move (grid, tm, &normalized);
    }
}
