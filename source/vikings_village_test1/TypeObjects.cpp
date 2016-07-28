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

TypeBuilding::TypeBuilding(prototypes::TypeBuildingTable data): TypeObject() {
  _name =  data._name;
  _description = data._description;
  _max_employees = data._max_employees;
  _resources = data._resources;
  _cost = data._cost;
  _producable = data._producable;
  _building_time = data._building_time;
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

size_t TypeBuilding::get_save_data(prototypes::TypeBuildingTable& result) {
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
  if (!result._max_employees.empty()) {
    result._max_employees.clear();
  }
  result._max_employees = _max_employees;
  if (!result._resources.empty()) {
    result._resources.clear();
  }
  result._resources = _resources;
  result._building_time;
  if (!result._producable.empty()) {
    result._producable.clear();
  }
  result._producable = _producable;
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

size_t TypeBuilding::import_from_table(prototypes::TypeBuildingTable data) {
  _name = data._name;
  _description = data._description;
  _cost = data._cost;
  _max_employees = data._max_employees;
  _resources = data._resources;
  _building_time = data._building_time;
  _producable = data._producable;
  return 0;
}

TypeProfession::TypeProfession(): TypeObject() {
  _consumation.clear();
  _consumation.resize(RI_SIZE);
  _can_slave = BOOL_DEFAULT_VALUE;
}

TypeProfession::TypeProfession(prototypes::TypeProfessionTable data): TypeObject() {
  _name = data._name;
  _description = data._description;
  _consumation.clear();
  _consumation = data._consumation;
  _id = data._id;
  _can_slave = data._can_slave;
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

size_t TypeProfession::get_id(ssize_t& result) {
  result = _id;
  return 0;
}

size_t TypeProfession::get_can_slave(bool& result) {
  result = _can_slave;
  return 0;
}

size_t TypeProfession::get_save_data(prototypes::TypeProfessionTable& result) {
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
  if (!result._consumation.empty()) {
    result._consumation.clear();
  }
  result._consumation = _consumation;
  result._id = _id;
  result._can_slave = _can_slave;
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

size_t TypeProfession::set_id(size_t value) {
  _id = value;
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

size_t TypeProfession::import_from_table(prototypes::TypeProfessionTable data) {
  _name = data._name;
  _description = data._description;
  _consumation = data._consumation;
  _can_slave = data._can_slave;
  return 0;
}
