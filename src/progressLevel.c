#include "game.h"

bool progressLevel(t_game *game,
		   int spawnigType)
{
  const char *event;
  double dificulty;

  if (game->levelProgress < 10)
    dificulty = 0;
  else if (game->levelProgress < 20)
    dificulty = 1;
  else if (game->levelProgress < 40)
    dificulty = 2;
  else if (game->levelProgress < 80)
    dificulty = 3;
  else
    dificulty = 3.5;

  if (game->levelTime <= 0 && (game->levelProgress < game->maxLevelEvent || spawnigType != 0))
    {
      if (spawnigType == 0)
	bunny_configuration_getf(game->level, &event, "Level[%d].event", game->levelProgress);
      else if (game->levelProgress % 2 == 0)
	event = "spawn";
      else
	event = "wait";
      if (strcmp(event, "wait") == 0)
	{
	  if (spawnigType == 0)
	    bunny_configuration_getf(game->level, &game->levelTime, "Level[%d].time", game->levelProgress);
	  else if  (spawnigType == 1)
	    game->levelTime = 4 - dificulty;
	  else if  (spawnigType == 2)
	    game->levelTime = 4 - (dificulty / 2);
	    
	}
      else if (strcmp(event, "spawn") == 0)
	{
	  int floor;
	  int number;
	  t_people people;

	  if (spawnigType == 0)
	    {
	      bunny_configuration_getf(game->level, &floor, "Level[%d].floor", game->levelProgress);
	      bunny_configuration_getf(game->level, &number, "Level[%d].number", game->levelProgress);
	      bunny_configuration_getf(game->level, &people.timeLeft, "Level[%d].timer", game->levelProgress);
	      bunny_configuration_getf(game->level, &people.targetFloor, "Level[%d].dest", game->levelProgress);
	    }
	  else if (spawnigType == 1)
	    {
	      floor = rand() % game->nbrFloors;
	      number = rand() % 2 + 1;
	      people.targetFloor = rand() % game->nbrFloors;
	      while (people.targetFloor == floor)
		people.targetFloor = rand() % game->nbrFloors;
	      people.timeLeft = 8 + (2 * abs(floor - people.targetFloor)) + rand() % 4;
	    }
	  else if (spawnigType == 2)
	    {
	      floor = rand() % game->nbrFloors;
	      number = rand() % 3 + 3;
	      people.targetFloor = rand() % game->nbrFloors;
	      while (people.targetFloor == floor)
		people.targetFloor = rand() % game->nbrFloors;
	      people.timeLeft = 8 + (2 * abs(floor - people.targetFloor)) + rand() % 4;
	    }
	  for (int i = 0; i < number; i++)
	    addPeopleToFloor(&game->floors[floor], people);
	}
      game->levelProgress += 1;
      
    }
  else
    game->levelTime -= 0.0334;
  if (isAllArived(game) && game->levelProgress == game->maxLevelEvent && spawnigType == 0)
    return (true);
  return (false);
}

