#include "global.h"

const char *actor_to_string(Actor *actor) {
  if (actor == NULL) {
    return "NULL";
  }
  switch (actor->id) {

#define DEFINE_ACTOR(_name, enumValue, _allocType, debugName)                  \
  case enumValue:                                                              \
    return #debugName;
#define DEFINE_ACTOR_INTERNAL(_name, enumValue, _allocType, debugName)         \
  case enumValue:                                                              \
    return #debugName;
#define DEFINE_ACTOR_UNSET(enumValue)                                          \
  case enumValue:                                                              \
    return "";

#include "tables/actor_table.h"

#undef DEFINE_ACTOR
#undef DEFINE_ACTOR_INTERNAL
#undef DEFINE_ACTOR_UNSET

  default:
    return "Unknown";
  }
}
