#include "Item.h"

Item::Item() {
  _name.clear();
  _description.clear();
  _cost.clear();
  _slots.clear();
  _bonuses.clear();
  _penalties.clear();
  _cost.resize(RI_SIZE);
  _bonuses.resize(SI_SIZE);
  _penalties.resize(SI_SIZE);
  _slots.resize(IS_SIZE);
  for (size_t i = 0; i < _cost.size(); ++i) {
    _cost[i] = SIZE_T_DEFAULT_VALUE;
  }
  for (size_t i = 0; i < _slots.size(); ++i) {
    _slots[i] = BOOL_DEFAULT_VALUE;
  }
  for (size_t i = 0; i < _bonuses.size(); ++i) {
    _bonuses[i] = SIZE_T_DEFAULT_VALUE;
    _penalties[i] = SIZE_T_DEFAULT_VALUE;
  }
  _quality = IQ_COMMON;
  _is_players = true;
}

Item::Item(prototypes::ItemTable data) {
  _name.clear();
  _description.clear();
  _cost.clear();
  _slots.clear();
  _bonuses.clear();
  _penalties.clear();
  _name = data._name;
  _description = data._description;
  _cost = data._cost;
  _slots = data._slots;
  _bonuses = data._bonuses;
  _penalties = data._penalties;
  _quality = data._quality;
  _is_players = data._is_players;
}

Item::Item(prototypes::ItemTable data, bool quality) {
  _name.clear();
  _description.clear();
  _cost.clear();
  _slots.clear();
  _bonuses.clear();
  _penalties.clear();
  _name = data._name;
  _description = data._description;
  _cost = data._cost;
  _slots = data._slots;
  _bonuses = data._bonuses;
  _penalties = data._penalties;
  _quality = quality;
  _is_players = true;
}

Item::Item(prototypes::ItemTable data, bool quality, bool is_players) {
  _name.clear();
  _description.clear();
  _cost.clear();
  _slots.clear();
  _bonuses.clear();
  _penalties.clear();
  _name = data._name;
  _description = data._description;
  _cost = data._cost;
  _slots = data._slots;
  _bonuses = data._bonuses;
  _penalties = data._penalties;
  _quality = quality;
  _is_players = is_players;
}

size_t Item::get_name(std::string& result) {
  result = _name;
  return 0;
}

size_t Item::get_description(std::string& result) {
  result = _description;
  return 0;
}

size_t Item::get_cost(std::vector<size_t>& result) {
  result = _cost;
  return 0;
}

size_t Item::get_cost(size_t index, size_t& result) {
  if (index < _cost.size()) {
    result = _cost[index];
  }
  return 0;
}

size_t Item::get_bonuses(std::vector<size_t>& result) {
  result = _bonuses;
  return 0;
}

size_t Item::get_bonuses(size_t index, size_t& result) {
  if (index < _bonuses.size()) {
    result = _bonuses[index];
  }
  return 0;
}

size_t Item::get_penalties(std::vector<size_t>& result) {
  result = _penalties;
  return 0;
}

size_t Item::get_penalties(size_t index, size_t& result) {
  if (index < _penalties.size()) {
    result = _penalties[index];
  }
  return 0;
}

size_t Item::get_quality(size_t& result) {
  result = _quality;
  return 0;
}

size_t Item::get_slots(std::vector<bool>& result) {
  result =  _slots;
  return 0;
}

size_t Item::get_slots(size_t index, bool& result) {
  if (index < _slots.size()) {
    result = _slots[index];
  }
  return 0;
}

size_t Item::get_is_players(bool& result) {
  result = _is_players;
  return 0;
}

size_t Item::get_save_data(prototypes::ItemTable& result) {
  result._name_size = _name.size();
  if (!result._name.empty()) {
    result._name.clear();
  }
  result._name = _name;
  result._description_size = _description.size();
  if (!result._description.empty()) {
    result._description.clear();
  }
  result._description = _description;
  if (!result._cost.empty()) {
    result._cost.clear();
  }
  result._cost = _cost;
  if (!result._bonuses.empty()) {
    result._bonuses.clear();
  }
  result._bonuses = _bonuses;
  if (!result._penalties.empty()) {
    result._penalties.clear();
  }
  result._penalties = _penalties;
  result._quality = _quality;
  if (!result._slots.empty()) {
    result._slots.clear();
  }
  result._slots = _slots;
  result._is_players = _is_players;
  return 0;
}

