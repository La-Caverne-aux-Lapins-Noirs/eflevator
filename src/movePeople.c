#include "game.h"

int  movePeople(t_elevator *elevator,
		t_floor *floor)
{
  t_people temp;
  int peopleDeliver = 0;

  for (int i = 0; i < elevator->nbrPeople; i++)
    if (elevator->peoples[i].targetFloor == elevator->pos)
      {
	temp = removePeopleFromElevator(elevator, i);
	peopleDeliver++;
	i--;
      }
  for (int i = 0; i < floor->nbrPeople; i++)
    if (elevator->nbrPeople < elevator->size)
      {
	temp = removePeopleFromFloor(floor, i);
	addPeopleToElevator(elevator, temp);
	i--;
      }
  return (peopleDeliver);
}

