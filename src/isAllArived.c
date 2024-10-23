#include "game.h"

bool isAllArived(t_game *game)
{
  for (int i = 0; i < game->nbrElev; i++)
    if (game->elev[i].nbrPeople != 0)
      return (false);
  for (int i = 0; i < game->nbrFloors; i++)
    if (game->floors[i].nbrPeople != 0)
      return (false);
  return (true);
} 

