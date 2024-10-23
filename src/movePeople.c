#include "game.h"

void movePeople(t_elevator *elevator,
		t_floor *floor)
{
  t_people temp;

  for (int i = 0; i < elevator->nbrPeople; i++)
    if (elevator->peoples[i].targetFloor == elevator->pos)
      {
	temp = removePeopleFromElevator(elevator, i);
	i--;
      }
  for (int i = 0; i < floor->nbrPeople; i++)
    if (elevator->nbrPeople < elevator->size)
      {
	temp = removePeopleFromFloor(floor, i);
	addPeopleToElevator(elevator, temp);
	i--;
      }
}

