#include "Inventory.h"

Inventory::Inventory() {
  _equipped.clear();
}

Inventory::Inventory(std::vector<ssize_t> equipped) {
  _equipped = equipped;
}

size_t Inventory::get_equipped(std::vector<ssize_t>& result) {
  result = _equipped;
  return 0;
}

size_t Inventory::get_equipped(size_t index, ssize_t& result) {
  if (index < _equipped.size()) {
    result = _equipped[index];
  }
  return 0;
}

size_t Inventory::get_bonuses(std::vector<size_t>& result, IngameStorage& storage) {
  result.clear();
  result.resize(SI_SIZE, 0);
  for (size_t i = 0; i < _equipped.size(); ++i) {
    if (_equipped[i] > FREE_INDEX) {
      std::vector<size_t> tmp;
      tmp.clear();
      Item item();
      storage.get_item(_equipped[i], item);
      item.get_bonuses(tmp);
      if (tmp.size() == result.size()) {
        for (size_t j = 0; j < result.size(); ++j) {
          result[j] += tmp[j];
        }
      }
    }
  }
  return 0;
}

size_t Inventory::get_bonuses(size_t index, size_t& result, IngameStorage& storage) {
  result = 0;
  for (size_t i = 0; i < _equipped.size(); ++i) {
    size_t tmp;
    Item item;
    storage.get_item(index, item);
    item.get_bonuses(index, tmp);
    result += tmp;
  }
  return 0;
}

size_t Inventory::set_equipped(std::vector<ssize_t> value) {
  _equipped = value;
  return 0;
}

size_t Inventory::set_equipped(size_t index, ssize_t value) {
  if (index < _equipped.size()) {
    _equipped[index] = value;
  }
  return 0;
}

size_t Inventory::what(std::string& out, IngameStorage& storage) {
}
