#ifndef ITEM_H
#define ITEM_H

#include <cmath>
#include "prototypes.h"

class Item {
  public:
    Item();
    Item(prototypes::ItemTable data);
    Item(prototypes::ItemTable data, bool quality);
    Item(prototypes::ItemTable data, bool quality, bool is_players);
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
    size_t get_is_players(bool& result);
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
    size_t set_slots(size_t index, size_t value);
    size_t set_is_players(bool value)
    size_t what(std::string& out);
    size_t import_from_table(prototypes::ItemTable data);

    Item& operator = (Item& lhs, const Item& rhs) {
      if (!lhs._name.empty()) {
        lhs._name.clear();
      }
      lhs._name = rhs._name;
      if (!lhs._description.empty()) {
        lhs._description.clear();
      }
      lhs._description = rhs._description;
      if (!lhs._cost.empty()) {
        lhs._cost.clear();
      }
      lhs._cost = rhs._cost;
      if (!lhs._bonuses.empty()) {
        lhs._bonuses.clear();
      }
      lhs._bonuses = rhs._bonuses;
      if (!lhs._penalties.empty()) {
        lhs._penalties.clear();
      }
      lhs._penalties = rhs._penalties;
      lhs._quality = rhs._quality;
      if (!lhs._slots.empty()) {
        lhs._slots.clear();
      }
      lhs._slots = rhs._slots;
      lhs._is_players =rhs._is_players;
      return lhs;
    }

  protected:
    std::string _name;
    std::string _description;
    std::vector<size_t> _cost;
    std::vector<size_t> _bonuses;
    std::vector<size_t> _penalties;
    size_t _quality;
    std::vector<bool> _slots;
    bool _is_players;
};

#endif // ITEM_H

