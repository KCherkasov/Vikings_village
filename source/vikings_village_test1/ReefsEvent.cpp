#include "ReefsEvent.h"

size_t ReefsEvent::success() {
  const size_t SLOW_DOWN = 1;
  increase_phase_duration(SLOW_DOWN);
  return EO_SUCCESS;
}

size_t ReefsEvent::normal() {
  const size_t SLOW_DOWN = 2;
  const size_t PERCENTS= 5;
  const size_t ROUNDS = 1;
  increase_phase_duration(SLOW_DOWN);
  for (size_t i = 0; i < ROUNDS; ++i) {
    remove_random_resource_percent(PERCENTS);
  }
  return EO_NORMAL;
}

size_t ReefsEvent::failure() {
  const size_t SLOW_DOWN = 4;
  const size_t PERCENTS_REST = 88;
  const size_t ROUNDS = 2;
  increase_phase_duration(SLOW_DOWN);
  for (size_t i = 0; i < ROUNDS; ++i) {
    remove_random_resource_percent(PERCENTS);
  }
  return EO_FAILURE;
}

size_t ReefsEvent::execute() {
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

