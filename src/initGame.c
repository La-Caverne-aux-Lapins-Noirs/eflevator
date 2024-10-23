#include "game.h"

bool initGame(t_game *game,
	      char *level,
	      char *elevator)
{
  t_bunny_configuration *newConf;

  if ((newConf = bunny_load_configuration(BC_DABSIC, elevator, NULL)) == NULL)
    {
      printf("FAILED TO LOAD ELEVATOR\n");
      return (false);
    }
  bunny_configuration_getf(newConf, &game->nbrFloors, "nbrFloor");
  for (int i = 0; i < game->nbrFloors; i++)
    game->floors[i].nbrPeople = 0;
  bunny_configuration_getf(newConf, &game->nbrElev, "nbrElevator");
  for (int i = 0; i < game->nbrElev; i++)
    {
      bunny_configuration_getf(newConf, &game->elev[i].size, "Elevator[%d].size", i);
      bunny_configuration_getf(newConf, &game->elev[i].speed, "Elevator[%d].speed", i);
      game->elev[i].nbrPeople = 0;
      game->elev[i].pos = 0;
      game->elev[i].targetPos = 0;
      game->elev[i].maxUp = game->nbrFloors;
    }
  game->pictElev = bunny_load_picture("res/elevators.jpg");
  game->pictPeople = bunny_load_picture("res/waiting.png");
  if ((game->level = bunny_load_configuration(BC_DABSIC, level, NULL)) == NULL)
    {
      printf("FAILED LOAD LEVEL\n");
      return (false);
    }
  bunny_configuration_getf(game->level, &game->maxLevelEvent, "nbrEvent");
  game->levelProgress = 0;
  game->levelTime = 0;
  game->pix = bunny_new_picture(1920, 900);
  game->win = bunny_start(1920, 900, false, "eflevator");
  return (true);
}
