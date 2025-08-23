#include "global_variables.h"
#include "modding.h"

PlayState* gPlayState;
s8 current_room;
RoomContext *gRoomCtx;
s8 gRoomStatus;

RECOMP_HOOK("Play_Init")
void global_Play_Init(PlayState *play)
{
  gPlayState = play;
  current_room = -1;
}

RECOMP_HOOK("Room_ProcessRoomRequest")
void GreatBayCoast_ProcessRoomRequest(PlayState *play, RoomContext *roomCtx)
{
  gRoomCtx = roomCtx;
  gRoomStatus = roomCtx->status;
}
