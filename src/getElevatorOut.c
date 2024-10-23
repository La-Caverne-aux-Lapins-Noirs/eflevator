#include "elevatorApi.h"
#include "elevatorStruct.h"
#include "stdio.h"

t_elevatorOut getElevatorOut(t_eflevator *elevator)
{
  t_elevator *castElevator = (t_elevator *)elevator;
  t_elevatorOut out;

  out.nbrButtonPressed = 0;
  for (int i = 0; i < castElevator->nbrPeople; i++)
    {
      int j;

      for (j = 0; j < out.nbrButtonPressed; j++)
	if (out.buttonPressed[j] == castElevator->peoples[i].targetFloor)
	  break;
      out.buttonPressed[out.nbrButtonPressed] = castElevator->peoples[i].targetFloor;
      out.nbrButtonPressed += 1;
    }
  return (out);
}

