#include "RaidEvent.h"

RaidEvent::RaidEvent(IngameStorage& storage, std::string name, std::vector<std::string> descriptions, size_t& raid_turns, std::vector<size_t>& raid_resources, std::vector<Human*>& raid_participants, std::vector<Human*>& raid_slaves, std::vector<Item*>& raid_loot): _storage(storage), _name(name), _descriptions(descriptions), _raid_turns(raid_turns), _raid_resources(raid_resources), _raid_participants(raid_participants), _raid_slaves(raid_slaves), _raid_loot(raid_loot) {}

RaidEvent::~RaidEvent() {}

size_t RaidEvent::get_name(std::string& result) {
  result = _name;
  return 0;
}

size_t RaidEvent::get_descriptions(std::vector<std::string>& result) {
  result = _descriptions;
  return 0;
}

size_t RaidEvent::get_descriptions(size_t index, std::string& result) {
  return 0;
}

size_t RaidEvent::set_name(std::string value) {
  _name = value;
  return 0;
}

size_t RaidEvent::set_description(std::string value) {
  _description = value;
  return 0;
}

size_t RaidEvent::get_combat_stats(size_t index, size_t human_id, size_t& result) {
  result = SIZE_T_DEFAULT_VALUE;
  if (human_id < _raid_participants.size()) {
    if (_raid_participants[human_id] != NULL) {
      _raid_participants[human_id]->get_combat_stats(true, index, result);
	}
  }
  return 0;
}

size_t RaidEvent::get_combat_stats(size_t human_id, std::vector<size_t>& result) {
  result.clear();
  result.resize(SI_SIZE);
  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = SIZE_T_DEFAULT_VALUE;
  }
  if (human_id < _raid_participants.size()) {
    if (_raid_participants[human_id] != NULL) {
      _raid_participants[human_id]->get_combat_stats(true, result);
	}
  }
  return 0;
}

size_t RaidEvent::get_combat_stats(size_t index, size_t& result) {
  result = SIZE_T_DEFAULT_VALUE;
  if (!_raid_participants.empty()) {
    for (size_t i = 0; i < _raid_participants.size(); ++i) {
      if (_raid_participants[i] != NULL) {
        size_t stat = SIZE_T_DEFAULT_VALUE;
        _raid_participants[i]->get_combat_stats(true, index, stat);
        result += stat;
	  }
	}
	result /= _raid_participants.size();
  }
  return 0;
}

size_t RaidEvent::get_combat_stats(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result.resize(SI_SIZE);
  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = SIZE_T_DEFAULT_VALUE;
  }
  if (!_raid_participants.empty()) {
    for (size_t i = 0; i < _raid_participants.size(); ++i) {
      if (_raid_participants[i] != NULL) {
        std::vector<size_t> stats;
        _raid_participants[i]->get_combat_stats(stats);
        if (stats.size() == result.size()) {
          for (size_t j = 0; j < result.size(); ++j) {
            result[j] += stats[j];
		  }
		}
	  }
	}
	for (size_t i = 0; i < result.size(); ++i) {
      result[i] /= _raid_participants.size();
	}
  }
  return 0;
}

size_t RaidEvent::get_misc_stats(size_t index, size_t human_id, size_t& result) {
  result = SIZE_T_DEFAULT_VALUE;
  if (human_id < _raid_participants.size()) {
    if (_raid_participants[human_id] != NULL) {
      _raid_participants[human_id]->get_misc_stats(index, result);
	}
  }
  return 0;
}

size_t RaidEvent::get_misc_stats(size_t human_id, std::vector<size_t>& result) {
  result.clear();
  result.resize(MI_SIZE);
  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = SIZE_T_DEFAULT_VALUE;
  }
  if (human_id < _raid_participants.size()) {
    if (_raid_participants[human_id] != NULL) {
      _raid_participants[human_id]->get_misc_stats(result);
	}
  }
  return 0;
}

size_t RaidEvent::get_misc_stats(size_t index, size_t& result) {
  result = SIZE_T_DEFAULT_VALUE;
  if (!_raid_participants.empty()) {
  	for (size_t i = 0; i < _raid_participants.size(); ++i) {
      if (_raid_participants[i] != NULL) {
        size_t stat = SIZE_T_DEFAULT_VALUE;
        _raid_participants[i]->get_misc_stats(index, stat);
        result += stat;
	  }
	}
    result /= _raid_participants.size();
  }
  return 0;
}

size_t RaidEvent::get_misc_stats(std::vector<size_t>& result) {
  result.clear();
  result.resize(MI_SIZE);
  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = SIZE_T_DEFAULT_VALUE;
  }
  if (!_raid_participants.empty()) {
    for (size_t i = 0; i < _raid_participants.size(); ++i) {
      if (_raid_participants[i] != NULL) {
        std::vector<size_t> stats;
        stats.clear();
        stats.resize(MI_SIZE);
        for (size_t j = 0; j < stats.size(); ++j) {
          stats[j] = SIZE_T_DEFAULT_VALUE;
		}
        _raid_participants[i]->get_misc_stats(stats);
        if (stats.size() == result.size()) {
          for (size_t j = 0; j < result.size(); ++j) {
            result[j] += stats[j];
		  }
		}
	  }
	}
	for (size_t i = 0; i < result.size(); ++i) {
	  result[i] /= _raid_participants.size();
	}
  }
  return 0;
}

