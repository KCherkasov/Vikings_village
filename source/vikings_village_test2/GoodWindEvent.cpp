#include "GoodWindEvent.h"

size_t GoodWindEvent::success() {
  const size_t BOOST = 3;
  decrease_phase_duration(BOOST);
  return EO_SUCCESS;
}

size_t GoodWindEvent::normal() {
  const size_t BOOST = 2;
  decrease_phase_duration(BOOST);
  return EO_NORMAL;
}

size_t GoodWindEvent::failure() {
  const size_t BOOST = 1;
  decrease_phase_duration(BOOST);
  return EO_FAILURE;
}

size_t GoodWindEvent::execute() {
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

