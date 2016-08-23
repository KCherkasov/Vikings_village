#ifndef ITEM_H
#define ITEM_H

#include <cmath>
#include <cstdlib>
#include <stdint.h>

#include "prototypes.h"

class Item {
  public:
    Item();
    Item(prototypes::ItemTable data);
    Item(prototypes::ItemTable data, size_t quality);
    Item(prototypes::ItemTable data, size_t quality, ssize_t owner_id);
    ~Item() {}
    size_t get_name(std::string& result);
    size_t get_description(std::string& result);
    size_t get_cost(std::vector<size_t>& result);
    size_t get_cost(size_t index, size_t& result);
    size_t get_bonuses(std::vector<size_t>& result);
    size_t get_bonuses(size_t index, size_t& result);
    size_t get_penalties(std::vector<size_t>& result);
    size_t get_penalties(size_t index, size_t& result);
    size_t get_quality(size_t& result);
    size_t get_slots(std::vector<bool>& result);
    size_t get_slots(size_t index, bool& result);
    size_t get_owner_id(ssize_t& result);
    size_t get_save_data(prototypes::ItemTable& result);
    size_t set_name(std::string value);
    size_t set_description(std::string value);
    size_t set_cost(std::vector<size_t> value);
    size_t set_cost(size_t index, size_t value);
    size_t set_bonuses(std::vector<size_t> value);
    size_t set_bonuses(size_t index, size_t value);
    size_t set_penalties(std::vector<size_t> value);
    size_t set_penalties(size_t index, size_t value);
    size_t set_quality(size_t value);
    size_t set_slots(std::vector<bool> value);
    size_t set_slots(size_t index, bool value);
    size_t set_owner_id(ssize_t value);
    size_t what(std::string& out);
    size_t import_from_table(prototypes::ItemTable data);

    Item& operator = (const Item& rhs) {
      if (!_name.empty()) {
        _name.clear();
      }
      _name = rhs._name;
      if (!_description.empty()) {
        _description.clear();
      }
      _description = rhs._description;
      if (!_cost.empty()) {
        _cost.clear();
      }
      _cost = rhs._cost;
      if (!_bonuses.empty()) {
        _bonuses.clear();
      }
      _bonuses = rhs._bonuses;
      if (!_penalties.empty()) {
        _penalties.clear();
      }
      _penalties = rhs._penalties;
      _quality = rhs._quality;
      if (!_slots.empty()) {
        _slots.clear();
      }
      _slots = rhs._slots;
      _owner_id =rhs._owner_id;
      return *this;
    }

  protected:
    std::string _name;
    std::string _description;
    std::vector<size_t> _cost;
    std::vector<size_t> _bonuses;
    std::vector<size_t> _penalties;
    size_t _quality;
    std::vector<bool> _slots;
    ssize_t _owner_id;
};

#endif // ITEM_H

