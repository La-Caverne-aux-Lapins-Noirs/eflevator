#include "game.h"

void moveElevator(t_elevator *elevator)
{
  if (elevator->pos == elevator->targetPos)
    return;
  if (elevator->pos < elevator->targetPos)
    {
      elevator->pos += elevator->speed;
      if (elevator->pos > elevator->maxUp - 1)
	elevator->pos = elevator->maxUp - 1;
      if (elevator->pos > elevator->targetPos)
	elevator->pos = elevator->targetPos;
    }
  else
    {
      elevator->pos -= elevator->speed;
      if (elevator->pos < 0)
	elevator->pos = 0;
      if (elevator->pos < elevator->targetPos)
	elevator->pos = elevator->targetPos;
    }
}

