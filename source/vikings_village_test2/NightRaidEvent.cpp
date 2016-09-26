#include "NightRaidEvent.h"

size_t NightRaidEvent::success() {
  const size_t TROPHIES_COUNT = 6;
  const size_t SLAVE_CHANCE = 15;
  const size_t ITEM_CHANCE = 40;
  for (size_t i = 0; i < TROPHIES_COUNT; ++i) {
    size_t roll;
    roll_dice(roll);
    if (roll < SLAVE_CHANCE) {
      add_slave();
    } else {
      if (roll < ITEM_CHANCE) {
        add_random_item();
      } else {
        add_random_resource();
      }
    }
  }
  return EO_SUCCESS;
}

size_t NightRaidEvent::normal() {
  const size_t TROPHIES_COUNT = 3;
  const size_t SLAVE_CHANCE =  15;
  const size_t ITEM_CHANCE = 40;
  Battle* battle = new Battle(_storage, _raid_participants, _raid_slaves, _raid_resources, _raid_loot);
  battle->generate_enemies(FS_SMALL);
  size_t battle_outcome = battle->play();
  delete battle;
  if (battle_outcome == BO_RAIDERS_WON) {
    for (size_t i = 0; i < TROPHIES_COUNT; ++i) {
      size_t roll;
      roll_dice(roll);
      if (roll < SLAVE_CHANCE) {
        add_slave();
      } else {
        if (roll < ITEM_CHANCE) {
          add_random_item();
        } else {
          add_random_resource();
        }
      }
    }
    increase_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    return EO_SUCCESS;
  } else {
    decrease_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    return EO_FAILURE;
  }
}

size_t NightRaidEvent::failure() {
  const size_t TROPHIES_COUNT = 3;
  const size_t SLAVE_CHANCE = 15;
  const size_t ITEM_CHANCE = 40;
  Battle* battle = new Battle(_storage, _raid_participants, _raid_slaves, _raid_resources, _raid_loot);
  battle->generate_enemies(FS_MEDIUM);
  size_t battle_outcome = battle->play();
  delete battle;
  if (battle_outcome == BO_RAIDERS_WON) {
    for (size_t i = 0; i < TROPHIES_COUNT; ++i) {
      size_t roll;
      roll_dice(roll);
      if (roll < SLAVE_CHANCE) {
        add_slave();
      } else {
        if (roll < ITEM_CHANCE) {
          add_random_item();
        } else {
          add_random_resource();
        }
      }
    }
    increase_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    return EO_SUCCESS;
  } else {
    decrease_misc_stat(MI_MORALE, BATTLE_MORALE_BOOST);
    return EO_FAILURE;
  }
}

size_t NightRaidEvent::execute() {
  size_t outcome = event_outcome(0);
  if (outcome == EO_SUCCESS) {
    outcome = success();
  } else {
    if (outcome == EO_NORMAL) {
      outcome = normal();
    } else {
      outcome = failure();
    }
  }
  return outcome;
}
