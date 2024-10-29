#include "game.h"

void addPeopleToElevator(t_elevator *elevator,
			 t_people people)
{
  if (elevator->nbrPeople >= 31)
    return;
  for (int i = elevator->nbrPeople -1; i >= 0 ; i--)
    elevator->peoples[i + 1] = elevator->peoples[i];
  elevator->peoples[0] = people;
  elevator->nbrPeople++;
}

