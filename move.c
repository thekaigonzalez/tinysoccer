#include "move.h"

void
cset (coordinates *a, coordinates *b)
{
  b->x = a->x; // point 2 x = point 1 x
  b->y = a->y; // point 2 y = point 1 y
}

void
move (xygrid *g, coordinates *o, coordinates *n)
{
    int vtm = g->_space[o->y][o->x]; // save old coordinates
    g->_space[o->y][o->x] = NONE;    // evacuate old coordinates
    g->_space[n->y][n->x] = vtm;     // set the new coordinates

    cset (n, o);
}

void
move1 (xygrid *s, coordinates *o, coordinates *n)
{
  if (((o->x - n->x) <= 1 && (o->x - n->x) > 0)
      && ((o->y - n->y) <= 1 && (o->y - n->y) > 0))
    {
      move (s, o, n);
    }
}

void
move1clamp (xygrid *s, coordinates *o, coordinates *n)
{
  if (n->x != o->x)
    n->x = o->x + (clamp (n->x, -1, 1));

  if (n->y != o->y)
    n->y = o->y - (clamp (n->y, -1, 1));

  move (s, o, n);
}
