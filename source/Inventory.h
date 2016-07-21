#ifndef INVENTORY_H
#define INVENTORY_H

#include<stdint.h>
#include<string>
#include<vector>

#include "prototypes.h"
#include "Item.h"
#include "IngameStorage.h"

class Inventory {
  public:
    Inventory();
    Inventory(std::vector<prototypes::ItemTable> equipped);
    ~Inventory();
    size_t get_equipped(std::vector<Item*>& result);
    size_t get_equipped(size_t index, Item*& result);
    size_t get_bonuses(std::vector<size_t> result);
    size_t get_bonuses(size_t index, size_t& result);
    size_t get_save_data(std::vector<prototypes::ItemTable>& result);
    size_t set_equipped(std::vector<prototypes::ItemTable> value);
    size_t set_equipped(size_t index, Item* value);
    size_t set_equipped(size_t index, prototypes::ItemTable value);
    size_t what(std::string& out);
  protected:
    std::vector<Item*> _equipped;
};

#endif
