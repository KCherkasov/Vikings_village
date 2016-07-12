#include "TypeObjects.h"

size_t TypeObject::get_name(std::string& result) {
  result = _name;
  return 0;
}

size_t TypeObject::get_description(std::string& result) {
  result = _description;
  return 0;
}

size_t TypeObject::set_name(std::string value) {
  _name = value;
  return 0;
}

size_t TypeObject::set_name(char* value) {
  if (value != NULL) {
    _name.append(value);
  }
  return 0;
}

size_t TypeObject::set_description(std::string value) {
  _description = value;
  return 0;
}

size_t TypeObject::set_description(char* value) {
  if (value != NULL) {
    _description.append(value);
  }
  return 0;
}

TypeBuilding::TypeBuilding(): TypeObject() {
  _max_employees.clear();
  _resources.clear();
  _cost.clear();
  _producable.clear();
  _building_time = 0;
}

size_t TypeBuilding::get_max_employees(std::vector<size_t>& result) {
  result = _max_employees;
  return 0;
}

size_t TypeBuilding::get_max_employees(size_t index, size_t& result) {
  if (index < _max_employees.size()) {
    result = _max_employees[index];
  }
  return 0;
}

size_t TypeBuilding::get_resources(std::vector<size_t>& result) {
  result = _resources;
  return 0;
}

size_t TypeBuilding::get_resources(size_t index, size_t& result) {
  if (index < _resources.size()) {
    result = _resources[index];
  }
  return 0;
}

size_t TypeBuilding::get_cost(std::vector<size_t>& result) {
  result = _cost;
  return 0;
}

size_t TypeBuilding::get_cost(size_t index, size_t& result) {
  if (index < _cost.size()) {
    result = _cost[index];
  }
  return 0;
}

size_t TypeBuilding::get_producable(std::vector<bool>& result) {
  result = _producable;
  return 0;
}

size_t TypeBuilding::get_producable(size_t index, bool& result) {
  if (index < _producable.size()) {
    result = _producable[index];
  }
  return 0;
}

size_t TypeBuilding::get_building_time(size_t& result) {
  result = _building_time;
  return 0;
}

size_t TypeBuilding::set_max_employees(std::vector<size_t> value) {
  _max_employees = value;
}

size_t TypeBuilding::set_max_employees(size_t index, size_t value) {
  if (index < _max_employees.size()) {
    _max_employees[index] = value;
  }
  return 0;
}

size_t TypeBuilding::set_resources(std::vector<size_t> value) {
  _resources = value;
  return 0;
}

size_t TypeBuilding::set_resources(size_t index, size_t value) {
  if (index < _resources.size()) {
    _resources[index] = value;
  }
  return 0;
}

size_t TypeBuilding::set_cost(std::vector<size_t> value) {
  _cost = value;
  return 0;
}

size_t TypeBuilding::set_cost(size_t index, size_t value) {
  if ( index < _cost.size()) {
    _cost[index] = value;
  }
  return 0;
}

size_t TypeBuilding::set_producable(std::vector<bool> value) {
  _producable = value;
  return 0;
}

size_t TypeBuilding::set_producable(size_t index, bool value) {
  if (index < _producable.size()) {
    _producable[index] = value;
  }
  return 0;
}

size_t TypeBuilding::set_building_time(size_t value) {
  _building_time = value;
  return 0;
}

size_t TypeBuilding::what(std::string& out) {
  out.clear();
  //code to from pop-up text here
  return 0;
}

TypeProfession::TypeProfession(): TypeObject() {
  _consumation.clear();
  _can_slave = false;
}

size_t TypeProfession::get_consumation(std::vector<size_t>& result) {
  result = _consumation;
  return 0;
}

size_t TypeProfession::get_consumation(size_t index, size_t& result) {
  if (index < _consumation.size()) {
    result = _consumation[index];
  }
  return 0;
}

size_t TypeProfession::get_can_slave(bool& result) {
  result = _can_slave;
  return 0;
}

size_t TypeProfession::set_consumation(std::vector<size_t> value) {
  _consumation = value;
  return 0;
}

size_t TypeProfession::set_consumation(size_t index, size_t value) {
  if (index < _consumation.size()) {
    _consumation[index] = value;
  }
  return 0;
}

size_t TypeProfession::set_can_slave(bool value) {
  _can_slave = value;
  return 0;
}

size_t TypeProfession::what(std::string& out) {
  //code to form pop-up text here
  return 0;
}
