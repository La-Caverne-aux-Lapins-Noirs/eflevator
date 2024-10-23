#include "game.h"

bool isPlayerLosing(t_game *game)
{
  for (int i = 0; i < game->nbrElev; i++)
    for (int j = 0; j < game->elev[i].nbrPeople; j++)
      {
	if (game->elev[i].peoples[j].timeLeft <= 0)
	  return (true);
	else
	  game->elev[i].peoples[j].timeLeft -= 0.0334;
      }
  for (int i = 0; i < game->nbrFloors; i++)
    for (int j = 0; j < game->floors[i].nbrPeople; j++)
      {
	if (game->floors[i].peoples[j].timeLeft <= 0)
	  return (true);
	else
	  game->floors[i].peoples[j].timeLeft -= 0.0334;  
      }
  return (false);
}

