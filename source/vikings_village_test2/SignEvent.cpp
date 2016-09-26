#include "SignEvent.h"

size_t SignEvent::success() {
  const size_t MORALE_CHANGE = 10;
  increase_misc_stat(MI_MORALE, MORALE_CHANGE);
  return EO_SUCCESS;
}

size_t SignEvent::normal() {
  const size_t MORALE_CHANGE = 0;
  increase_misc_stat(MI_MORALE, MORALE_CHANGE);
  return EO_NORMAL;
}

size_t SignEvent::failure() {
  const size_t MORALE_CHANGE = 10;
  decrease_misc_stat(MI_MORALE, MORALE_CHANGE);
  return EO_FAILURE;
}

size_t SignEvent::execute() {
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
