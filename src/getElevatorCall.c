#include "elevatorApi.h"
#include "elevatorStruct.h"

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
	  out.callingFloor[out.nbrCallingFloor] = i;
	  out.nbrCallingFloor += 1;
	}
    }
  return (out);
}

