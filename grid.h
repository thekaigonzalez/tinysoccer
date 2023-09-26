// Copyright 2019-2023 Kai D. Gonzalez

#define GRID_BOUND 5 /* grids will ALWAYS be even */
#define GRID_FAKE_MAX                                                         \
  GRID_BOUND - 1 /* grids have a weird offset, read the readme (the grid      \
                    offset issue) to understand */
#define real(x)                                                               \
  (x > 1) ? x - 1 : x /* the "real" value of a grid - since they're arrays    \
                         you cant go to the full length you will have to use  \
                         this to get "true" position values*/

#define NONE 0
#define PLAYER 1
#define BALL 2
#define TEAM2 3
#define GOAL 4

#define YES 1
#define NO -1

#define close(distance)                                                       \
  (real(distance.x) == 1 || real(distance.x) == 0 || real(distance.x) == -1)                    \
  && (real(distance.y) == 1 || real(distance.y) == 0 || real(distance.y) == -1)                  \

#define clamp(x, min, max) (x >= max) ? max : (x < min) ? min : x
#define isnegative(x) (x < 0) ? YES : NO

#ifndef _GRIDZC_ // just learned what these are for
#define _GRIDZC_

    typedef struct Grid
{
  int _space[GRID_BOUND][GRID_BOUND]; /* 5x5 for example*/
  int x;                              // the x
  int y;                              // the y
  int w;                              // the game won?
} xygrid;

typedef struct coordinates
{
  int x;
  int y;
} coordinates;

/* ppoint (player point) set the player point in the grid */
void ppoint (xygrid *s, int x, int y);

/* set x and y to value "to" */
void set (xygrid *s, int x, int y, int to);

/* get the value for the point at (x, y)*/
int get (xygrid *s, int x, int y);

/* initialize a grid - set all x and y to NONE */
void init (xygrid *s);

/* find the player and sets the x and y of the given coordinates */
void find (xygrid *s, coordinates *c, int v);

/* setf will set the spot to V if the space is not occupied*/
void setf (xygrid *grid, int x, int y, int v);

/* print all known information about coordinates */
void debug(coordinates * c);

/* will make x and y 1 if they're a great value */
coordinates normal(coordinates* s);

/* is x and y less than or 1? and not less than -1 either?*/
int is1(coordinates* s);

/* converts -1 to 1 . literally*/
int negate(int x);

#endif
