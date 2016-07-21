#include "Inventory.h"

Inventory::Inventory() {
  _equipped = {NULL};
}

Inventory::Inventory(prototypes::ItemTable* equipped) {
  if (equipped != NULL) {
    for (size_t i = 0; i < IS_SIZE; ++i) {
      _equipped[i] = new Item(equipped[i]);
    }
  }
}

Inventory::~Inventory() {
  for (size_t i = 0; i < IS_SIZE; ++i) {
    if (_equipped[i] != NULL) {
      delete _equipped[i];
    }
  }
}

size_t Inventory::get_equipped(prototypes::ItemTable*& result) {
  if (result == NULL) {
    result = new prototypes::ItemTable[IS_SIZE];
  }
  for (size_t i = 0; i < IS_SIZE; ++i) {
    result[i]._name.clear();
    result[i]._description.clear();
    result[i]._bonuses = {SIZE_T_DEFAULT_VALUE};
    result[i]._penalties = {SIZE_T_DEFAULT_VALUE};
    result[i]._cost = {BOOL_DEFAULT_VALUE};
    result[i]._slots = {SIZE_T_DEFAULT_VALUE};
    result[i]._quality = IQ_COMMON;
    if (_equipped[i] != NULL) {
      _equipped[i]->get_save_data(result[i]);
    }
  }
  return 0;
}

size_t Inventory::get_equipped(size_t index, Item*& result) {
  if (index < _equipped.size()) {
    result = _equipped[index];
  }
  return 0;
}

size_t Inventory::get_bonuses(size_t*& result) {
  delete[] result
  result = new size_t[SI_SIZE] {SIZE_T_DEFAULT_VALUE};
  for (size_t i = 0; i < IS_SIZE; ++i) {
    if (_equipped[i] != NULL) {
      size_t* tmp = NULL;
      _equipped[i]->get_bonuses(tmp);
      if (tmp != NULL && result != NULL) {
        for (size_t j = 0; j < SI_SIZE; ++j) {
          result[j] += tmp[j];
        }
      }
    }
  }
  return 0;
}

size_t Inventory::get_bonuses(size_t index, size_t& result) {
  result = 0;
  for (size_t i = 0; i < IS_SIZE; ++i) {
    if (_equipped[i] != NULL) {
      size_t tmp = 0;
      _equipped[i]->get_bonuses(index, tmp);
      result += tmp;
    }
  }
  return 0;
}

size_t Inventory::set_equipped(prototypes::ItemTable* value) {
  if (value != NULL) {
    for (size_t i = 0; i < IS_SIZE; ++i) {
      if (_equipped[i] != NULL) {
        delete _equipped[i];
      }
      _equipped[i] = new Item(value[i]);
    }
  }
  return 0;
}

size_t Inventory::set_equipped(size_t index, Item* value) {
  if (index < IS_SIZE) {
    if (_equipped[index] == NULL) {
      _equipped[index] = value;
    } else {
      Item* buffer = value;
      value = _equipped[index];
      _equipped[index] = buffer;
      buffer = NULL;
    }
  }
  return 0;
}

size_t Inventory::what(std::string& out) {
  return 0;
}
