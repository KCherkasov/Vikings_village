#include "RottenFoodEvent.h"

size_t RottenFoodEvent::success() {
  const size_t LOST_FOOD = 0;
  remove_resource(RI_FOOD, LOST_FOOD);
  return EO_SUCCESS;
}

size_t RottenFoodEvent::normal() {
  const size_t LOST_FOOD = 5;
  remove_resource(RI_FOOD, LOST_FOOD);
  return EO_NORMAL;
}

size_t RottenFoodEvent::failure {
  const size_t LOST_FOOD = 10;
  remove_resource(RI_FOOD, LOST_FOOD);
  return EO_FAILURE;
}

size_t RottenFoodEvent::execute() {
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
