#include "game.h"

void displayFloor(t_game *game)
{
  game->vertex.lenght = 0;
  for (int i = 0; i < game->nbrFloors; i++)
    {
      for (int j = 0; j < game->floors[i].nbrPeople; j++)
	{
	  int offsetx = game->pix->buffer.width / 4 + j * 50;
	  int offsety = i * (game->pix->buffer.height / game->nbrFloors);
	  game->vertex.vertex[game->vertex.lenght].pos.x = offsetx;
	  game->vertex.vertex[game->vertex.lenght].pos.y = game->pix->buffer.height - offsety;
	  game->vertex.vertex[game->vertex.lenght].tex.x = 0;
	  game->vertex.vertex[game->vertex.lenght].tex.y = game->pictPeople->buffer.width;
	  game->vertex.vertex[game->vertex.lenght + 1].pos.x = offsetx + 50;
	  game->vertex.vertex[game->vertex.lenght + 1].pos.y = game->pix->buffer.height - offsety;
	  game->vertex.vertex[game->vertex.lenght + 1].tex.x = game->pictPeople->buffer.width;
	  game->vertex.vertex[game->vertex.lenght + 1].tex.y = game->pictPeople->buffer.width;
	  game->vertex.vertex[game->vertex.lenght + 2].pos.x = offsetx + 50;
	  game->vertex.vertex[game->vertex.lenght + 2].pos.y = game->pix->buffer.height - offsety - game->pix->buffer.height / game->nbrFloors;
	  game->vertex.vertex[game->vertex.lenght + 2].tex.x = game->pictPeople->buffer.width;
	  game->vertex.vertex[game->vertex.lenght + 2].tex.y = 0;
	  game->vertex.vertex[game->vertex.lenght + 3].pos.x = offsetx;
	  game->vertex.vertex[game->vertex.lenght + 3].pos.y = game->pix->buffer.height - offsety - game->pix->buffer.height / game->nbrFloors;
	  game->vertex.vertex[game->vertex.lenght + 3].tex.x = 0;
	  game->vertex.vertex[game->vertex.lenght + 3].tex.y = 0;
	  game->vertex.lenght += 4;
	}
    }
  bunny_set_geometry(&game->win->buffer, BGY_QUADS, (t_bunny_vertex_array *)&game->vertex, game->pictPeople);
}

