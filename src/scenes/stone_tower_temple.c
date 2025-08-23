#include "global.h"
#include "modding.h"
#include "recomputils.h"

RECOMP_CALLBACK("*", recomp_after_actor_init)
void StoneTowerTemple_AfterActorInit(PlayState *play, Actor *actor)
{
  if (play->sceneId != SCENE_INISIE_N)
    return;

  if (play->roomCtx.curRoom.num != 9)
    return;

  if (actor->id == ACTOR_OBJ_LIGHTSWITCH)
    Actor_Kill(actor);
}
