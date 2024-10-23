#include "game.h"

bool progressLevel(t_game *game)
{
  const char *event;

  if (game->levelTime <= 0 && game->levelProgress < game->maxLevelEvent)
    {      
      bunny_configuration_getf(game->level, &event, "Level[%d].event", game->levelProgress);
      if (strcmp(event, "wait") == 0)
        bunny_configuration_getf(game->level, &game->levelTime, "Level[%d].time", game->levelProgress);
      else if (strcmp(event, "spawn") == 0)
	{
	  int floor;
	  int number;
	  t_people people;

	  bunny_configuration_getf(game->level, &floor, "Level[%d].floor", game->levelProgress);
	  bunny_configuration_getf(game->level, &number, "Level[%d].number", game->levelProgress);
	  bunny_configuration_getf(game->level, &people.timeLeft, "Level[%d].timer", game->levelProgress);
	  bunny_configuration_getf(game->level, &people.targetFloor, "Level[%d].dest", game->levelProgress);
	  for (int i = 0; i < number; i++)
	    addPeopleToFloor(&game->floors[floor], people);
	}
      game->levelProgress += 1;
      
    }
  else
    game->levelTime -= 0.0334;
  if (isAllArived(game) && game->levelProgress == game->maxLevelEvent)
    return (true);
  return (false);
}

