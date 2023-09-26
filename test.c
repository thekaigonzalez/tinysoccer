#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ball.h"
#include "disp.h"
#include "move.h"
#include "nat.h"
#include "ai.h"

main ()
{
  xygrid grid;

  coordinates playerpoint;        // (3, 0)
  coordinates ballpoint;          // (3, -3)
  coordinates playerballdistance; // distance between the player and ball
  coordinates ptm;                // PTM (Point To Move)
  coordinates tm1;                // coordinates of the only team 2 member

  init (&grid);

  // set points on the grid
  ppoint (&grid, real (2), real (2));
  bpoint (&grid, real (3), real (4));

  setf (&grid, real (3), real (5), TEAM2);
  setf (&grid, real (5), real (3), GOAL);

  find (&grid, &playerpoint, PLAYER);
  find (&grid, &ballpoint, BALL);
  find (&grid, &tm1, TEAM2);

  dist (&ballpoint, &playerpoint, &playerballdistance);

  system ("clear");
  printf("gen 1\n");

  print_grid (&grid);
  sleep(2);
  system("clear");
  printf("gen 2\n");

  nextmove(&grid, &tm1, &ballpoint);

  print_grid(&grid);

  sleep(3);

  system("clear");

  printf("gen 3\n");

  kick (&grid, &playerpoint, &ballpoint, PLAYER); // kicking from the player.
  
  print_grid (&grid);
  sleep (2);
  system("clear");
  nextmove(&grid, &tm1, &ballpoint);
  print_grid (&grid);

}
