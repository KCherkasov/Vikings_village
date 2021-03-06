#include "Human.h"

Human::Human(TypeProfession& profession, bool gender, ssize_t house_id, std::string& name) {
  srand(static_cast<unsigned int>(time(0)));
  _name.clear();
  _name = name;
  _combat_stats.clear();
  _combat_stats.resize(SI_SIZE);
  for (size_t i = 0; i < _combat_stats.size(); ++i) {
    if (i != SI_WOUNDS) {
      if (gender == MALE_GENDER) {
        _combat_stats[i] = BASE_MALE_COMBAT_STAT;
      } else {
        _combat_stats[i] = BASE_FEMALE_COMBAT_STAT;
      }
      size_t rnd = rand() % BASE_SEED - BASE_SEED / 2; //possibly needs tuning after play tests (in current form maximal add to stat is only BAS_SEED / 2)
      _combat_stats[i] += rnd;
    } else {
      _combat_stats[i] = BASE_WOUNDS; //needs future review (possibly units need more than one wound))
    }
  }
  _misc_stats.clear();
  _misc_stats.resize(MI_SIZE);
  for (size_t i = 0; i < _misc_stats.size(); ++i) {
    _misc_stats[i] = BASE_MISC_STAT;
    size_t rnd = rand() % BASE_SEED - BASE_SEED / 2; //possibly needs tuning after play tests
    _misc_stats[i] += rnd;
  }
  _skills.clear();
  _skills.resize(PI_SIZE);
  for (size_t i = 0; i < _skills.size(); ++i) {
    _skills[i] = BASE_SKILL;
    size_t rnd = rand() % BASE_SEED; //possibly need tuning after play tests;
    _skills[i] += rnd;
  }
  _saga.clear();
  _saga.resize(PS_SIZE);
  for (size_t i = 0; i < _saga.size(); ++i) {
    _saga[i] = SIZE_T_DEFAULT_VALUE;
  }
  _house_id = house_id;
  _profession = profession;
  _inventory();
  _gender = gender;
}

Human::Human(prototypes::HumanTable data, TypeProfession& profession) {
  _name.clear();
  _name = name;
  _combat_stats.clear();
  _combat_stats = data._combat_stats;
  _misc_stats.clear();
  _misc_stats = data._misc_stats;
  _skills.clear();
  _skills = data._skills;
  _saga.clear();
  _saga = data._saga;
  _house_id = data._house_id;
  _profession = profession;
  _inventory(data._equipment);
  _gender = data._gender;
}

size_t Human::get_name(std::string& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _name;
  return 0;
}

size_t Human::get_combat_stats(bool with_items, std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _combat_stats;
  if (with_items) {
    std::vector<size_t> from_items;
    from_items.clear();
    _inventory.get_bonuses(from_items);
    for (size_t i = 0; i < result.size(); ++i) {
      result[i] += from_items[i];
    }
  }
  return 0;
}

size_t Human::get_combat_stats(bool with_items, size_t index, size_t& result) {
  if (index < _combat_stats.size()) {
    result = _combat_stats[index];
  }
  if (with_items) {
    size_t from_items =SIZE_T_DEFAULT_VALUE;
    _inventory.get_bonuses(index, from_items);
    result += from_items;
  }
  return 0;
}

size_t Human::get_misc_stats(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _misc_stats;
  return 0;
}

size_t Human::get_misc_stats(size_t index, size_t& result) {
  if (index < _misc_stats.size()) {
    result = _misc_stats[index];
  }
  return 0;
}

size_t Human::get_skills(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _skills;
  return 0;
}

size_t Human::get_skills(size_t index, size_t& result) {
  if (index < _skills.size()) {
    result = _skills[index];
  }
  return 0;
}

size_t Human::get_saga(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _saga;
  return 0;
}

size_t Human::get_saga(size_t index, size_t& result) {
  if (index < _saga.size()) {
    result = _saga[index];
  }
  return 0;
}

size_t Human::get_age(size_t& result) {
  result = _age;
  return 0;
}

size_t Human::get_house_id(ssize_t& result) {
  result = _house_id;
  return 0;
}

size_t Human::get_profession(TypeProfession& result) {
  result = _profession;
  return 0;
}

size_t Human::get_inventory(Inventory& result) {
  result = _inventory;
  return 0;
}

size_t Human::get_inventory(std::vector<prototypes::ItemTable>& result) {
  _inventory.get_save_data(result);
  return 0;
}

size_t Human::get_inventory(size_t index, prototypes::ItemTable& result) {
  size_t inv_size;
  _inventory.get_size(inv_size);
  if (index < inv_size) {
    Item* item = NULL;
    _inventory.get_equipped(index, item);
    item->get_save_data(result);
    Item* item = NULL;
  }
  return 0;
}

size_t Human::get_gender(bool& result) {
  result = _gender;
  return 0;
}

size_t Human::get_save_data(prototypes::HumanTable& result) {
  result._name_size = _name.size();
  if (!result._name.empty()) {
    result._name.clear();
  }
  result._name = _name;
  if (!result._combat_stats.empty()) {
    result._combat_stats.clear();
  }
  result._combat_stats = _combat_stats;
  if (!result._misc_stats.empty()) {
    result._misc_stats.clear();
  }
  result._misc_stats = _misc_stats;
  if (!result._skills.empty()) {
    result._skills.clear();
  }
  result._skills = _skills;
  if (!result._saga.empty()) {
    result._saga.clear();
  }
  result._saga = _saga;
  _profession.get_id(result._profession_id);
  _inventory.get_save_data(result._equipment);
  result._gender = _gender;
  return 0;
}

