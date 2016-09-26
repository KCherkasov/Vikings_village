#include "CelebrationEvent.h"

size_t CelebrationEvent::success() {
  srand(static_cast<unsigned int>(time(0)));
  const size_t CASUALTIES_LOW = 0;
  const size_t CASUALTIES_HIGH = 0;
  const size_t MORALE_BOOST = 15;
  size_t casualties = SIZE_T_DEFAULT_VALUE;
  if (CASUALTIES_HIGH > CASUALTIES_LOW) {
    casualties = rand() % (CASUALTIES_HIGH - CASUALTIES_LOW) + CASUALTIES_LOW;
  }
  for (size_t i = 0; i < casualties; ++i) {
    kill_random_human();
  }
  increase_misc_stat(MI_MORALE, MORALE_BOOST);
  return EO_SUCCESS;
}

size_t CelebrationEvent::normal() {
  srand(static_cast<unsigned int>(time(0)));
  const size_t CASUALTIES_LOW = 0;
  const size_t CASUALTIES_HIGH = 0;
  const size_t MORALE_BOOST = 10;
  size_t casualties = SIZE_T_DEFAULT_VALUE;
  if (CASUALTIES_HIGH > CASUALTIES_LOW) {
    casualties = rand() % (CASUALTIES_HIGH - CASUALTIES_LOW) + CASUALTIES_LOW;
  }
  for (size_t i = 0; i < casualties; ++i) {
    kill_random_human();
  }
  increase_misc_stat(MI_MORALE, MORALE_BOOST);
  return EO_NORMAL;
}

size_t CelebrationEvent::failure() {
  srand(static_cast<unsigned int>(time(0)));
  const size_t CASUALTIES_LOW = 1;
  const size_t CASUALTIES_HIGH = 3;
  const size_t MORALE_BOOST = 5;
  size_t casualties = SIZE_T_DEFAULT_VALUE;
  if (CASUALTIES_HIGH > CASUALTIES_LOW) {
    casualties = rand() % (CASUALTIES_HIGH - CASUALTIES_LOW) + CASUALTIES_LOW;
  }
  for (size_t i = 0; i < casualties; ++i) {
    kill_random_human();
  }
  increase_misc_stat(MI_MORALE, MORALE_BOOST);
  return EO_FAILURE;
}

size_t CelebrationEvent::execute() {
  const size_t FOOD_CONSUMED = 10;
  if (_raid_resources.empty()) {
    return EO_SIZE;
  }
  if (_raid_resources[RI_FOOD] < FOOD_CONSUMED) {
  	return EO_SIZE;
  }
  remove_resource(RI_FOOD, FOOD_CONSUMED);
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

