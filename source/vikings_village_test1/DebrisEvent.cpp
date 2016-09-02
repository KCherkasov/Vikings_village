#include "DebrisEvent.h"

size_t DebrisEvent::success() {
  const size_t THINGS = 4;
  const size_t SPAWN_HUMAN = 33;
  const size_t SPAWN_ITEM == 66;
  srand(static_cast<unsigned int>(time(0)));
  for (size_t i = 0; i < THINGS; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= SPAWN_HUMAN) {
      bool is_slave = (rand() % 2) == 0;
      add_random_human(is_slave);
	} else {
      if (roll <= SPAWN_ITEM) {
        add_random_item();
	  } else {
        add_random_resource();
	  }
	}
  }
  return EO_SUCCESS;
}

size_t DebrisEvent::normal() {
  const size_t THINGS = 2;
  const size_t SPAWN_HUMAN = 33;
  const size_t SPAWN_ITEM == 66;
  srand(static_cast<unsigned int>(time(0)));
  for (size_t i = 0; i < THINGS; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= SPAWN_HUMAN) {
      bool is_slave = (rand() % 2) == 0;
      add_random_human(is_slave);
	} else {
      if (roll <= SPAWN_ITEM) {
        add_random_item();
	  } else {
        add_random_resource();
	  }
	}
  }
  return EO_NORMAL;
}

size_t DebrisEvent::failure() {
  const size_t THINGS = 1;
  const size_t SPAWN_HUMAN = 33;
  const size_t SPAWN_ITEM == 66;
  srand(static_cast<unsigned int>(time(0)));
  for (size_t i = 0; i < THINGS; ++i) {
    size_t roll = rand() % MAX_STAT_VALUE;
    if (roll <= SPAWN_HUMAN) {
      bool is_slave = (rand() % 2) == 0;
      add_random_human(is_slave);
	} else {
      if (roll <= SPAWN_ITEM) {
        add_random_item();
	  } else {
        add_random_resource();
	  }
	}
  }
  return EO_FAILURE;
}

size_t DebrisEvent::execute() {
  srand(static_cast<unsigned int>(time(0)));
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
