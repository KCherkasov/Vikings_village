#ifndef INVENTORY_H
#define INVENTORY_H

#include<stdint.h>
#include<string>
#include<vector>

#include "prototypes.h"
#include "Item.h"

class Inventory {
  public:
    Inventory();
    Inventory(prototypes::ItemTable* equipped);
    ~Inventory();
    size_t get_equipped(prototypes::ItemTable*& result);
    size_t get_equipped(size_t index, Item*& result);
    size_t get_bonuses(size_t*& result);
    size_t get_bonuses(size_t index, size_t& result);
    size_t set_equipped(prototypes::ItemTable* value);
    size_t set_equipped(size_t index, Item* value);
    size_t what(std::string& out);
  protected:
    Item* _equipped[IS_SIZE];
};

#endif
