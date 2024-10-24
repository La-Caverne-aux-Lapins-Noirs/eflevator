#include "game.h"

void displayElev(t_game *game)
{
  game->vertex.lenght = 0;
  for (int i = 0; i < game->nbrElev; i++)
    {
      int offsetx = i * (game->pix->buffer.width / 4 / game->nbrElev);
      int offsety = game->elev[i].pos * (game->pix->buffer.height / game->nbrFloors);
      game->vertex.lenght = 0;
      game->vertex.vertex[game->vertex.lenght].pos.x = offsetx;
      game->vertex.vertex[game->vertex.lenght].pos.y = game->pix->buffer.height - offsety;
      game->vertex.vertex[game->vertex.lenght].tex.x = 0;
      game->vertex.vertex[game->vertex.lenght].tex.y = game->pictElev->buffer.height;
      game->vertex.vertex[game->vertex.lenght + 1].pos.x = offsetx + (game->pix->buffer.width / 4 / game->nbrElev);
      game->vertex.vertex[game->vertex.lenght + 1].pos.y = game->pix->buffer.height - offsety;
      game->vertex.vertex[game->vertex.lenght + 1].tex.x = game->pictElev->buffer.width;
      game->vertex.vertex[game->vertex.lenght + 1].tex.y = game->pictElev->buffer.height;
      game->vertex.vertex[game->vertex.lenght + 2].pos.x = offsetx + (game->pix->buffer.width / 4 / game->nbrElev);
      game->vertex.vertex[game->vertex.lenght + 2].pos.y = game->pix->buffer.height - offsety - game->pix->buffer.height / game->nbrFloors;
      game->vertex.vertex[game->vertex.lenght + 2].tex.x = game->pictElev->buffer.width;
      game->vertex.vertex[game->vertex.lenght + 2].tex.y = 0;
      game->vertex.vertex[game->vertex.lenght + 3].pos.x = offsetx;
      game->vertex.vertex[game->vertex.lenght + 3].pos.y = game->pix->buffer.height - offsety - game->pix->buffer.height / game->nbrFloors;
      game->vertex.vertex[game->vertex.lenght + 3].tex.x = 0;
      game->vertex.vertex[game->vertex.lenght + 3].tex.y = 0;
      game->vertex.lenght = 4;
      bunny_set_geometry(&game->win->buffer, BGY_QUADS, (t_bunny_vertex_array *)&game->vertex, game->pictElev);
      game->vertex.lenght = 0;
      for (int j = 0; j < game->elev[i].nbrPeople; j++)
	{
	  int offsetxp = j * ((game->pix->buffer.width / 4 / game->nbrElev) / game->elev[i].size) + offsetx;
	  if (game->elev[i].size % 2 != 0)
	    offsetxp -= 12;
	  game->vertex.vertex[game->vertex.lenght].pos.x = offsetxp;
	  game->vertex.vertex[game->vertex.lenght].pos.y = game->pix->buffer.height - offsety;
	  game->vertex.vertex[game->vertex.lenght].tex.x = 0;
	  game->vertex.vertex[game->vertex.lenght].tex.y = game->pictPeople->buffer.height;
	  game->vertex.vertex[game->vertex.lenght + 1].pos.x = offsetxp + ((game->pix->buffer.width / 4 / game->nbrElev) / game->elev[i].size);
	  game->vertex.vertex[game->vertex.lenght + 1].pos.y = game->pix->buffer.height - offsety;
	  game->vertex.vertex[game->vertex.lenght + 1].tex.x = game->pictPeople->buffer.width;
	  game->vertex.vertex[game->vertex.lenght + 1].tex.y = game->pictPeople->buffer.height;
	  game->vertex.vertex[game->vertex.lenght + 2].pos.x = offsetxp + ((game->pix->buffer.width / 4 / game->nbrElev) / game->elev[i].size);
	  game->vertex.vertex[game->vertex.lenght + 2].pos.y = game->pix->buffer.height - offsety - game->pix->buffer.height / game->nbrFloors;
	  game->vertex.vertex[game->vertex.lenght + 2].tex.x = game->pictPeople->buffer.width;
	  game->vertex.vertex[game->vertex.lenght + 2].tex.y = 0;
	  game->vertex.vertex[game->vertex.lenght + 3].pos.x = offsetxp;
	  game->vertex.vertex[game->vertex.lenght + 3].pos.y = game->pix->buffer.height - offsety - game->pix->buffer.height / game->nbrFloors;
	  game->vertex.vertex[game->vertex.lenght + 3].tex.x = 0;
	  game->vertex.vertex[game->vertex.lenght + 3].tex.y = 0;
	  game->vertex.lenght += 4;
	}
      bunny_set_geometry(&game->win->buffer, BGY_QUADS, (t_bunny_vertex_array *)&game->vertex, game->pictPeople);
    }
}
