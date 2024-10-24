#ifndef GAME_H
#define GAME_H

#include <lapin.h>
#include "elevatorApi.h"
#include "elevatorStruct.h"

void passTimePeople(t_people *people,
		    double timePassed);

void moveElevator(t_elevator *elevator);
void addPeopleToElevator(t_elevator *elevator, t_people people);
t_people removePeopleFromElevator(t_elevator *elevator, int index);

int movePeople(t_elevator *elevator, t_floor *floor);
void addPeopleToFloor(t_floor *floor, t_people people);
t_people removePeopleFromFloor(t_floor *floor, int index);

typedef struct s_vertex
{
  size_t lenght;
  t_bunny_vertex vertex[200];
} t_vertex;

typedef struct s_game
{
  t_bunny_window *win;
  t_bunny_picture *pix;
  int nbrElev;
  t_elevator elev[15];
  int nbrFloors;
  t_floor floors[50];
  t_bunny_picture *pictElev;
  t_bunny_picture *pictPeople;
  int mul;
  int nbrPeopleTransport;
  int modeType;
  
  t_bunny_configuration *level;
  int levelProgress;
  int maxLevelEvent;
  double levelTime;

  t_vertex vertex;
} t_game;

bool isPlayerLosing(t_game *game);
bool progressLevel(t_game *game, int spawnigType);
bool isAllArived(t_game *game);

void displayFloor(t_game *game);
void displayElev(t_game *game);

bool initGame(t_game *game, char *level, char *elevator, bool isFast);
t_bunny_response mainLoop(void *data);
t_bunny_response keys(t_bunny_event_state state, t_bunny_keysym sym, void *data);
t_bunny_response display(void *data);

#endif // GAME_H
