#include "game.h"

void addPeopleToFloor(t_floor *floor,
		      t_people people)
{
  if (floor->nbrPeople >= 127)
    return;
  for (int i = floor->nbrPeople - 1; i >= 0 ; i--)
    floor->peoples[i + 1] = floor->peoples[i];
  floor->peoples[0] = people;
  floor->nbrPeople++;
}
