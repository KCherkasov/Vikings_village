#include "StormEvent.h"

size_t StormEvent::success() {
  const size_t PERCENTS = 3;
  const size_t ROUNDS_COUNT = 1;
  for (size_t i = 0; i < ROUNDS_COUNT; ++i) {
    remove_random_resource_percent(PERCENTS);
  }
  return EO_SUCCESS;
}

size_t StormEvent::normal() {
  const size_t PERCENTS = 7;
  const size_t ROUNDS_COUNT = 2;
  const size_t CASUALTIES = 1;
  for (size_t i = 0; i < ROUNDS_COUNT; ++i) {
    remove_random_resource_percent(PERCENTS);
  }
  for (size_t i = 0; i < CASUALTIES; ++i) {
    kill_random_human();
  }
  return EO_NORMAL;
}

size_t StormEvent::failure() {
  const size_t PERCENTS = 15;
  const size_t ROUNDS_COUNT = 3; 
  const size_t CASUALTIES = 2;
  for (size_t i = 0; i < ROUNDS_COUNT; ++i) {
    remove_random_resource_percent(PERCENTS);
  }
  for (size_t i = 0; i < CASUALTIES; ++i) {
    kill_random_human();
  }
  return EO_FAILURE;
}

size_t StormEvent::execute() {
  size_t average_sailorship = SIZE_T_DEFAULT_VALUE;
  get_misc_stats(MI_SAILORSHIP, average_sailorship);
  size_t outcome = event_outcome(average_sailorship);
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
