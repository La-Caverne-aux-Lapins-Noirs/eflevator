#include "game.h"

int main(int nbrIn,
	 char **input)
{
  t_game game;
  bool isFast = false;

  if (nbrIn < 3)
    {
      printf("How to use\n\n./eflevator LEVELCONF ELEVATORCONF\n\nLEVELCONF = configuration du niveau\nELEVATORCONF = configuration de l'assenceur\nvous pouvez ajouter le paramêtre suplémentaire \"fast\" après ELEVATORCONF pour accélérer la simulation\n!! LEVELCONF peut être remplacer par \"smallGroup\" ou \"bigGroup\" pour lancer la simulation en mode infini!!\n");
      return (-1);
    }
  if (nbrIn == 4 && strcmp(input[3], "fast") == 0)
    isFast = true;
  if (!initGame(&game, input[1], input[2], isFast))
    return (-1);
  bunny_set_key_response(keys);
  bunny_set_loop_main_function(mainLoop);
  bunny_set_display_function(display);
  bunny_loop(game.win, 30, &game);
  return (0);
}