size_t RaidEvent::get_difficulty(size_t& result) {
  srand(static_cast<unsigned int>(time(0)));
  result = (rand() % MAX_STAT_VALUE + MAX_STAT_VALUE / 2) / 2;
  return 0;
}

size_t RaidEvent::event_outcome(size_t stat) {
  srand(static_cast<unsigned int>(time(0)));
  size_t difficulty = SIZE_T_DEFAULT_VALUE;
  get_difficulty(difficulty);
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

size_t RaidEvent::add_random_item() {
  if (storage.get_items_count() > 0) {
    srand(static_cast<unsigned int>(time(0)));
    size_t item_id = rand() % _storage.get_items_count();
    Item* to_add = NULL;
    size_t quality = IQ_THRASH;
    size_t rnd = rand() % MAX_STAT_VALUE;
    if (rnd < LEGENDARY_CHANCE) {
      quality = IQ_LEGENDARY;
    } else {
      rnd = rand() % MAX_STAT_VALUE;
      if (rnd < EPIC_CHANCE) {
        quality = IQ_EPIC;
	  } else {
        rnd = rand() % MAX_STAT_VALUE;
        if (rnd < RARE_CHANCE) {
          quality = IQ_RARE;
	    } else {
          rnd = rand() % MAX_STAT_VALUE;
          if (rnd < GOOD_CHANCE) {
            quality = IQ_GOOD;
		  } else {
            rnd = rand() % MAX_STAT_VALUE;
            if (rnd < COMMON_CHANCE) {
              quality = IQ_COMMON;
		    }
		  }
	    }
	  }
    }
	if (!_raid_participants.empty()) {
      size_t owner_id = _raid_participants.size();
      size_t index = _raid_participants.size();
      while (true) {
        index = rand() % _raid_participants.size();
        if (_raid_participants[index] != NULL) {
          break;
		}
	  }
	  _raid_participants[index]->get_own_id(owner_id);
      to_add = new Item(_storage.get_item_table(item_id), quality, owner_id);
	} else {
	  to_add = new Item(_storage.get_item_table(item_id), quality, FREE_INDEX);
	}
    _raid_loot.push_back(to_add);
    to_add = NULL;
  }
  return 0;
}

size_t RaidEvent::destroy_random_item() {
  if (!_raid_loot.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
      size_t index = rand() % target.size();
      if (_raid_loot[index] != NULL) {
        break;
	  }
	}
	delete _raid_loot[index];
	_raid_loot.erase(_raid_loot.begin() + index);
  }
  return 0;
}

size_t RaidEvent::add_random_resource() {
  if (!_raid_resources.empty()) {
  	srand(static_cast<unsigned int>(time(0)));
  	size_t index = rand() % _raid_resources.size();
  	size_t amount = rand() % (MAX_STAT_VALUE / 5);
  	_raid_resources[index] += amount;
  }
  return 0;
}

size_t RaidEvent::add_random_resource(size_t amount) {
  if (!_raid_resources.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    size_t index = rand() % _raid_resources.size();
    _raid_resources[index] += amount;
  }
  return 0;
}

size_t RaidEvent::remove_random_resource() {
  if (!_raid_resources.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    size_t index = rand() % target.size();
    size_t amount = rand() % (MAX_STAT_VALUE / 5);
    if (_raid_resources[index] >= amount) {
	  _raid_resources[index] -= amount;
    } else {
      _raid_resources[index] = SIZE_T_DEFAULT_VALUE;
	}
  }
  return 0;
}

size_t RaidEvent::remove_random_resource(size_t amount) {
  if (!_raid_resources.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    size_t index = rand() % _raid_resources.size();
    if (_raid_resources[index] >= amount) {
      _raid_resources[index] -= amount;
	} else {
      _raid_resources[index] = SIZE_T_DEFAULT_VALUE;
	}
  }
  return 0;
}

size_t RaidEvent::remove_random_resource_percent(size_t percents) {
  if (!_raid_resources.empty()) {
    srand(static_cast<unsigned int>(time(0)));
	size_t rest = MAX_STAT_VALUE;
    if (percents > rest) {
      rest = SIZE_T_DEFAULT_VALUE;
	} else {
	  rest -= percents;
	}
	size_t index = rand() % _raid_resources.size();
	_raid_resources[index] = _raid_resources[index] * rest / MAX_STAT_VALUE;
  }
  return 0;
}

