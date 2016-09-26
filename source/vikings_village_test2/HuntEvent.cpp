#include "HuntEvent.h"

size_t HuntEvent::success() {
  const size_t FOOD_AMOUNT = 20;
  const size_t MORALE_BOOST = 5;
  add_resource(RI_FOOD, FOOD_AMOUNT);
  increase_misc_stat(MI_MORALE, MORALE_BOOST);
  return EO_SUCCESS;
}

size_t HuntEvent::normal() {
  const size_t FOOD_AMOUNT = 10;
  add_resource(RI_FOOD, FOOD_AMOUNT);
  return EO_NORMAL;
}

size_t HuntEvent::failure() {
  const size_t FOOD_AMOUNT = 0;
  add_resource(RI_FOOD, FOOD_AMOUNT);
  return EO_FAILURE;
}

size_t HuntEvent::execute() {
  size_t index = rand() % _raid_participants.size();
  size_t ranged_skill = SIZE_T_DEFAULT_VALUE;
  get_combat_stat(SI_RANGED, ranged_skill);
  size_t outcome = event_outcome(ranged_skill);
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
