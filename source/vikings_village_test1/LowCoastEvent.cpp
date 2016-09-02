#include "LowCoastEvent.h"

size_t LowCoastEvent::success() {
  const size_t SLOW_DOWN = 0;
  increase_phase_duration(SLOW_DOWN);
  return EO_SUCCESS;
}

size_t LowCoastEvent::normal() {
  const size_t SLOW_DOWN = 1;
  const size_t PERCENTS = 3;
  const size_t ROUNDS = 1;
  increase_phase_duration(SLOW_DOWN);
  for (size_t i = 0; i < ROUNDS; ++i) {
    remove_random_resource_percent(PERCENTS);
  }
  return EO_NORMAL;
}

size_t LowCoastEvent::failure() {
  const size_t SLOW_DOWN = 3;
  const size_t PERCENTS_REST = 90;
  const size_t ROUNDS = 2;
  increase_phase_duration(SLOW_DOWN);
  for (size_t i = 0; i < ROUNDS; ++i) {
    remove_random_resource_percent(PERCENTS);
  }
  return EO_FAILURE;
}

size_t LowCoastEvent::execute() {
  size_t average_sailorship = SIZE_T_DEFAULT_VALUE;
  get_misc_stats(MI_SAILORSHIP, average_sailorship);
  size_t outcome = event_outcome(average_sailorship);
  if (outcome == EO_SUCCESS) {
    success();
  } else{
    if (outcome == EO_NORMAL) {
      normal();
	} else {
	  failure();
	}
  }
  return outcome;
}

