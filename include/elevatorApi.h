#ifndef ELEVATOR_API
#define ELEVATOR_API

#include <stdbool.h>

typedef struct s_elevatorOut
{
  int nbrButtonPressed;
  int buttonPressed[20]; // contien les différents étages demander dans un assenseur
} t_elevatorOut;

typedef struct s_caller
{
  int floor; // numero de l'étage
  bool goUp;
  bool goDown;
} t_caller;

typedef struct s_elevatorCall
{
  int nbrCallingFloor;
  t_caller callingFloor[50]; // contien les étage ayant appeler un assenceur
} t_elevatorCall;

typedef struct s_eflevator
{
  int targetedFloor;
  const double pos; // position en étage
  const int size; // capacité maximal de personne transporté
  const int nbrPeopleIn;
  const char data[528];
} t_eflevator;

typedef struct s_efloor
{
  const int nbrPeopleIn; 
  const char data[2052];
} t_efloor;

t_elevatorOut getElevatorOut(t_eflevator *elevator);
t_elevatorCall getElevatorCall(t_efloor *floor, int nbrFloor);

void computeElevator(t_eflevator *elevator, int nbrElevator, t_efloor *floor, int nbrFloor); // fonction de loop pour l'étudiant

#endif // ELEVATOR_API
