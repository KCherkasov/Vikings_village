#include "DeathEvent.h"

size_t DeathEvent::success() {
  const size_t DEATHS = 0;
  for (size_t i = 0; i < DEATHS; ++i) {
    kill_random_human();
  }
  return EO_SUCCESS;
}

size_t DeathEvent::normal() {
  const size_t DEATHS = 1;
  for (size_t i = 0; i < DEATHS; ++i) {
    kill_random_human();
  }
  return EO_NORMAL;
}

size_t DeathEvent::failure() {
  const size_t DEATHS = 1;
  for (size_t i = 0; i < DEATHS; ++i) {
    kill_random_human();
  }
  return EO_FAILURE;
}

size_t DeathEvent::execute() {
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

