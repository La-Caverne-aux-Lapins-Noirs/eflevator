#include "game.h"

void passTimePeople(t_people *people,
		    double timePassed)
{
  people->timeLeft -= timePassed;
}

