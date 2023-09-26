#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ai.h"
#include "ball.h"
#include "disp.h"
#include "move.h"
#include "nat.h"

void
refresh (xygrid *grid)
{
  system ("clear");
  print_grid (grid);
}

char *
getinp ()
{
  char *c = malloc (BUFSIZ);

  fgets (c, BUFSIZ, stdin);

  if ((strlen (c) > 0) && (c[strlen (c) - 1] == '\n')) // wtf is this
    c[strlen (c) - 1] = '\0';

  return c;
}

main ()
{
  printf ("welcome to 1987 soccer!\n");
  sleep (2);

  xygrid grid;

  coordinates ballpoint; // (3, -3)

  coordinates playerpoint; // (3, 0)
  coordinates tm1;         // coordinates of the only team 2 member

  coordinates playerballdistance; // distance between the player and ball

  init (&grid);

  // set points on the grid
  ppoint (&grid, real (2), real (2));
  bpoint (&grid, real (3), real (3));

  setf (&grid, real (3), real (5), TEAM2);
  setf (&grid, real (5), real (3), GOAL);

  find (&grid, &playerpoint, PLAYER);
  find (&grid, &ballpoint, BALL);
  find (&grid, &tm1, TEAM2);

  dist (&ballpoint, &playerpoint, &playerballdistance);

  // player input loop

  refresh (&grid);

  sleep (2);

  printf ("time for the games to begin!\n");

  while (1)
    {
      printf ("make your move: ");
      char *c = getinp ();
      if (strcmp (c, "move") == 0)
        {
          printf ("how far do you want to move RIGHT OR LEFT ? ");
          char *g = getinp ();
          int XmoveAmount = atoi (g);
          printf ("how far do you want to move UP OR DOWN ? ");
          char *z = getinp ();
          int YmoveAmount = atoi (z);
          coordinates tomove;
          
          printf("%i\n", negate(XmoveAmount));
          printf("%i\n", YmoveAmount);

          setc (&tomove, playerpoint.x + negate (XmoveAmount),
                playerpoint.y + negate (YmoveAmount));
          move (&grid, &playerpoint, &tomove);
        }
      else if (strcmp (c, "kick") == 0)
        {
          kick (&grid, &playerpoint, &ballpoint, PLAYER);
        }
      sleep (2);
      refresh (&grid);
      sleep (4);
      nextmove (&grid, &tm1, &ballpoint);
      refresh (&grid);
      sleep (3);
      if (grid.w == 0)
        {
            system("clear");
            sleep(1);
            printf("this game was a tough one...\n");
            sleep(2);
            printf("but TEAM 2 WINS! sorry player, you'll get it next time.\n");
            sleep(5);
            system("clear");
            break;
        }
    else if (grid.w == 1)
        {
            system("clear");
            sleep(1);
            printf("this game was a tough one...\n");
            sleep(2);
            printf("but THE PLAYER WINS!! sorry team 2, one day you'll beat the master.\n");
            sleep(5);
            system("clear");
            break;
        }
      printf ("this seems like a tight game... focus up!\n");
      sleep (2);
      refresh (&grid);
    }
}
