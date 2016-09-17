#include "GiftsEvent.h"

size_t GiftsEvent::success() {
  // following consts may be tweaked to change game mechanics
  const size_t GIFTS_COUNT = 5;
  const size_t ITEM_CHANCE = 30;
  for (size_t i = 0; i < GIFTS_COUNT; ++i) {
    size_t roll;
    roll_dice(roll);
    if (roll <= GIFTS_COUNT) {
      add_random_item();
    } else {
      add_random_resource();
    }
  }
  return EO_SUCCESS;
}

size_t GiftsEvent::normal() {
  // following consts may be tweaked to change game mechanics
  const size_t GIFTS_COUNT = 3;
  const size_t ITEM_CHANCE = 30;
  for (size_t i = 0; i < GIFTS_COUNT; ++i) {
    size_t roll;
    roll_dice(roll);
    if (roll <= GIFTS_COUNT) {
      add_random_item();
    } else {
      add_random_resource();
    }
  }
  return EO_NORMAL;
}

size_t GiftsEvent::failure() {
  // following consts may be tweaked to change game mechanics
  const size_t GIFTS_COUNT = 1;
  const size_t ITEM_CHANCE = 30;
  for (size_t i = 0; i < GIFTS_COUNT; ++i) {
    size_t roll;
    roll_dice(roll);
    if (roll <= GIFTS_COUNT) {
      add_random_item();
    } else {
      add_random_resource();
    }
  }
  return EO_FAILURE;
}

size_t GiftsEvent::execute() {
  size_t outcome = event_outcome(0);
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

