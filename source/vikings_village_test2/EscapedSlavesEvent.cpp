#include "EscapedSlavesEvent.h"

size_t EscapedSlavesEvent::success() {
  return EO_SUCCESS;
}

size_t EscapedSlavesEvent::normal() {
  // following constants may be tweaked to change game mechanics
  const size_t ESCAPED_PERCENTAGE = 10;
  size_t escaped_count = _raid_slaves.size() * MAX_STAT_VALUE / ESCAPED_PERCENTAGE;
  for (size_t i = 0; i < escaped_count; ++i) {
    kill_slave();
  }
  return EO_NORMAL;
}

size_t EscapedSlavesEvent::failure() {
  // following constants may be tweaked to change game mechanics
  const size_t ESCAPED_PERCENTAGE = 20;
  size_t escaped_count = _raid_slaves.size() * MAX_STAT_VALUE / ESCAPED_PERCENTAGE;
  for (size_t i = 0; i < escaped_count; ++i) {
    kill_slave();
  }
  return EO_FAILURE;
}

size_t EscapedSlavesEvent::execute() {
  size_t  outcome = event_outcome(0); // review later
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
