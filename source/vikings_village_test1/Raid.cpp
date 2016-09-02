#include "Raid.h"

Raid::Raid(IngameStorage& storage): _storage(storage) {
  _stage = RS_THERE;
  if (!_turns_left.empty()) {
    _turns_left.clear();
    _turns_left.resize(RS_SIZE);
    for (size_t i = 0; i < _turns_left.size(); ++i) {
      _turns_left[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  if (!_terms.empty()) {
    _terms.clear();
    _terms.resize(TI_SIZE);
    for (size_t i = 0; i < _terms.size(); ++i) {
      _terms[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  if (!_resources.empty()) {
    _resources.clear();
    _resources.resize(RI_SIZE);
    for (size_t i = 0; i < _resources.size(); ++i) {
      _resources[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  if (!_participants.empty()) {
    for (size_t i = 0; i < _participants.size(); ++i) {
      if (_participants[i] != NULL) {
        delete _participants[i];
	  }
	}
	_participants.clear();
  }
  if (!_loot.empty()) {
    for (size_t i = 0; i < _loot.size(); ++i) {
      if (_loot[i] != NULL) {
        delete _loot[i];
	  }
	}
	_loot.clear();
  }
}

Raid::Raid(size_t turns_left, std::vector<size_t> terms, size_t food, std::vector<Human*> participants, IngameStorage& storage): _storage(storage) {
  _stage = RS_THERE;
  size_t whole_turns = turns_left;
  if (!_turns_left.empty()) {
    _turns_left.clear();
  }
  _turns_left.resize(RS_SIZE);
  for (size_t i = 0; i < _turns_left.size(); ++i) {
    _turns_left[i] = whole_turns / RS_SIZE;
  }
  whole_turns -= (whole_turns / RS_SIZE * RS_SIZE);
  if (whole_turns > 0) {
  	size_t i = 0;
    while (whole_turns > 0) {
      ++_turns_left[i++ % _turns_left.size()];
      --whole_turns;
	}
  }
  if (!_terms.empty()) {
    _terms.clear();
    _terms.resize(TI_SIZE);
    for (size_t i = 0; i < _terms.size(); ++i) {
      _terms[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  if (terms.size() == _terms.size()) {
    for (size_t i = 0; i < _terms.size(); ++i) {
      _terms[i] = terms[i];
	}
  }
  if (!_resources.empty()) {
    _resources.clear();
    _resources.resize(RI_SIZE);
    for (size_t i = 0; i < _resources.size(); ++i) {
      _resources[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  _resources[RI_FOOD] = food;
  if (!_participants.empty()) {
    for (size_t i = 0; i < _participants.size(); ++i) {
      if (_participants[i] != NULL) {
        delete _participants[i];
	  }
	}
	_participants.clear();
  }
  for (size_t i = 0; i < participants.size(); ++i) {
    _participants.push_back(participants[i]);
  }
  if (!_loot.empty()) {
    for (size_t i = 0; i < _loot.size(); ++i) {
      if (_loot[i] != NULL) {
        delete _loot[i];
	  }
	}
	_loot.clear();
  }
}

Raid::Raid(prototypes::RaidTable data, IngameStorage& storage): _storage(storage) {
  _stage = data._stage;
  if (!_turns_left.empty()) {
    _turns_left.clear();
  }
  _turns_left = data._turns_left;
  if (!_terms.empty()) {
    _terms.clear();
    _terms.resize(TI_SIZE);
    for (size_t i = 0; i < _terms.size(); ++i) {
      _terms[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  if (data._terms.size() == _terms.size()) {
    for (size_t i = 0; i < _terms.size(); ++i) {
      _terms[i] = data._terms[i];
	}
  }
  if (!_resources.empty()) {
    _resources.clear();
    _resources.resize(RI_SIZE);
    for (size_t i = 0; i < _resources.size(); ++i) {
      _resources[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  if (data._resources.size() == _resources.size()) {
    for (size_t i = 0; i < _resources.size(); ++i) {
      _resources[i] = data._resources[i];
	}
  }
  if (!_participants.empty()) {
    for (size_t i = 0; i < _participants.size(); ++i) {
      if (_participants[i] != NULL) {
        delete _participants[i];
	  }
	}
	_participants.clear();
  }
  for (size_t i = 0; i < data._participants.size(); ++i) {
    Human* to_add = new Human(data._participants[i], _storage.get_profession(data._participants[i]._profession_id));
    _participants.push_back(to_add);
    to_add = NULL;
  }
  if (!_loot.empty()) {
    for (size_t i = 0; i < _loot.size(); ++i) {
      if (_loot[i] != NULL) {
        delete _loot[i];
	  }
	}
	_loot.clear();
  }
  for (size_t i = 0; i < data._loot.size(); ++i) {
    Item* to_add = new Item(data._loot[i]);
    _loot.push_back(to_add);
    to_add = NULL;
  }
}

Raid::~Raid() {
  if (!_participants.empty()) {
    for (size_t i = 0; i < _participants.size(); ++i) {
      if (_participants[i] != NULL) {
        delete _participants[i];
	  }
	}
	_participants.clear();
  }
  if (!_loot.empty()) {
    for (size_t i = 0; i < _loot.size(); ++i) {
      if (_loot[i] != NULL) {
        delete _loot[i];
	  }
	}
	_loot.clear();
  }
}

size_t Raid::get_turns_left(std::vector<size_t>& result) {
  result = _turns_left;
  return 0;
}

size_t Raid::get_turns_left(size_t index, size_t& result) {
  if (index < _turns_left.size()) {
    result = _turns_left;
  }
  return 0;
}

size_t Raid::get_stage(size_t& result) {
  result = _stage;
  return 0;
}

size_t Raid::get_terms(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _terms;
  return 0;
}

size_t Raid::get_terms(size_t index, size_t& result) {
  if (index < _terms.size()) {
    result = _terms[index];
  }
  return 0;
}

size_t Raid::get_terms(size_t index) {
  if (index < _terms.size()) {
    return _terms[index];
  } else {
    return _SIZE_T_DEFAULT_VALUE;
  }
}

size_t Raid::get_resources(std::vector<size_t>& result) {
  result = _resources;
  return 0;
}

size_t Raid::get_resources(size_t index, size_t& result) {
  if (index < _resources.size()) {
    result = _resources[index];
  }
  return 0;
}

size_t Raid::get_resources(size_t index) {
  if (index < _resources.size()) {
    return _resources[index];
  } else {
    return SIZE_T_DEFAULT_VALUE;
  }
}

size_t Raid::get_participants(std::vector<Human*>& result) {
  result =  _participants;
  return 0;
}

size_t Raid::get_participants(size_t index, Human*& result) {
  if (index < _participants.size()) {
    result = _participants[index];
  } else {
    result = NULL;
  }
  return 0;
}

size_t Raid::get_participants_count(size_t& result) {
  result = _participants.size();
  return 0;
}

size_t Raid::get_slaves(std::vector<Human*>& result) {
  result = _slaves;
  return 0;
}

size_t Raid::get_slaves(size_t index, Human*& result) {
  if (index < _slaves.size()) {
    result = _slaves[index];
  } else {
    result = NULL;
  }
  return 0;
}

size_t Raid::get_slaves_count(size_t& result) {
  result = _slaves.size();
  return 0;
}

size_t Raid::get_loot(std::vector<Item*>& result) {
  result = _loot;
  return 0;
}

size_t Raid::get_loot(size_t index, Item*& result) {
  if (index < _loot.size()) {
    result = _loot[index];
  } else {
    result = NULL;
  }
  return 0;
}

size_t Raid::get_loot_count(size_t& result) {
  result = _loot.size();
  return 0;
}

size_t Raid::get_save_data(prototypes::RaidTable& result) {
  result._turns_left = _turns_left;
  if (!result._terms.empty()) {
    result._terms.clear();
  }
  result._terms = _terms;
  if (!result._resources.empty()) {
    result._resources.clear();
  }
  result._resources = _resources;
  if (!result._participants.empty()) {
    result._participants.clear();
  }
  for (size_t i = _participants.size(); ++i) {
    if (_participants[i] != NULL) {
      prototypes::HumanTable to_add;
      _participants[i]->get_save_data(to_add);
      result._participants.push_back(to_add);
	}
  }
  result._participants_count = result._participants.size();
  if (!result._slaves.empty()) {
    result._slaves.clear();
  }
  for (size_t i = 0; i < _slaves.size(); ++i) {
    if (_slaves[i] != NULL) {
      prototypes::HumanTable to_add;
      _slaves[i]->get_save_data(to_add);
      result._slaves.push_back(to_add);
	}
  }
  result._slaves_count = result._slaves.size();
  if (!result._loot.empty()) {
    result._loot.clear();
  }
  for (size_t i = 0; i < _loot.size(); ++i) {
    if (_loot[i] != NULL) {
      prototypes::ItemTable to_add;
      _loot[i]->get_save_data(to_add);
      result._loot.push_back(to_add);
	}
  }
  result._loot_count = result._loot.size();
  return 0;
}

size_t Raid::set_turns_left(size_t value) {
  _turns_left = value;
  return 0;
}

size_t Raid::set_terms(std::vector<size_t> value) {
  if (!_terms.empty()) {
    _terms.clear();
  }
  _terms = value;
  return 0;
}

size_t Raid::set_terms(size_t index, size_t value) {
  if (index < _terms.size()) {
    _terms[index] = value;
  }
  return 0;
}

size_t Raid::set_resources(std::vector<size_t> value) {
  if (!_resources.empty()) {
    _resources.clear();
  }
  _resources = value;
  return 0;
}

size_t Raid::set_resources(size_t index, size_t value) {
  if (index < _resources.size()) {
    _resources[index] = value;
  }
  return 0;
}

size_t Raid::set_participants(std::vector<Human*> value) {
  if (!_participants.empty()) {
    _participants.clear();
  }
  _participants = value;
  return 0;
}

size_t Raid::set_participants(size_t index, Human* value) {
  if (index < _participants.size()) {
    _participants[i] = value;
  }
  return 0;
}

size_t Raid::set_slaves(std::vector<Human*> value) {
  if (!_slaves.empty()) {
    for (size_t i = 0; i < _slaves.size(); ++i) {
      if (_slaves[i] != NULL) {
        delete _slaves[i];
	  }
	}
	_slaves.clear();
  }
  _slaves = value;
  return 0;
}

size_t Raid::set_slaves(size_t index, Human* value) {
  if (index < _slaves.size()) {
    if (_slaves[index] != NULL) {
      delete _slaves[index];
	}
	_slaves[index] = value;
  }
  return 0;
}

size_t Raid::set_loot(std::vector<Item*> value) {
  if (!_loot.empty()) {
    for (size_t i = 0; i < _loot.size(); ++i) {
      if (_loot[i] != NULL) {
        delete _loot[i];
	  }
	}
	_loot.clear();
  }
  _loot = value;
  return 0;
}

size_t Raid::set_loot(size_t index, Item* value) {
  if (index < _loot.size()) {
    if (_loot[index] != NULL) {
      delete _loot[index];
	}
	_loot[index] = value;
  }
  return 0;
}

size_t Raid::what(std::string& out) {
  if (!out.empty()) {
    out.clear();
  }
  return 0;
}

size_t Raid::distribute_loot(std::vector<size_t>& village_resources, std::vector<Item*>& village_items, std::vector<Human*>& village_people) {
  if (village_resources.empty()) {
    village_resources.resize(RI_SIZE);
    for (size_t i = 0; i < village_resources.size(); ++i) {
      village_resources[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  if (village_resources.size() == _resources.size()) {
    // at this moment only gold is shared between chief and participants, possibly needs a review
    size_t debt = SIZE_T_DEFAULT_VALUE;
	if (_resources[RI_GOLD] >= _terms[TI_SHIP_COST]) {
      village_resources[RI_GOLD] += _terms[TI_SHIP_COST];
      _resources[RI_GOLD] -= _terms[TI_SHIP_COST];
	} else {
      debt += (_terms[TI_SHIP_COST] - _resources[RI_GOLD]);
      village_resources[RI_GOLD] += _resources[RI_GOLD];
      _resources[RI_GOLD] = SIZE_T_DEFAULT_VALUE;
	}
	if (_resources[RI_GOLD] >= _terms[TI_FOOD_COST]) {
      village_resources[RI_GOLD] += _terms[TI_FOOD_COST];
      _resources[RI_GOLD] -= _terms[TI_FOOD_COST];
	} else {
      debt += (_terms[TI_FOOD_COST] - _resources[RI_GOLD]);
      village_resources[RI_GOLD] += _resources[RI_GOLD];
      _resources[RI_GOLD] = SIZE_T_DEFAULT_VALUE;
	}
	size_t share = SIZE_T_DEFAULT_VALUE;
	if (_participants.size() > _resources[RI_GOLD]) {
      share = 1;
	} else {
      share = _resources[RI_GOLD] / _participants.size();
	}
	for (size_t i = 0; i < _participants.size(); ++i) {
      if (_resources[RI_GOLD] == SIZE_T_DEFAULT_VALUE) {
        break;
	  }
	  if (_resources[RI_GOLD] < share) {
	  	_participants[i]->add_to_saga(PS_LOOTED, _resources[RI_GOLD]);
	  	_resources[RI_GOLD] = SIZE_T_DEFAULT_VALUE;
		break;
	  } else {
        _participants[i]->add_to_saga(PS_LOOTED, share);
        _resources[RI_GOLD] -= share;
	  }
	}
	if (_resources[RI_GOLD] >= (3 * share)) {
      village_resources[RI_GOLD] += (3 * share);
      _resource[RI_GOLD] -= (3 * share);
	} else {
      village_resources[RI_GOLD] += _resources[RI_GOLD];
      _resources[RI_GOLD] = SIZE_T_DEFAULT_VALUE;
	}
	for (size_t i = 0; i < village_resources.size(); ++i) {
      village_resource[i] += _resources[i];
      _resources[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  for (size_t i = 0; i < _loot.size(); ++i) {
    if (_loot[i] != NULL) {
      village_items.push_back(_loot[i]);
    }
  }
  for (size_t i = 0; i < _slaves.size(); ++i) {
    if (_slaves[i] != NULL) {
      village_people.push_back(_slaves[i]);
    }
  }
  return 0;
}

size_t Raid::consume() {
  for (size_t i = 0; i < _participants.size(); ++i) {
    if (_participants[i] != NULL) {
      if (!_participants[i]->get_has_consumed()) {
        _participants[i]->switch_has_consumed();
        if (_resources[RI_FOOD] > SIZE_T_DEFAULT_VALUE) {
          _participants[i]->increase_misc_stat(MI_MORALE);
		} else {
          _participants[i]->decrease_misc_stat(MI_MORALE);
		}
	  }
	}
  }
  return 0;
}

size_t Raid::turn() {
  // write after RaidEvent and derivatives will be realized
  return 0;
}

size_t Raid::add_resources(std::vector<size_t> amount) {
  if (amount.size() == _resources.size()) {
    for (size_t i = 0; i < _resources.size(); ++i) {
      _resources[i] += amount[i];
	}
  }
  return 0;
}

size_t Raid::add_resources(size_t index, size_t amount) {
  if (index < _resources.size()) {
    _resources[index] += amount;
  }
  return 0;
}

size_t Raid::add_participant(Human* value) {
  // put some branch code here to set conditions of successfull adding of new participants (possibly when Ship class will be developed)
  _participants.push_back(value);  
  return 0;
}

size_t Raid::add_participant(prototypes::HumanTable value) {
  // put some branch code here to set conditions of successfull adding of new participants (possibly when Ship class will be developed)
  Human* to_add = new Human(value, _storage.get_profession(value._profession_id));
  _participants.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t Raid::add_slave(Human* value) {
  _slaves.push_back(value);
  return 0;
}

size_t Raid::add_slave(prototypes::HumanTable value) {
  Human* to_add = new Human(value, _storage.get_profession(value._profession_id));
  _slaves.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t Raid::add_loot(Item* value) {
  srand(static_cast<unsigned int>(time(0)));
  if (!_participants.empty()) {
    size_t looter_id;
    while (true) {
      if (_participants[rand() % _participants.size()] != NULL) {
        _participants[rand() % _participants.size()]->get_own_id(looter_id);
        break;
	  }
	}
	if (value != NULL) {
      value->set_owner_id(looter_id);
	}
  }
  _loot.push_back(value);
  return 0;
}

size_t Raid::add_loot(prototypes::ItemTable value) {
  srand(static_cast<unsigned int>(time(0)));
  Item* to_add = NULL;
  if (!_participants.empty()) {
  	to_add = new Item(value, value._quality, rand() % _participants.size());
  } else {
  	to_add = new Item(value);
  }
  _loot.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t Raid::remove_resources(std::vector<size_t> amount) {
  if (amount.size() == _resources.size()) {
    for (size_t i = 0; i < _resources.size(); ++i) {
      if (_resources[i] >= amount[i]) {
        _resource[i] -= amount[i];
	  } else {
        _resource[i] = SIZE_T_DEFAULT_VALUE;
	  }
	}
  }
  return 0;
}

size_t Raid::remove_resources(size_t index, size_t amount) {
  if (index < _resources.size()) {
    if (_resources[index] >= amount) {
      _resources[index] -= amount;
	} else {
      _resources[index] = SIZE_T_DEFAULT_VALU/E;
	}
  }
  return 0;
}

size_t Raid::remove_participant(size_t index) {
  if (index < _participants.size()) {
    if (_participants[index] != NULL) {
      _participants[index] = NULL;
	}
	_participants.erase(_participants.begin() + index);
  }
  return 0;
}

size_t Raid::remove_slave(size_t index) {
  if (index < _slaves.size()) {
    if (_slaves[index] != NULL) {
      delete _slaves[index];
	}
	_slaves.erase(_slaves.begin() + index);
  }
  return 0;
}

size_t Raid::remove_loot(size_t index) {
  if (index < _loot.size()) {
    if (_loot[index] != NULL) {
      delete _loot[index];
	}
	_loot.erase(_loot.begin() + index);
  }
  return 0;
}

