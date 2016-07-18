#include "Item.h"

Item::Item() {
  _name.clear();
  _description.clear();
  _cost.clear();
  _slots.clear();
  _bonuses.clear();
  _penalties.clear();
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

size_t Item::set_name(std::string value) {
  _name = value;
  return 0;
}

size_t Item::set_description(std::string value) {
  _description = value;
  return 0;
}

size_t Item::set_cost(std::vector<size_t> value) {
  _cost = value;
  return 0;
}

size_t Item::set_cost(size_t index, size_t value) {
  if (index < _cost.size()) {
    _cost[index] = value;
  }
  return 0;
}

size_t Item::set_bonuses(std::vector<size_t> value) {
  _bonuses = value;
  return 0;
}

size_t Item::set_bonuses(size_t index, size_t value) {
  if (index < _bonuses.size()) {
    _bonuses[index] = value;
  }
  return 0;
}

size_t Item::set_penalties(std::vector<size_t> value) {
  _penalties = value;
  return 0;
}

size_t Item::set_penalties(size_t index, size_t value) {
  if (index < _penalties.size()) {
    _penalties[index] = value;
  }
  return 0;
}

size_t Item::set_slots(std::vector<bool> value) {
  _slots = value;
  return 0;
}

size_t Item::set_slots(size_t index, bool value) {
  if (index < _slots.size()) {
    _slots[index] = value;
  }
  return 0;
}

size_t Item::what(std::string& out) {
  out.clear();
  //code here to make pop-up text
  return 0;
}
