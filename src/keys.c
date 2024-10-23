#include "game.h"

t_bunny_response keys(t_bunny_event_state state,
		      t_bunny_keysym	sym,
		      void		*data)
{
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

