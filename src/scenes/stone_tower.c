#include "global.h"
#include "modding.h"
#include "recomputils.h"

#include "global_variables.h"
#include "overlays/actors/ovl_Bg_F40_Block/z_bg_f40_block.h"

RECOMP_IMPORT("ProxyMM_ActorListIndex", s32 GetActorListIndex(Actor *actor));

static Vec3s newPathwayPoints[] = {
    {164, -506, 1511},
    {164, -506, 1711},
    {4, -506, 1711},
    {4, -680, 1711},
    {4, -680, 1871},
};

static Vec3s anotherPathwayPoints[] = {
    {-156, -506, 1511},
    {-156, -506, 1871},
    {4, -506, 1871},
    {4, -506, 2151},
    {4, -680, 2151},
    {4, -680, 2431},
};

static Path newPath = (Path){ARRAY_COUNT(newPathwayPoints), -1, -1, newPathwayPoints};
static Path anotherPath = (Path){ARRAY_COUNT(anotherPathwayPoints), -1, -1, anotherPathwayPoints};

RECOMP_CALLBACK("*", recomp_after_actor_init)
void StoneTower_AfterActorInit(PlayState *play, Actor *actor)
{
  if (play->sceneId != SCENE_F40)
    return;
  BgF40Block *this;
  switch (GetActorListIndex(actor))
  {
  case 85:
    this = (BgF40Block *)actor;
    this->path = &newPath;
    this->dyna.actor.world.pos = (Vec3f){164, -506, 1511};
    break;
  case 90:
    this = (BgF40Block *)actor;
    this->path = &anotherPath;
    this->dyna.actor.world.pos = (Vec3f){-156, -506, 1511};
    break;
  case 86:
  case 91:
  case 92:
    Actor_Kill(actor);
    break;
  default:
    break;
  }
}
