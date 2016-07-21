#include "Inventory.h"

Inventory::Inventory() {
  _equipped.clear();
  _equipped.resize(IS_SIZE);
  for (size_t i = 0; i < _equipped.size(); ++i) {
    _equipped[i] = NULL;
  }
}

Inventory::Inventory(std::vector<prototypes::ItemTable> equipped) {
  _equipped.clear();
  _equipped.resize(IS_SIZE);
  for (size_t i = 0; i < _equipped.size(); ++i) {
    _equipped[i] = NULL;
  }
  if (!equipped.empty()) {
    if (_equipped.size() == equipped.size()) {
      for (size_t i = 0; i < _equipped.size(); ++i) {
        _equipped[i] = new Item(equipped[i]);
      }
    }
  }
}

Inventory::~Inventory() {
  if (!_equipped.empty()) {
    for (size_t i = 0; i < _equipped.size(); ++i) {
      if (_equipped[i] != NULL) {
        delete _equipped[i];
      }
    }
    _equipped.clear();
  }
}

size_t Inventory::get_equipped(std::vector<Item*>& result) {
  result = _equipped;
  return 0;
}

size_t Inventory::get_equipped(size_t index, Item*& result) {
  if (index < _equipped.size()) {
    result = _equipped[index];
  }
  return 0;
}

size_t Inventory::get_bonuses(std::vector<size_t>& result) {
  result.clear();
  result.resize(SI_SIZE);
  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = SIZE_T_DEFAULT_VALUE;
  }
  for (size_t i = 0; i < _equipped.size(); ++i) {
    if (_equipped[i] > FREE_INDEX) {
      std::vector<size_t> tmp;
      tmp.clear();
      if (_equipped[i] != NULL) {
        _equipped[i]->get_bonuses(tmp);
      }
      if (tmp.size() == result.size()) {
        for (size_t j = 0; j < result.size(); ++j) {
          result[j] += tmp[j];
        }
      }
    }
  }
  return 0;
}

size_t Inventory::get_bonuses(size_t index, size_t& result) {
  result = 0;
  size_t response = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < _equipped.size(); ++i) {
    size_t tmp = 0;
    if (_equipped[i] != NULL) {
      response = _equipped[i]->get_bonuses(index, tmp);
    }
    result += tmp;
  }
  return response;
}

size_t Inventory::set_equipped(std::vector<prototypes::ItemTable> value) {
  if (!value.empty()) {
    if (!_equipped.empty()) {
      for (size_t i = 0; i < _equipped.size(); ++i) {
        if (_equipped[i] != NULL) {
          delete _equipped[i];
        }
      }
    }
    _equipped.clear();
    _equipped.resize(value.size());
    for (size_t i = 0; i < _equipped.size(); ++i) {
      _equipped[i] = NULL;
      _equipped[i] = new Item(value[i]);
    }
  }
  return 0;
}

size_t Inventory::set_equipped(size_t index, Item* value) {
  if (index < _equipped.size()) {
    _equipped[index] = value;
  }
  return 0;
}

size_t Inventory::set_equipped(size_t index, prototypes::ItemTable value) {
  if (index < _equipped.size()) {
    if (_equipped[index] == NULL) {
      _equipped[index] = new Item(value);
    }
  }
  return 0;
}

size_t Inventory::what(std::string& out) {
}
