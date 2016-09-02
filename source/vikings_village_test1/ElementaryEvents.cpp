#include "ElemantaryEvents.h"

size_t event_outcome(size_t difficulty, size_t stat) {
  srand(static_cast<unsigned int>(time(0)));
  size_t roll = rand() % MAX_STAT_VALUE;
  if (roll + stat >= difficulty) {
    if (roll + stat - difficulty > SUCCESS_FAIL_RANGE) {
      return EO_SUCCESS;
	} else {
      return EO_NORMAL;
	}
  } else {
    if (difficulty - roll - stat <= SUCCESS_FAIL_RANGE) {
      return EO_NORMAL;
	} else {
      return EO_FAILURE;
	}
  }
  return EO_SIZE;
}

size_t add_random_item(std::vector<Item*>& target, IngameStorage& storage, size_t owner_id) {
  if (storage.get_items_count() > 0) {
    srand(static_cast<unsigned int>(time(0)));
    size_t item_id = rand() % storage.get_items_count();
    Item* to_add = new Item(storage.get_item_table(item_id), storage.get_item_table(index)._quality, owner_id);
    target.push_back(to_add);
    to_add = NULL;
  }
  return 0;
}

size_t destroy_random_item(std::vector<Item*>& target) {
  if (!target.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
      size_t index = rand() % target.size();
      if (target[index] != NULL) {
        break;
	  }
	}
	delete target[index];
	target.erase(target.begin() + index);
  }
  return 0;
}

size_t add_random_resource(std::vector<size_t>& target) {
  if (!target.empty()) {
  	srand(static_cast<unsigned int>(time(0)));
  	size_t index = rand() % target.size();
  	size_t amount = rand() % (MAX_STAT_VALUE / 5);
  	target[index] += amount;
  }
  return 0;
}

size_t add_random_resource(std::vector<size_t>& target, size_t amount) {
  if (!target.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    size_t index = rand() % target.size();
    target[index] += amount;
  }
  return 0;
}

size_t remove_random_resource(std::vector<size_t>& target) {
  if (!target.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    size_t index = rand() % target.size();
    size_t amount = rand() % (MAX_STAT_VALUE / 5);
    if (target[index] >= amount) {
	  target[index] -= amount;
    } else {
      target[index] = SIZE_T_DEFAULT_VALUE;
	}
  }
  return 0;
}

size_t remove_random_resource(std::vector<size_t>& target, size_t amount) {
  if (!target.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    size_t index = rand() % target.size();
    if (target[index] >= amount) {
      target[index] -= amount;
	} else {
      target[index] = SIZE_T_DEFAULT_VALUE;
	}
  }
  return 0;
}

size_t add_resource(size_t& target) {
  srand(static_cast<unsigned int>(time(0)));
  size_t amount = rand() % (MAX_STAT_VALUE / 4);
  target += amount;
  return 0;
}

size_t add_resource(size_t& target, size_t amount) {
  target += amount;
  return 0;
}

size_t remove_resource(size_t& target) {
  srand(static_cast<unsigned int>(time(0)));
  size_t amount = rand() % (MAX_STAT_VALUE / 5);
  if (target >= amount) {
    target -= amount;
  } else {
    target = SIZE_T_DEFAULT_VALUE;
  }
  return 0;
}

size_t remove_resource(size_t& target, size_t amount) {
  if (target >= amount) {
    target -= amount;
  } else {
    target = SIZE_T_DEFAULT_VALUE;
  }
  return 0;
}

size_t add_random_human(std::vector<Human*>& target, TypeProfession& profession, bool is_slave) {
  srand(static_cast<unsigned int>(time(0)));
  bool gender = FEMALE_GENDER;
  size_t roll = rand() % MAX_STAT_VALUE;
  if (roll % 2 == 0) {
    gender = MALE_GENDER;
  }
  Human* to_add = new Human()
  return 0;
}
