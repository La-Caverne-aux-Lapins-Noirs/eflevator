#include "game.h"

t_bunny_response display(void *data)
{
  t_game *game = (t_game *)data;
  
  game->vertex.lenght = 8;
  game->vertex.vertex[0].pos.x = 0;
  game->vertex.vertex[0].pos.y = 0;
  game->vertex.vertex[0].color = BLACK;
  game->vertex.vertex[1].pos.x = game->pix->buffer.width / 4;
  game->vertex.vertex[1].pos.y = 0;
  game->vertex.vertex[1].color = BLACK;
  game->vertex.vertex[2].pos.x = game->pix->buffer.width / 4;
  game->vertex.vertex[2].pos.y = game->pix->buffer.height;
  game->vertex.vertex[2].color = BLACK;
  game->vertex.vertex[3].pos.x = 0;
  game->vertex.vertex[3].pos.y = game->pix->buffer.height;
  game->vertex.vertex[3].color = BLACK;
  t_bunny_color color;
  color.argb[RED_CMP] = 125;
  color.argb[BLUE_CMP] = 125;
  color.argb[GREEN_CMP] = 125;
  color.argb[ALPHA_CMP] = 255;
  
  game->vertex.vertex[4].pos.x = game->pix->buffer.width / 4;
  game->vertex.vertex[4].pos.y = 0;
  game->vertex.vertex[4].color = color.full;
  game->vertex.vertex[5].pos.x = game->pix->buffer.width;
  game->vertex.vertex[5].pos.y = 0;
  game->vertex.vertex[5].color = color.full;
  game->vertex.vertex[6].pos.x = game->pix->buffer.width;
  game->vertex.vertex[6].pos.y = game->pix->buffer.height;
  game->vertex.vertex[6].color = color.full;
  game->vertex.vertex[7].pos.x = game->pix->buffer.width / 4;
  game->vertex.vertex[7].pos.y = game->pix->buffer.height;
  game->vertex.vertex[7].color = color.full;
  bunny_set_geometry(&game->win->buffer, BGY_QUADS, (t_bunny_vertex_array *)&game->vertex, NULL);
  displayElev(game);
  displayFloor(game);
  bunny_display(game->win);
  return (GO_ON);
}


