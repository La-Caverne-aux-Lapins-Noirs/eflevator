#include "game.h"

void addPeopleToFloor(t_floor *floor,
		      t_people people)
{
  if (floor->nbrPeople >= 127)
    return;
  for (int i = 0; i < floor->nbrPeople; i++)
    floor->peoples[i + 1] = floor->peoples[i];
  floor->peoples[0] = people;
  floor->nbrPeople++;
}
