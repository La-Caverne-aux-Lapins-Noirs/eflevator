#ifndef ELEVATOR_STRUCT
#define ELEVATOR_STRUCT

typedef struct s_people
{
  double timeLeft;
  int targetFloor;
} t_people;

typedef struct s_elevator
{
  int targetPos;
  double pos;
  int size;
  int nbrPeople;
  t_people peoples[32];
  double speed;
  int maxUp;
} t_elevator;

typedef struct s_floor
{
  int nbrPeople;
  t_people peoples[128];
} t_floor;


#endif // ELEVATOR_STRUCT