size_t Human::set_name(std::string value) {
  if (!value.empty()) {
    _name = value;
  }
  return 0;
}

size_t Human::set_combat_stats(std::vector<size_t> value) {
  if (!value.empty()) {
    _combat_stats = value;
  }
  return 0;
}

size_t Human::set_combat_stats(size_t index, size_t value) {
  if (index < _combat_stats.size()) {
    _combat_stats[index] = value;
  }
  return 0;
}

size_t Human::set_misc_stats(std::vector<size_t> value) {
  if (!value.empty()) {
    _misc_stats = value;
  }
  return 0;
}

size_t Human::set_misc_stats(size_t index, size_t value) {
  if (index < _misc_stats.size()) {
    _misc_stats[index] = value;
  }
  return 0;
}

size_t Human::set_skills(std::vector<size_t> value) {
  if (!value.empty()) {
    _skills = value;
  }
  return 0;
}

size_t Human::set_skills(size_t index, size_t value) {
  if (index < _skills.size()) {
    _skills[index] = value;
  }
  return 0;
}

size_t Human::set_saga(std::vector<size_t> value) {
  if (!value.empty()) {
    _saga = value;
  }
  return 0;
}

size_t Human::set_saga(size_t index, size_t value) {
  if (index < _saga.size()) {
    _saga[index] = value;
  }
  return 0;
}

size_t Human::set_age(size_t value) {
  _age = value;
  return 0;
}

size_t Human::set_house_id(ssize_t value) {
  _house_id = value;
  return 0;
}

size_t Human::set_profession(TypeProfession& value) {
  _profession = value;
  return 0;
}

size_t Human::set_inventory(Inventory& value) {
  _inventory = value;
  return 0;
}

size_t Human::set_inventory(std::vector<prototypes::ItemTable> value) {
  _inventory.set_equipped(value);
  return 0;
}

size_t Human::set_inventory(size_t index, prototypes::ItemTable value) {
  _inventory.set_equipped(index, value);
  return 0;
}

size_t Human::set_inventory(size_t index, Item* value) {
  _inventory.set_equipped(index, value);
  return 0;
}

size_t Human::set_gender(bool value) {
  _gender = value;
  return 0;
}

size_t Human::what(std::string& out) {
  if (!out.empty()) {
    out.clear();
  }
  //code here to make pop-up text
  return 0;
}

size_t Human::consume() {
  //to be realized
  return 0;
}

size_t Human::add_to_saga(size_t index, size_t value) {
  if (index < _saga.size()) {
    _saga[index] += value;
  }
}

size_t Human::wound() {
  if (_combat_stats[SI_WOUNDS] > 0) {
    --_combat_stats[SI_WOUNDS];
  }
  return 0;
}

size_t Human::increase_combat_stat(size_t index) {
  if (index < _combat_stats.size()) {
    ++_combat_stats[index];
  }
  return 0;
}

size_t Human::increase_combat_stat(size_t index, size_t value) {
  if (index < _combat_stats.size()) {
    _combat_stats[index] += value;
  }
  return 0;
}

size_t Human::increase_misc_stat(size_t index) {
  if (index < _misc_stats.size()) {
    ++_misc_stats[index];
  }
  return 0;
}

size_t Human::increase_misc_stat(size_t index, size_t value) {
  if (index < _misc_stats.size()) {
    _misc_stats[index] += value;
  }
  return 0;
}

size_t Human::increase_skill(size_t index) {
  if (index < _skills.size()) {
    ++_skills[index];
  }
  return 0;
}

size_t Human::increase_skill(size_t index, size_t value) {
  if (index < _skills.size()) {
    _skills[index] += value;
  }
  return 0;
}

size_t Human::increase_age() {
  ++_age;
  return 0;
}

size_t Human::decrease_combat_stat(size_t index) {
  if (index < _combat_stats.size()) {
    if (_combat_stats[index] > 0) {
      --_combat_stats[index];
    }
  }
  return 0;
}

size_t Human::decrease_combat_stat(size_t index, size_t value) {
  if (index < _combat_stats.size()) {
    if (_combat_stats[index] >= value) {
      _combat_stats[index] -= value;
    } else {
      _combat_stats[index] = SIZE_T_DEFAULT_VALUE;
    }
  }
}

size_t Human::decrease_misc_stat(size_t index) {
  if (index < _misc_stats.size()) {
    if (_misc_stats[index] > 0) {
      --_misc_stats[index];
    }
  }
  return 0;
}

size_t Human::decrease_misc_stat(size_t index, size_t value) {
  if (index < _misc_stats.size()) {
    if (_misc_stats[index] >= value) {
      _misc_stats[index] -= value;
    } else {
      _misc_stats[index] = SIZE_T_DEFAULT_VALUE;
    }
  }
  return 0;
}

size_t Human::decrease_skill(size_t index) {
  if (index < _skills.size()) {
    if (_skills[index] > 0) {
      --_skills[index];
    }
  }
  return 0;
}

size_t Human::decrease_skill(size_t index, size_t value) {
  if (index < _skills.size()) {
    if (_skills[index] >= value) {
      _skills[index] -= value;
    } else {
      _skills[index] = SIZE_T_DEFAULT_VALUE;
    }
  }
  return 0;
}
