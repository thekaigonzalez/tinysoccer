#include "ball.h"
#include "dist.h"
#include "move.h"

#include <stdio.h>

void
kick (xygrid *field, coordinates *player, coordinates *ball, int HEADER)
{
  coordinates distance;

  dist (player, ball, &distance);
  if (is1(&distance) > 0)
    { // player can not kick they are farther than 1 grid space
      coordinates newball;
      newball.x = ball->x + negate(distance.x);
      
      newball.y = ball->y + negate(distance.y);

      if (get (field, newball.x, newball.y) != NONE
          && get (field, newball.x, newball.y) != GOAL)
        {
          printf ("kick(): you kicked it to someone who's already there!\n");
          return;
        }
      else if (get (field, newball.x, newball.y) == GOAL)
        {
          if (HEADER == PLAYER)
            {
              printf("YOU WIN!\n");
              field->w = 1; // you win!
            }
          else if (HEADER == TEAM2)
            {
              printf("YOU LOSE!\n");

              field->w = 0;
            }
          return;
        }
      move (field, ball, &newball);
    }
  else
    {
      printf ("kick(): error! you can not kick because you are too far!\n");
    }
}

void
bpoint (xygrid *field, int x, int y)
{
  setf (field, x, y, BALL);
}
