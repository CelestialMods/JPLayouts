#include "helpers.h"

void CelestialMods_SetActorPos(Actor *actor, f32 x, f32 y, f32 z)
{
  if (actor != NULL)
  {
    Vec3f pos = {x, y, z};
    actor->home.pos = actor->world.pos = pos;
  }
}

Actor *CelestialMods_SpawnWithCutscene(PlayState *play, s16 actorId, f32 x, f32 y, f32 z, s16 rotX, s16 rotY, s16 rotZ, s32 params, u32 csId)
{
  return Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, actorId, x, y, z, rotX, rotY, rotZ, params, csId, HALFDAYBIT_ALL, NULL);
}
