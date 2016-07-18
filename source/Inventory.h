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
    Inventory(std::vector<ssize_t> equipped);
    ~Inventory() {}
    size_t get_equipped(std::vector<size_t>& result);
    size_t get_equipped(size_t index, ssize_t& result);
    size_t get_bonuses(std::vector<size_t> result, IngameStorage& storage);
    size_t get_bonuses(size_t index, size_t& result, IngameStorage& storage);
    size_t set_equipped(std::vector<ssize_t> value);
    size_t set_equipped(size_t index, ssize_t value);
    size_t what(std::string& out, IngameStorage& storage);
  protected:
    std::vector<ssize_t> _equipped;
};

#endif
