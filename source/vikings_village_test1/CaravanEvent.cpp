#include "CaravanEvent.h"

size_t CaravanEvent::success() {
  srand(static_cast<unsigned int>(time(0)));
  const size_t ELEMS_COUNT = 4;
  // following consts may be tweaked to change game mechanics
  const size_t SLAVE_CHANCE = 15;
  const size_t ITEM_CHANCE = 48;
  const size_t RESOURCE_AMOUNT = 10;
  for (size_t i = 0; i < ELEMS_COUNT; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= SLAVE_CHANCE) {
      add_slave();
    } else {
      if (roll <= ITEM_CHANCE) {
        add_item();
      } else {
        size_t amount = rand() % RESOURCE_AMOUNT + 1;
        add_random_resource(amount);
  }
  return EO_SUCCESS;
}

size_t CaravanEvent::normal() {
  srand(static_cast<unsigned int>(time(0)));
  const size_t ELEMS_COUNT = 2;
  // following consts may be tweaked to change game mechanics
  const size_t SLAVE_CHANCE = 15;
  const size_t ITEM_CHANCE = 48;
  const size_t RESOURCE_AMOUNT = 5;
  for (size_t i = 0; i < ELEMS_COUNT; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= SLAVE_CHANCE) {
      add_slave();
    } else {
      if (roll <= ITEM_CHANCE) {
        add_item();
      } else {
        size_t amount = rand() % RESOURCE_AMOUNT + 1;
        add_random_resource(amount);
  }
  return EO_NORMAL;
}

size_t CaravanEvent::failure() {
  srand(static_cast<unsigned int>(time(0)));
  const size_t ELEMS_COUNT = 1;
  // following consts may be tweaked to change game mechanics
  const size_t SLAVE_CHANCE = 15;
  const size_t ITEM_CHANCE = 48;
  const size_t RESOURCE_AMOUNT = 2;
  for (size_t i = 0; i < ELEMS_COUNT; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= SLAVE_CHANCE) {
      add_slave();
    } else {
      if (roll <= ITEM_CHANCE) {
        add_item();
      } else {
        size_t amount = rand() % RESOURCE_AMOUNT + 1;
        add_random_resource(amount);
  }
  return EO_FAILURE;
}

size_t CaravanEvent::execute() {
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
