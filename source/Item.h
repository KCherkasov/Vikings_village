#ifndef ITEM_H
#define ITEM_H

#include "prototypes.h"

class Item {
  public:
    Item();
    Item(prototypes::ItemTable data);
    Item(prototypes::ItemTable data, size_t quality);
    ~Item() {}
    size_t get_name(std::string& result);
    size_t get_description(std::string& result);
    size_t get_cost(size_t& result[RI_SIZE]);
    size_t get_cost(size_t index, size_t& result);
    size_t get_bonuses(size_t& result[SI_SIZE]);
    size_t get_bonuses(size_t index, size_t& result);
    size_t get_penalties(size_t& result[SI_SIZE]);
    size_t get_penalties(size_t index, size_t& result);
    size_t get_slots(bool& result[IS_SIZE]);
    size_t get_slots(size_t index, bool& result);
    size_t get_quality(size_t& result);
    size_t get_save_data(prototypes::ItemTable& result);
    size_t set_name(std::string value);
    size_t set_description(std::string value);
    size_t set_cost(size_t value[RI_SIZE]);
    size_t set_cost(size_t index, size_t value);
    size_t set_bonuses(size_t value[SI_SIZE]);
    size_t set_bonuses(size_t index, size_t value);
    size_t set_penalties(size_t value[SI_SIZE]);
    size_t set_penalties(size_t index, size_t value);
    size_t set_slots(bool value[IS_SIZE]);
    size_t set_slots(size_t index, size_t value);
    size_t set_quality(size_t value);
    size_t what(std::string& out);
    size_t import_from_table(prototypes::ItemTable data);

  protected:
    std::string _name;
    std::string _description;
    size_t _cost[RI_SIZE];
    size_t _bonuses[SI_SIZE];
    size_t _penalties[SI_SIZE];
    size_t _quality;
    bool _slots[IS_SIZE];
};

#endif // ITEM_H

