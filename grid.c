#include "grid.h"
#include <stdio.h>
// Copyright 2019-2023 Kai D. Gonzalez
void
ppoint (xygrid *s, int x, int y)
{
  if (s->_space[y][x] == NONE)
    { /* no occupants currently*/
      set (s, x, y, PLAYER);
    }
}

void
set (xygrid *s, int x, int y, int to)
{
  s->_space[y][x] = to;
}

int
get (xygrid *s, int x, int y)
{
  return s->_space[y][x];
}

void
init (xygrid *s)
{
  int x, y;
  for (y = 0; y < GRID_BOUND; ++y)     // y
    {                                  /* search left to right up and down*/
      for (x = 0; x < GRID_BOUND; ++x) // x
        {
          set (s, x, y, NONE);
        }
    }
  s->w = -1;
}

void
find (xygrid *s, coordinates *c, int v)
{
  int y;
  int x;

  int found = NO;

  for (y = 0; y < GRID_BOUND; ++y)     // y
    {                                  /* search left to right up and down*/
      for (x = 0; x < GRID_BOUND; ++x) // x
        {
          if (get (s, x, y) == v)
            {
              c->x = x;
              c->y = y;
              found = 1;
            }
          if (found == YES)
            break;
        }
      if (found == YES)
        break;
    }

  if (found == NO)
    {
      c->x = -1;
      c->y = -1;
    }
}

void
setf (xygrid *grid, int x, int y, int v)
{
  if (get (grid, x, y) == NONE)
    set (grid, x, y, v);
}

void
debug (coordinates *c)
{
  printf ("COORDINATES DEBUG:\n    x: %i\n    y: %i\n", c->x, c->y);
}

coordinates
normal (coordinates *s)
{
  coordinates g;

  g.x = negate (s->x);
  g.y = negate (s->y);

  return g;
}

int
is1 (coordinates *s)
{
  int _output = -1;

  if ((s->x == 1) || (s->x == -1) || (s->x == 0))
    _output = _output + 1;

  if ((s->y == 1) || (s->y == -1) || (s->y == 0))
    _output = _output + 1;

  return _output;
}

int
negate (int x)
{
  if (x == 0)
    return x;

  if (x == -1)
    {
      return -1;
    }

  if (x < -1)
    {
      return -1;
    }

  return 1;
}