size_t RaidEvent::add_resource(size_t index) {
  if (index < _raid_resources.size()) {
    srand(static_cast<unsigned int>(time(0)));
    size_t amount = rand() % (MAX_STAT_VALUE / 4);
    _raid_resources[index] += amount;
  }
  return 0;
}

size_t RaidEvent::add_resource(size_t index, size_t amount) {
  if (index < _raid_resources.size()) {
    _raid_resources[index] += amount;
  }
  return 0;
}

size_t RaidEvent::remove_resource(size_t index) {
  if (index < _raid_resources.size()) {
    srand(static_cast<unsigned int>(time(0)));
    size_t amount = rand() % (MAX_STAT_VALUE / 5);
    if (_raid_resources[index] >= amount) {
      _raid_resources[index] -= amount;
    } else {
      _raid_resources[index] = SIZE_T_DEFAULT_VALUE;
    }
  }
  return 0;
}

size_t RaidEvent::remove_resource(size_t index, size_t amount) {
  if (index < _raid_resources.size()) {
    if (_raid_resources[index] >= amount) {
      _raid_resources[index] -= amount;
    } else {
      _raid_resources[index] = SIZE_T_DEFAULT_VALUE;
    }
  }
  return 0;
}

size_t RaidEvent::add_participant() {
  srand(static_cast<unsigned int>(time(0)));
  bool gender = FEMALE_GENDER;
  size_t roll = rand() % MAX_STAT_VALUE;
  if (roll % 2 == 0) {
    gender = MALE_GENDER;
  }
  std::string name;
  _storage.form_name(gender, name);
  Human* to_add = new Human(_storage.get_profession(PI_UNEMPLOYED), gender, false, FREE_INDEX, name);
  _raid_participants.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t RaidEvent::kill_participant() {
  srand(static_cast<unsigned int>(time(0)));
  if (!_raid_participants.empty()) {
    while (true) {
      size_t index = rand() % _raid_participants.size();
      if (_raid_participants[index] != NULL) {
        delete _raid_participants[index];
        _raid_participants.erase(_raid_participants.begin() + index);
        break;
	  }
    }
  }
  return 0;
}

size_t RaidEvent::add_slave() {
  srand(static_cast<unsigned int>(time(0)));
  bool gender = FEMALE_GENDER;
  size_t roll = rand() % MAX_STAT_VALUE;
  if (roll % 2 == 0) {
    gender = MALE_GENDER;
  }
  std::string name;
  _storage.form_name(gender, name);
  Human* to_add = new Human(_storage.get_profession(PI_UNEMPLOYED), gender, true, FREE_INDEX, name);
  _raid_slaves.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t RaidEvent::kill_slave() {
  srand(static_cast<unsigned int>(time(0)));
  if (!_raid_slaves.empty()) {
    while (true) {
      size_t index = rand() % _raid_slaves.size();
      if (_raid_slaves[index] != NULL) {
        delete _raid_slaves[index];
        _raid_slaves.erase(_raid_slaves.begin() + index);
        break;
   	  }
    }
  }
  return 0;
}

size_t RaidEvent::add_random_human(bool is_slave) {
  if (is_slave) {
  	add_participant();
  } else {
  	add_slave();
  }
  return 0;
}

size_t RaidEvent::kill_random_human() {
  srand(static_cast<unsigned int>(time(0)));
  if ((rand() % MAX_STAT_VALUE) % 2 == 0) {
    kill_participant();
  } else {
    kill_slave();
  }
  return 0;
}

size_t RaidEvent::increase_phase_duration(size_t amount) {
  _raid_turns += amount;
  return 0;
}

size_t RaidEvent::decrease_phase_duration(size_t amount) {
  if (_raid_turns >= amount) {
    _raid_turns -= amount;
  } else {
    _raid_turns = SIZE_T_DEFAULT_VALUE;
  }
  return 0;
}

size_t RaidEvent::increase_misc_stat(size_t index, size_t value) {
  for (size_t i = 0; i < _raid_participants.size(); ++i) {
    if (_raid_participants[i] != NULL) {
      _raid_participants[i]->increase_misc_stat(index, value);
	}
  }
  return 0;
}

size_t RaidEvent::decrease_misc_stat(size_t index, size_t value) {
  for (size_t i = 0; i < _raid_participants.size(); ++i) {
    if (_raid_participants[i] != NULL) {
      _raid_participants[i]->decrease_misc_stat(index, value);
	}
  }
  return 0;
}

size_t RaidEvent::increase_combat_stat(size_t index, size_t value) {
  for (size_t i = 0; i < _raid_participants.size(); ++i) {
    if (_raid_participants[i] != NULL) {
      _raid_participants[i]->increase_combat_stat(index, value);
	}
  }
  return 0;
}

size_t RaidEvent::decrease_combat_stat(size_t index, size_t value) {
  for (size_t i = 0; i < _raid_participants.size(); ++i) {
    if (_raid_participants[i] != NULL) {
      _raid_participants[i]->decrease_combat_stat(index, value);
	}
  }
  return 0;
}
