#include "AmbushEvent.h"

size_t AmbushEvent::success() {
  srand(static_cast<unsigned int>(time(0)));
  // following consts may be tweaked to change game mechanics
  const size_t MORALE_BOOST = 15;
  const size_t MIN_SLAVES = 3;
  const size_t MAX_SLAVES = 5;
  const size_t ITEM_CHANCE = 30;
  const size_t OTHER_TROPHIES = 4;
  size_t slaves_count = rand() % (MAX_SLAVES - MIN_SLAVES) + MIN_SLAVES;
  for (size_t i = 0; i < slaves_count; ++i) {
    add_slave();
  }
  for (size_t i = 0; i < OTHER_TROPHIES; ++i) {
    size_t roll;
    roll_dice(roll);
    if (roll < ITEM_CHANCE) {
      add_random_item();
    } else {
      add_random_resource();
    }
  }
  return EO_SUCCESS;
}

size_t AmbushEvent::normal() {
  Battle* battle = new Battle(_storage, _raid_participants, _raid_slaves, _raid_resources, _raid_loot);
  battle->generate_enemies(FS_SMALL);
  size_t battle_outcome = battle->play();
  delete battle;
  if (battle_outcome == BO_RAIDERS_WON) {
    increase_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    return EO_SUCCESS;
  } else {
    decrease_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    return EO_FAILURE;
  }
}

size_t AmbushEvent::failure() {
  Battle* battle = new Battle(_storage, _raid_participants, _raid_slaves, _raid_resources, _raid_loot);
  battle->generate_enemies(FS_MEDIUM);
  size_t battle_outcome = battle->play();
  delete battle;
  if (battle_outcome == BO_RAIDERS_WON) {
    increase_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    return EO_SUCCESS;
  } else {
    decrease_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    return EO_FAILURE;
  }
}

size_t AmbushEvent::execute() {
  size_t outcome = event_outcome(0);
  if (outcome == EO_SUCCESS) {
    success();
  } else {
    if (outcome == EO_NORMAL) {
      outcome = normal();
    } else {
      outcome = failure();
    }
  }
  return outcome;
}

