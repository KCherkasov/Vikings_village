#include "RivalEvent.h"

size_t RivalEvent::success() {
  return EO_SUCCESS;
}

size_t RivalEvent::normal() {
  return EO_NORMAL;
}

size_t RivalEvent::failure() {
  return EO_FAILURE;
}

size_t RivalEvent::execute() {
  if (_raid_participants.empty()) {
    return EO_SIZE;
  }
  size_t raid_loyalty = SIZE_T_DEFAULT_VALUE;
  get_misc_stat(MI_LOYALTY, raid_loyalty);
  size_t outcome = event_outcome(raid_loyalty);
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
