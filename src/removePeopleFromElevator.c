#include "game.h"

t_people removePeopleFromElevator(t_elevator *elevator,
				  int index)
{
  t_people temp;

  
  temp.timeLeft = -1;
  temp.targetFloor = -1;
  if (elevator->nbrPeople <= 0)
    return (temp);
  
  temp = elevator->peoples[index];
  for (int i = index; i < elevator->nbrPeople - 1; i++)
    elevator->peoples[i] = elevator->peoples[i + 1];
  elevator->nbrPeople--;
  return (temp);
}

