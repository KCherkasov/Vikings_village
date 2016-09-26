#include "DiseaseEvent.h"

size_t DiseaseEvent::success() {
  const size_t CASUALTIES = 0;
  for (size_t i = 0; i < CASUALTIES; ++i) {
    kill_random_human();
  }
  return EO_SUCCESS;
}

size_t DiseaseEvent::normal() {
  const size_t CASUALTIES = 1;
  for (size_t i = 0; i < CASUALTIES; ++i) {
    kill_random_human();
  }
  return EO_NORMAL;
}

size_t DiseaseEvent::failure() {
  const size_t CASUALTIES = 3;
  for (size_t i = 0; i < CASUALTIES; ++i) {
    kill_random_human();
  }
  return EO_FAILURE;
}

size_t DiseaseEvent::execute() {
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
}
