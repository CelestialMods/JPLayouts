#include "global.h"
#include "modding.h"
#include "recomputils.h"
#include "z64recomp_api.h"

#include "actor_to_string.h"
#include "global_variables.h"

#define CUR_ROOM(play) ((play)->roomCtx.curRoom.num)

RECOMP_IMPORT("ProxyMM_ActorListIndex", s32 GetActorListIndex(Actor *actor));

void CelestialMods_SetActorPos(Actor *actor, f32 x, f32 y, f32 z)
{
  if (actor != NULL)
  {
    Vec3f pos = {x, y, z};
    actor->home.pos = actor->world.pos = pos;
  } 
}
RECOMP_CALLBACK("*", recomp_after_actor_init)
void DekuPalace_AfterActorInit(PlayState *play, Actor *actor)
{
  if (play->sceneId != SCENE_22DEKUCITY)
    return;

  s32 actorIndex = GetActorListIndex(actor);

  switch (CUR_ROOM(play))
  {
  case 1:
  {
    switch (actorIndex)
    {
    case 6: // DOOR_ANA - Bean Grotto
      CelestialMods_SetActorPos(actor, 451, 80, 726);
      break;
    case 17: // OBJ_MURE_3 - Rupee Circle
      CelestialMods_SetActorPos(actor, 405, 0, 1554);
      break;
    case 25: // OBJ_SYOKUDAI - Torch
      CelestialMods_SetActorPos(actor, 352, 160, 655);
      break;
    case 26: // OBJ_SYOKUDAI - Torch
      CelestialMods_SetActorPos(actor, 450, 80, 655);
      break;
    case 27: // OBJ_SYOKUDAI - Torch
      CelestialMods_SetActorPos(actor, 352, 160, 655);
      break;
    case 28: // OBJ_SYOKUDAI - Torch
      CelestialMods_SetActorPos(actor, 450, 80, 655);
      break;
    }
  }
  case 2:
  {
    switch (actorIndex)
    {
    case 10:
    case 11:
      Actor_Kill(actor);
      break;
    default:
      break;
    }
  }
  }
}

Actor *CelestialMods_SpawnTorch(PlayState *play, float x, float y, float z)
{
  s16 objSyokudai_params = 0x207f;
  if (gSaveContext.save.isNight)
    objSyokudai_params |= 0x800;
  return Actor_Spawn(&play->actorCtx, play, ACTOR_OBJ_SYOKUDAI, x, y, z, 0, 0, 0, objSyokudai_params);
}

Actor *CelestialMods_SpawnWithCutscene(PlayState *play, s16 actorId, f32 x, f32 y, f32 z, s16 rotX, s16 rotY, s16 rotZ, s32 params, u32 csId)
{
  return Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, actorId, x, y, z, rotX, rotY, rotZ, params, csId, HALFDAYBIT_ALL, NULL);
}

void DekuPalace_JpLayout(PlayState *play)
{
  if (gSaveContext.gameMode != GAMEMODE_NORMAL)
    return;

  if (play->sceneId != SCENE_22DEKUCITY)
    return;

  if (current_room == CUR_ROOM(play))
    return;

  Actor *ana;
  current_room = CUR_ROOM(play);
  switch (CUR_ROOM(play))
  {
  case 1:
    /* Top grotto */
    CelestialMods_SpawnWithCutscene(play, ACTOR_DOOR_ANA, 354, 160, 712, 0, 0, 0, 0x305, 20);

    /* Right Climb Grotto */
    CelestialMods_SpawnWithCutscene(play, ACTOR_DOOR_ANA, 423, 0, 1340, 0, 0, 0, 0x304, 17);

    CelestialMods_SpawnTorch(play, 421, 0, 1296);
    Actor_Spawn(&play->actorCtx, play, ACTOR_EN_ITEM00, 406, 80, 876, 0, 0, 0, 0x1101);
    Actor_Spawn(&play->actorCtx, play, ACTOR_EN_ITEM00, 439, 80, 825, 0, 0, 0, 0x1201);
    break;
  case 2:
    CelestialMods_SpawnTorch(play, -1040, 0, 656);
    CelestialMods_SpawnTorch(play, -420, 0, 1295);

    CelestialMods_SpawnWithCutscene(play, ACTOR_DOOR_ANA, -420, 0, 1340, 0x7, 0x12, 0x7f, 0x307, 18);
    CelestialMods_SpawnWithCutscene(play, ACTOR_DOOR_ANA, -1040, 0, 701, 0x7, 0x13, 0x7f, 0x308, 19);
    break;
  }
}

RECOMP_HOOK_RETURN("Play_Init")
void after_Play_Init(void)
{
  DekuPalace_JpLayout(gPlayState);
}

RECOMP_HOOK_RETURN("Play_Main")
void after_Play_Main(void)
{
  DekuPalace_JpLayout(gPlayState);
}
