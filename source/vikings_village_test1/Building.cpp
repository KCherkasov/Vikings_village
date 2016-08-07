#include "Building.h"

Building::Building(TypeBuilding& kind): _kind(kind) {
  if (!_employees_id.empty()) {
    _employees_id.clear();
  }
  if (!_inhabitants.empty()) {
    _inhabitants.clear();
  }
  if (!_production_queue.empty()) {
    _production_queue.clear();
  }
  _kind.get_building_time(_building_time);
}

Building::Building(prototypes::BuildingTable data, TypeBuilding& kind): _kind(kind) {
  if (!_employees_id.empty()) {
    _employees_id.clear();
  }
  _employees_id = data._employees_id;
  if (!_inhabitants.empty()) {
    _inhabitants.clear();
  }
  _inhabitants = data._inhabitants;
  if (!_production_queue.empty()) {
    _production_queue.clear();
  }
  _production_queue = data._production_queue;
  _building_time = data._building_time;
}

size_t Building::get_name(std::string& result) {
  _kind.get_name(result);
  return 0;
}

size_t Building::get_description(std::string& result) {
  _kind.get_description(result);
  return 0;
}

size_t Building::get_employees_id(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _employees_id;
  return 0;
}

size_t Building::get_employees_id(size_t index, size_t& result) {
  if (index < _employees_id.size()) {
    result = _employees_id[index];
  }
  return 0;
}

size_t Building::get_inhabitants(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _inhabitants;
  return 0;
}

size_t Building::get_inhabitants(size_t index, size_t& result) {
  if (index < _inhabitants.size()) {
    result = _inhabitants[index];
  }
  return 0;
}

size_t Building::get_production_queue(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _production_queue;
  return 0;
}

size_t Building::get_production_queue(size_t index, size_t& result) {
  if (index < _production_queue.size()) {
    result = _production_queue[index];
  }
  return 0;
}

size_t Building::get_building_time(size_t& result) {
  result = _building_time;
  return 0;
}

size_t Building::get_save_data(prototypes::BuildingTable& result) {
  _kind.get_id(result._kind_id);
  result._employees_count = _employees_id.size();
  if (!result._employees_id.empty()) {
    result._employees_id.clear();
  }
  result._employees_id = _employees_id;
  result._inhabitants_count = _inhabitants.size();
  if (!result._inhabitants.empty()) {
    result._inhabitants.clear();
  }
  result._inhabitants = _inhabitants;
  result._queue_size = _production_queue.size();
  if (!result._production_queue.empty()) {
    result._production_queue.clear();
  }
  result._production_queue = _production_queue;
  result._building_time = _building_time;
  return 0;
}

size_t Building::set_employees_id(std::vector<size_t> value) {
  _employees_id = value;
  return 0;
}

size_t Building::set_employees_id(size_t index, size_t value) {
  if (index < _employees_id.size()) {
    _employees_id[index] = value;
  }
  return 0;
}

size_t Building::set_inhabitants(std::vector<size_t> value) {
  _inhabitants = value;
  return 0;
}

size_t Building::set_inhabitants(size_t index, size_t value) {
  if (!_inhabitants.empty()) {
    _inhabitants[index] = value;
  }
  return 0;
}

size_t Building::set_production_queue(std::vector<size_t> value) {
  _production_queue = value;
  return 0;
}

size_t Building::set_production_queue(size_t index, size_t value) {
  if (index < _production_queue.size()) {
    _production_queue[index] = value;
  }
  return 0;
}

size_t Building::set_building_time(size_t value) {
  _building_time = value;
  return 0;
}

size_t Building::add_to_queue(size_t value) {
  if (_production_queue.size() < MAX_PRODUCTION_QUEUE_SIZE) {
    _production_queue.push_back(value);
  }
  return 0;
}

size_t Building::remove_from_queue() {
  if (!_production_queue.empty()) {
    _production_queue.erase(_production_queue.begin() +_production_queue.size() - 1);
  }
  return 0;
}

size_t Building::remove_from_queue(size_t index) {
  if (index < _production_queue.size()) {
    _production_queue.erase(_production_queue.begin() + index);
  }
  return 0;
}

size_t Building::add_inhabitant(size_t value) {
  size_t capacity;
  _kind.get_living_space(capacity);
  if (_inhabitants.size() < capacity) {
  	for (size_t i = 0; i < _inhabitants.size(); ++i) {
      if (value == _inhabitants[i]) {
        return 0;
	  }
	}
    _inhabitants.push_back(value);
  }
  return 0;
}

size_t Building::remove_inhabitant() {
  if (!_inhabitants.empty()) {
    _inhabitants.erase(_inhabitants.begin() + _inhabitants.size() - 1);
  }
  return 0;
}

size_t Building::remove_inhabitant(size_t index) {
  if (index < _inhabitants.size()) {
    _inhabitants.erase(_inhabitants.begin() + index);
  }
  return 0;
}

size_t Building::add_employee(size_t value) {
  size_t capacity;
  _kind.get_max_employees(capacity);
  if (_employees_id.size() < capacity) {
  	for (size_t i = 0; i < _employees_id.size(); ++i) {
      if (value == _employees_id[i]) {
        return 0;
	  }
    }
    _employees_id.push_back(value);
  }
  return 0;
}

size_t Building::remove_employee() {
  if (!_employees_id.empty()) {
    _employees_id.erase(_employees_id.begin() + _employees_id.size() - 1);
  }
  return 0;
}

size_t Building::remove_employee(size_t index) {
  if (index < _employees_id.size()) {
    _employees_id.erase(_employees_id.begin() + index);
  }
  return 0;
}

size_t Building::what(std::string& out) {
  out.clear();
  return 0;
}

size_t Building::turn(/*args will be added here*/) {
  if (_building_time > BUILD_DONE) {
    --_building_time;
  } else {
    //code here describing what will building do during the turn. Possibly needs derivative classes, or some more tinkering on Type Object pattern.
  }
  return 0;
}
