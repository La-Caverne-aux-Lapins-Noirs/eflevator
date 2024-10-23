#include "game.h"

t_people removePeopleFromFloor(t_floor *floor,
			       int index)
{
  t_people temp;

  temp.timeLeft = -1;
  temp.targetFloor = -1;
  if (floor->nbrPeople <= 0)
    return (temp);
  temp = floor->peoples[index];
  for (int i = index; i < floor->nbrPeople - 1; i++)
    floor->peoples[i] = floor->peoples[i + 1];
  floor->nbrPeople--;
  return (temp);
}

