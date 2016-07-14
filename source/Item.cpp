#include "Item.h"

Item::Item() {
  _name.clear();
  _description.clear();
  _cost.clear();
  _slots.clear();
  _bonuses._wounds = 0;
  _bonuses._melee = 0;
  _bonuses._ranged = 0;
  _bonuses._defense = 0;
  _bonuses._initiative = 0;
  _penalties._wounds = 0;
  _penalties._melee = 0;
  _penalties._ranged = 0;
  _penalties._defense = 0;
  _penalties._initiative = 0;
}

Item::Item(ItemTable data) {
  _name.clear();
  _description.clear();
  _cost.clear();
  _slots.clear();
  _name = data._name;
  _description = data._description;
  _cost = data._cost;
  _slots = data._slots;
  _bonuses._wounds = data._bonuses._wounds;
  _bonuses._melee = data._bonuses._melee;
  _bonuses._ranged = data._bonuses._ranged;
  _bonuses._defense = data._bonuses._defense;
  _bonuses._initiative = data._bonuses._initiative;
  _penalties._wounds = data._penalties._wounds;
  _penalties._melee = data._penalties._melee;
  _penalties._ranged = data._penalties._ranged;
  _penalties._defense = data._penalties._defense;
  _penalties._initiative = data._penalties._initiative;
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

size_t Item::get_bonuses(CombatStats& result) {
  result._wounds = _bonuses._wounds;
  result._melee = _bonuses._melee;
  result._ranged = _bonuses._ranged;
  result._defense = _bonuses._defense;
  result._initiative = _bonuses._initiative;
  return 0;
}

size_t Item::get_penalties(CombatStats& result) {
  result._wounds = _penalties._wounds;
  result._melee = _penalties._melee;
  result._ranged = _penalties._ranged;
  result._defense = _penalties._defense;
  result._initiative = _penalties._initiative;
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

size_t Item::set_bonuses(CombatStats value) {
  _bonuses._wounds = value._wounds;
  _bonuses._melee = value._melee;
  _bonuses._ranged = value._ranged;
  _bonuses._defense = value._defense;
  _bonuses._initiative = value._initiative;
  return 0;
}

size_t Item::set_penalties(CombatStats value) {
  _penalties._wounds = value._wounds;
  _penalties._melee = value._melee;
  _penalties._ranged = value._ranged;
  _penalties._defense = value._defense;
  _penalties._initiative = value._initiative;
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
