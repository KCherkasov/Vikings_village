#include "CaravanEvent.h"

size_t CaravanEvent::success() {
  srand(static_cast<unsigned int>(time(0)));
  const size_t ELEMS_COUNT = 4;
  // following consts may be tweaked to change game mechanics
  const size_t SLAVE_CHANCE = 15;
  const size_t ITEM_CHANCE = 48;
  const size_t RESOURCE_AMOUNT = 10;
  const size_t MORALE_BOOST = 10;
  for (size_t i = 0; i < ELEMS_COUNT; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= SLAVE_CHANCE) {
      add_slave();
    } else {
      if (roll <= ITEM_CHANCE) {
        add_random_item();
      } else {
        size_t amount = rand() % RESOURCE_AMOUNT + 1;
        add_random_resource(amount);
      }
    }
  }
  increase_misc_stat(MI_MORALE, MORALE_BOOST);
  return EO_SUCCESS;
}

size_t CaravanEvent::normal() {
  srand(static_cast<unsigned int>(time(0)));
  const size_t ELEMS_COUNT = 2;
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
        add_random_item();
      } else {
        size_t amount = rand() % RESOURCE_AMOUNT + 1;
        add_random_resource(amount);
      }
    }
  }
  return EO_NORMAL;
}

size_t CaravanEvent::failure() {
  srand(static_cast<unsigned int>(time(0)));
  // following consts may be tweaked to change game mechanics
  const size_t MIN_CASUALTIES = 1;
  const size_t MAX_CASUALTIES = 3;
  const size_t MORALE_DEBUFF = 5;
  size_t casualties = rand() % (MAX_CASUALTIES - MIN_CASUALTIES) + MIN_CASUALTIES;
  for (size_t i = 0; i < casualties; ++i) {
    kill_participant();
  }
  decrease_misc_stat(MI_MORALE, MORALE_DEBUFF);
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
