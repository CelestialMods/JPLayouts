#include "global.h"
#include "global_variables.h"
#include "segmented_address.h"
#include "recomputils.h"

#define DEFINE_SCENE(name, _enumValue, textId, drawConfig, _restrictionFlags, _persistentCycleFlags) \
  DECLARE_ROM_SEGMENT(name)
#define DEFINE_SCENE_UNSET(_enumValue)

#include "tables/scene_table.h"

#undef DEFINE_SCENE
#undef DEFINE_SCENE_UNSET

extern Vtx Z2_30GYOSON_room_00Vtx_012038[];
extern Vtx Z2_30GYOSON_room_00Vtx_012BC8[];
extern Vec3s Z2_30GYOSONCollisionHeader_0093F4Vertices[];
extern u16 Z2_30GYOSONCollisionHeader_0093F4Polygons[];

RoomContext *gRoomCtx;
s8 gRoomStatus;

RECOMP_HOOK("Room_ProcessRoomRequest")
void on_process_room_request(PlayState *play, RoomContext *roomCtx)
{
  gRoomCtx = roomCtx;
  gRoomStatus = roomCtx->status;
}

RECOMP_HOOK_RETURN("Room_ProcessRoomRequest")
void after_process_room_request()
{
  if (gRoomCtx->status == 0 && gRoomStatus == 1)
  {
    if (gPlayState->sceneId == SCENE_30GYOSON && gRoomCtx->curRoom.num == 0)
    {
      Vtx *vtxToReplace = (Vtx *)Lib_SegmentedToVirtual(Z2_30GYOSON_room_00Vtx_012038);
      for (u16 i = 0; i < 44; i++)
      {
        vtxToReplace[i].n.ob[1] += 25;
      }
      vtxToReplace = (Vtx *)Lib_SegmentedToVirtual(Z2_30GYOSON_room_00Vtx_012BC8);
      for (u16 i = 0; i < 4; i++)
      {
        vtxToReplace[i].n.ob[1] += 25;
      }
      Vec3s *vecToReplace = (Vec3s *)Lib_SegmentedToVirtual(Z2_30GYOSONCollisionHeader_0093F4Vertices);
      for (u16 i = 0; i < 8; i++)
      {
        vecToReplace[558 + i].y += 25;
      }
      u16 *collisionPolyToReplace = (u16 *)Lib_SegmentedToVirtual(Z2_30GYOSONCollisionHeader_0093F4Polygons);

      collisionPolyToReplace[0x187f] = -40;
      collisionPolyToReplace[0x1887] = -40;
      collisionPolyToReplace[0x18af] = -20;
      collisionPolyToReplace[0x18b7] = -20;
    }
  }
}

RECOMP_CALLBACK("*", recomp_after_actor_init)
void GreatBayCoast_AfterActorInit(PlayState *play, Actor *actor)
{
  if (gPlayState->sceneId == SCENE_30GYOSON && gPlayState->roomCtx.curRoom.num == 0)
    if (actor->id == ACTOR_OBJ_WARPSTONE)
    {
      actor->world.pos.y += 25;
      actor->home.pos.y += 25;
    }
}
