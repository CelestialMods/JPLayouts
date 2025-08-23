#pragma once

#define DEFINE_SCENE(name, _enumValue, textId, drawConfig, _restrictionFlags, _persistentCycleFlags) \
  DECLARE_ROM_SEGMENT(name)
#define DEFINE_SCENE_UNSET(_enumValue)

#include "tables/scene_table.h"

#undef DEFINE_SCENE
#undef DEFINE_SCENE_UNSET
