#include "global_variables.h"
#include "modding.h"

PlayState* gPlayState;
s8 current_room;

RECOMP_HOOK("Play_Init")
void global_Play_Init(PlayState *play)
{
  gPlayState = play;
  current_room = -1;
}
