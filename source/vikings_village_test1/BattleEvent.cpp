#include "BattleEvent.h"

size_t BattleEvent::success() {
  return FS_SMALL;
}

size_t BattleEvent::normal() {
  return FS_MEDIUM;
}

size_t BattleEvent::failure() {
  return FS_BIG;
}

size_t BattleEvent::execute() {
  size_t outcome = event_outcome(0);
  Battle* battle = new Battle(_storage, _raid_participants, _raid_slaves, _raid_resources, _raid_loot);
  size_t battle_size = FS_SIZE;
  if (outcome = EO_SUCCESS) {
    battle_size = success();
  } else {
    if (outcome == EO_NORMAL) {
      battle_size = normal();
    } else {
      battle_size = failure();
    }
  }
  battle->generate_enemies(battle_size);
  size_t battle_outcome = battle->play();
  if (battle_outcome == BO_RAIDERS_WON) {
    increase_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    outcome = EO_SUCCESS;
  } else {
    decrease_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    outcome = EO_FAILURE;
  }
  delete battle;
  return outcome;
}

