#include "game.h"

t_bunny_response mainLoop(void *data)
{
  t_game *game = (t_game *)data;
  for (int i = 0; i < game->nbrElev; i++)
    {
      moveElevator(&game->elev[i]);
      if (game->elev[i].targetPos == game->elev[i].pos)
	movePeople(&game->elev[i], &game->floors[game->elev[i].targetPos]);
    }
  if (isPlayerLosing(game))
    {
      printf("YOU LOSE!\n");
      return (EXIT_ON_SUCCESS);
    }
  if (progressLevel(game))
    {
      printf("YOU WIN!\n");
      return (EXIT_ON_SUCCESS);
    }
  computeElevator((t_eflevator *)game->elev, game->nbrElev, (t_efloor *)game->floors, game->nbrFloors);
  return (GO_ON);
}

