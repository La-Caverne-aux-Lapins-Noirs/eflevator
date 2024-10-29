#include "game.h"

t_bunny_response mainLoop(void *data)
{
  t_game *game = (t_game *)data;

  for (int j = 0; j < game->mul; j++)
    {
      for (int i = 0; i < game->nbrElev; i++)
	{
	  moveElevator(&game->elev[i]);
	  if (game->elev[i].targetPos == game->elev[i].pos)
	    game->nbrPeopleTransport += movePeople(&game->elev[i], &game->floors[game->elev[i].targetPos]);
	}
      if (isPlayerLosing(game))
	{
	  printf("YOU LOSE!\n");
	  printf("People transported %d\n", game->nbrPeopleTransport);
	  return (EXIT_FAILURE);
	}
      if (progressLevel(game, game->modeType))
	{
	  printf("YOU WIN!\n");
	  printf("People transported %d\n", game->nbrPeopleTransport);
	  return (EXIT_ON_SUCCESS);
	}
      computeElevator((t_eflevator *)game->elev, game->nbrElev, (t_efloor *)game->floors, game->nbrFloors);
    }
  return (GO_ON);
}

