#include "WrongRouteEvent.h"

size_t WrongRouteEvent::success() {
  const size_t SLOW_DOWN = 1;
  increase_phase_duration(SLOW_DOWN);
  return EO_SUCCESS;
}

size_t WrongRouteEvent::normal() {
  const size_t SLOW_DOWN = 2;
  increase_phase_duration(SLOW_DOWN);
  return EO_NORMAL;
}

size_t WrongRouteEvent::failure() {
  const size_t SLOW_DOWN = 4;
  increase_phase_duration(SLOW_DOWN);
  return EO_FAILURE;
}

size_t WrongRouteEvent::execute() {
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

