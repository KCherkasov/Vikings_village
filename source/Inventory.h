#ifndef INVENTORY_H
#define INVENTORY_H

#include "prototypes.h"
#include "Item.h"
#include "IngameStorage.h"

class Inventory {
  public:
    Inventory();
    Inventory(std::vector<size_t> equipped);
    ~Inventory() {}
    size_t get_equipped(std::vector<size_t>& result);
    size_t get_equipped(size_t index, size_t& result);
    size_t get_bonuses(CombatStats& result, IngameStorage storage);
    size_t get_bonuses_wounds(size_t& result, IngameStorage storage);
    size_t get_bonuses_melee(size_t& result, IngameStorage storage);
    size_t get_bonuses_ranged(size_t& result, IngameStorage storage);
    size_t get_bonuses_defense(size_t& result, IngameStorage storage);
    size_t get_bonuses_initiative(size_t& result, IngameStorage storage);
    size_t set_equipped(std::vector<size_t> value);
    size_t set_equipped(size_t index, size_t value);
    size_t what(std::string& out, IngameStorage storage);
  protected:
    std::vector<size_t> _equipped;
};

#endif