size_t Item::set_name(std::string value) {
  if (!value.empty()) {
    _name = value;
  }
  return 0;
}

size_t Item::set_description(std::string value) {
  if (!value.empty()) {
    _description = value;
  }
  return 0;
}

size_t Item::set_cost(std::vector<size_t> value) {
  if (!value.empty()) {
    _cost = value;
  }
  return 0;
}

size_t Item::set_cost(size_t index, size_t value) {
  if (index < _cost.size()) {
    _cost[index] = value;
  }
  return 0;
}

size_t Item::set_bonuses(std::vector<size_t> value) {
  if (!value.empty()) {
    _bonuses = value;
  }
  return 0;
}

size_t Item::set_bonuses(size_t index, size_t value) {
  if (index < _bonuses.size()) {
    _bonuses[index] = value;
  }
  return 0;
}

size_t Item::set_penalties(std::vector<size_t> value) {
  if (!value.empty()) {
    _penalties = value;
  }
  return 0;
}

size_t Item::set_penalties(size_t index, size_t value) {
  if (index < _penalties.size()) {
    _penalties[index] = value;
  }
  return 0;
}

size_t Item::set_quality(size_t value) {
  _quality = value;
  return 0;
}

size_t Item::set_slots(std::vector<bool> value) {
  if (!value.empty()) {
    _slots = value;
  }
  return 0;
}

size_t Item::set_slots(size_t index, bool value) {
  if (index < _slots.size()) {
    _slots[index] = value;
  }
  return 0;
}

size_t Item::set_is_players(bool value) {
  _is_players = value;
  return 0;
}

size_t Item::what(std::string& out) {
  char* digit = new char[DIGIT_STRING_SIZE];
  std::string resource_names[RI_SIZE] { "Gold: ", "Food: ", "Wood: ", "Iron: ", "Leather: " };
  std::string combat_stat_names[SI_SIZE] { "Wounds: ", "Melee skill: ", "Ranged skill: ", "Defense: ", "Initiative: " };
  std::string equipment_slot_names[IS_SIZE] { "Head ", "Body ", "Arms ", "Legs ", "Right hand ", "Left hand ", "Ranged " };
  std::string quality_names[IQ_SIZE] { "Thrash ", "Common ", "Good ", "Rare ", "Epic ", "Legendary " };
  if (!out.empty()) {
    out.clear();
  }
  out.append("\nName: ");
  out += _name;
  out.append("\nDescription: ");
  out += _description;
  out.append("\n--\n");
  out.append("Cost:\n");
  for (size_t i = 0; i < RI_SIZE; ++i) {
    out += resource_names[i];
    out.append(itoa(_cost[i], digit, 10));
    out.append("\n");
  }
  out.append("--\n");
  out.append("Wielder bonuses:\n");
  for (size_t i = 0; i < SI_SIZE; ++i) {
    out += combat_stat_names[i];
    out.append(itoa(_bonuses[i], digit, 10));
    out.append("\n");
  }
  out.append("--\n");
  out.append("Target penalties:\n");
  for (size_t i = 0; i < SI_SIZE; ++i) {
    out += combat_stat_names[i];
    out.append(itoa(_penalties[i], digit, 10));
    out.append("\n");
  }
  out.append("--\n");
  out.append("Quality: ");
  out += quality_names[_quality];
  out.append("--\n");
  out.append("Equipable slots:\n");
  for (size_t i = 0; i < IS_SIZE; ++i) {
    if (_slots[i]) {
      out += equipment_slot_names[i];
      out.append("\n");
    }
  }
  out.append("--\n");
  out.append("Belongs to player: ");
  if (_is_players) {
    out.append("Yes\n");
  } else {
    out.append("No\n");
  }
  out.append("\n<====>\n");
  delete[] digit;
  return 0;
}

size_t Item::import_from_table(prototypes::ItemTable data) {
  size_t response = 0;
  response = set_name(data._name);
  response = set_description(data._description);
  response = set_bonuses(data._bonuses);
  response = set_penalties(data._penalties);
  response = set_slots(data._slots);
  response = set_cost(data._cost);
  return response;
}
