#ifndef ITEM_H
#define ITEM_H

#include "prototypes.h"

class Item {
  public:
    Item();
    Item(prototypes::ItemTable data);
    ~Item() {}
    size_t get_name(std::string& result);
    size_t get_description(std::string& result);
    size_t get_cost(std::vector<size_t>& result);
    size_t get_cost(size_t index, size_t& result);
    size_t get_bonuses(std::vector<size_t>& result);
    size_t get_bonuses(size_t index, size_t& result);
    size_t get_penalties(std::vector<size_t>& result);
    size_t get_penalties(size_t index, size_t& result);
    size_t get_slots(std::vector<bool>& result);
    size_t get_slots(size_t index, bool& result);
    size_t set_name(std::string value);
    size_t set_description(std::string value);
    size_t set_cost(std::vector<size_t> value);
    size_t set_cost(size_t index, size_t value);
    size_t set_bonuses(std::vector<size_t> value);
    size_t set_bonuses(size_t index, size_t value);
    size_t set_penalties(std::vector<size_t> value);
    size_t set_penalties(size_t index, size_t value);
    size_t set_slots(std::vector<bool> value);
    size_t set_slots(size_t index, size_t value);
    size_t what(std::string& out);
  protected:
    std::string _name;
    std::string _description;
    std::vector<size_t> _cost;
    std::vector<size_t> _bonuses;
    std::vector<size_t> _penalties;
    std::vector<bool> _slots;
};

#endif // ITEM_H

