#include "global.h"
#include "modding.h"
#include "recomputils.h"

PlayState *sPlay;
SceneCmd *sCmd;

RECOMP_HOOK("Scene_CommandSpawnList")
void on_Scene_CommandSpawnList(PlayState *play, SceneCmd *cmd)
{
  sPlay = play;
  sCmd = cmd;
}

RECOMP_HOOK_RETURN("Scene_CommandSpawnList")
void after_Scene_CommandSpawnList(void)
{
  if(gSaveContext.gameMode != GAMEMODE_NORMAL)
    return;
  PlayState *play = sPlay;
  SceneCmd *cmd = sCmd;
  if (play->sceneId != SCENE_22DEKUCITY)
    return;
  if (play->curSpawn != 9)
    return;

  Vec3s pos = {450, 80, 784};
  Vec3s rot = {7, 0, 127};

  play->linkActorEntry->pos = pos;
  play->linkActorEntry->rot = rot;
}
