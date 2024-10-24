#include "elevatorApi.h"
#include "elevatorStruct.h"

static bool peopleWantGoUp(t_people *people,
			   int nbrPeople,
			   int currentFloor)
{
  for (int i = 0; i < nbrPeople; i++)
    if (people[i].targetFloor - currentFloor > 0)
      return (true);
  return (false);
}

static bool peopleWantGoDown(t_people *people,
			     int nbrPeople,
			     int currentFloor)
{
  for (int i = 0; i < nbrPeople; i++)
    if (people[i].targetFloor - currentFloor < 0)
      return (true);
  return (false);
}

t_elevatorCall getElevatorCall(t_efloor *floor,
			       int nbrFloor)
{
  t_floor *castFloor = (t_floor *)floor;
  t_elevatorCall out;

  out.nbrCallingFloor = 0;
  for (int i = 0; i < nbrFloor; i++)
    {
      if (castFloor[i].nbrPeople != 0)
	{
	  out.callingFloor[out.nbrCallingFloor].floor = i;
	  out.callingFloor[out.nbrCallingFloor].goUp = peopleWantGoUp(castFloor[i].peoples, castFloor[i].nbrPeople, i);
	  out.callingFloor[out.nbrCallingFloor].goDown = peopleWantGoDown(castFloor[i].peoples, castFloor[i].nbrPeople, i);
	  out.nbrCallingFloor += 1;
	}
    }
  return (out);
}

