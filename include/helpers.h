#pragma once

#include "global.h"

void CelestialMods_SetActorPos(Actor *actor, f32 x, f32 y, f32 z);
Actor *CelestialMods_SpawnWithCutscene(PlayState *play, s16 actorId, f32 x, f32 y, f32 z, s16 rotX, s16 rotY, s16 rotZ, s32 params, u32 csId);
