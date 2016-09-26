#include "FallenOutEvent.h"

size_t FallenOutEvent::success() {
  const size_t CASUALTIES = 0;
  for (size_t i = 0; i < CASUALTIES; ++i) {
    kill_random_human();
  }
  return EO_SUCCESS;
}

size_t FallenOutEvent::normal() {
  const size_t CASUALTIES = 1;
  for (size_t i = 0; i < CASUALTIES; ++i) {
    kill_random_human();
  }
  return EO_NORMAL;
}

size_t FallenOutEvent::failure() {
  const size_t CASUALTIES = 2;
  for (size_t i = 0; i < CASUALTIES; ++i) {
    kill_random_human();
  }
  return EO_FAILURE;
}

size_t FallenOutEvent::execute() {
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

