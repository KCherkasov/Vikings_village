#include "StolenTrophiesEvent.h"

size_t StolenTrophiesEvent::success() {
  return EO_SUCCESS;
}

size_t StolenTrophiesEvent::normal() {
  srand(static_cast<unsigned int>(time(0)));
  // following consts may be tweaked to change game mechanics
  const size_t THINGS_STOLEN = 1;
  const size_t RESOURCES_STACK = 10;
  const size_t ITEM_CHANCE = 20;
  for (size_t i = 0; i < THINGS_STOLEN; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= ITEM_CHANCE) {
      destroy_random_item();
    } else {
      remove_random_resource(RESOURCES_STACK);
    }
  }
  return EO_NORMAL;
}

size_t StolenTrophiesEvent::failure() {
  srand(static_cast<unsigned int>(time(0)));
  // following consts may be tweaked to change game mechanics
  const size_t THINGS_STOLEN = 3;
  const size_t RESOURCES_STACK = 10;
  const size_t ITEM_CHANCE = 20;
  for (size_t i = 0; i < THINGS_STOLEN; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= ITEM_CHANCE) {
      destroy_random_item();
    } else {
      remove_random_resource(RESOURCES_STACK);
    }
  }
  return EO_FAILURE;
}

size_t StolenTrophiesEvent::execute() {
  size_t outcome = event_outcome(0); // review later
  if (outcome == EO_SUCCESS) {
    success();
  } else {
    if (outcome == EO_NORMAL) {
      normal();
    } else {
      failure();
    }
  }
  return outcome;
}
