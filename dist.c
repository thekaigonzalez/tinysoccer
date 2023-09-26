#include "dist.h"

void
dist (coordinates *a, coordinates *b, coordinates *m)
{
  m->x = b->x - a->x;
  m->y = b->y - a->y;
}

int
dists (coordinates *a, coordinates *b)
{
  coordinates m;

  dist (a, b, &m);

  if (m.x == m.y)
    return m.x;
  return 0;
}
