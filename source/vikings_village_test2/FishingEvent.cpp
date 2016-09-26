#include "FishingEvent.h"

size_t FishingEvent::success(size_t amount) {
  const size_t DENUMENATOR = 2;
  if (amount < DENUMENATOR) {
    add_resource(RI_FOOD, 1);
  } else {
    add_resource(RI_FOOD, amount / DENUMENATOR);
  }
  return EO_SUCCESS;
}

size_t FishingEvent::normal(size_t amount) {
  const size_t DENUMENATOR = 4;
  if (amount < DENUMENATOR) {
    add_resource(RI_FOOD, 1);
  } else {
    add_resource(RI_FOOD, amount / DENUMENATOR);
  }
  return EO_NORMAL;
}

size_t FishingEvent::failure(size_t amount) {
  add_resource(RI_FOOD, 0);
  return EO_FAILURE;
}

size_t FishingEvent::execute() {
  srand(static_cast<unsigned int>(time(0)));
  size_t outcome = EO_SIZE;
  if (!_raid_participants.empty()) {
  	size_t index = _raid_participants.size();
	while (true) {
	  index = rand() % _raid_participants.size();
	  if (_raid_participants[index] != NULL) {
        break;
	  }
	}
    size_t ranged_skill = SIZE_T_DEFAULT_VALUE;
    get_combat_stats(SI_RANGED, index, ranged_skill);
    outcome = event_outcome(ranged_skill);
    if (outcome == EO_SUCCESS) {
      success(ranged_skill);
	} else {
	  if (outcome == EO_NORMAL) {
	    normal(ranged_skill);
	  } else {
	    failure(ranged_skill);
	  }
	}
  }
  return outcome;
}

