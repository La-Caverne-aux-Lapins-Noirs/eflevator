#include "game.h"

int main(int nbrIn,
	 char **input)
{
  t_game game;

  if (nbrIn != 3)
    {
      printf("How to use\n\n./eflevator LEVELCONF ELEVATORCONF\n\nLEVELCONF = configuration du niveau\nELEVATORCONF = configuration de l'assenceur\n");
      return (-1);
    }
  if (!initGame(&game, input[1], input[2]))
    return (-1);
  bunny_set_key_response(keys);
  bunny_set_loop_main_function(mainLoop);
  bunny_set_display_function(display);
  bunny_loop(game.win, 30, &game);
  return (0);
}
