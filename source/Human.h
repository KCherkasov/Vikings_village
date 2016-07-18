#ifndef HUMAN_H
#define HUMAN_H

#include <stdint.h>
#include <vector>
#include <string>

#include "prototypes.h"
#include "TypeObjects.h"
#include "Inventory.h"
#include "IngameStorage.h"

class Human {
  public:
    Human(IngameStorage& storage);
    Human(prototypes::HumanTable data);
    ~Human() {}
    size_t get_name(std::string& result);
    size_t get_combat_stats(bool with_items, IngameStorage& storage, std::vector<size_t>& result);
    size_t get_combat_stats(bool with_items, IngameStorage& storage, size_t index, size_t& result);
    size_t get_misc_stats(std::vector<size_t>& result);
    size_t get_misc_stats(size_t index, size_t& result);
    size_t get_skills(std::vector<size_t>& result);
    size_t get_skills(size_t index, size_t& result);
    size_t get_saga(std::vector<size_t>& result);
    size_t get_saga(size_t index, size_t& result);
    size_t get_house_id(ssize_t& result);
    size_t get_profession(TypeProfession& result);
    size_t get_inventory(Inventory& result);
    size_t get_inventory(std::vector<ssize_t>& result);
    size_t get_inventory(size_t index, ssize_t& result);
    size_t get_gender(bool& result);
    size_t get_save_data(prototypes::HumanTable& result);
    size_t set_name(std::string value);
    size_t set_combat_stats(std::vector<size_t> value);
    size_t set_combat_stats(size_t index, size_t value);
    size_t set_misc_stats(std::vector<size_t> value);
    size_t set_misc_stats(size_t index, size_t value);
    size_t set_skills(std::vector<size_t> value);
    size_t set_skills(size_t index, size_t value);
    size_t set_saga(std::vector<size_t> value);
    size_t set_saga(size_t index, size_t value);
    size_t set_house_id(ssize_t value);
    size_t set_inventory(Inventory value);
    size_t set_inventory(std::vector<ssize_t> value);
    size_t set_inventory(size_t index, ssize_t value);
    size_t set_gender(bool value);
    size_t what(std::string& out);
    size_t change_equipment(size_t slot, ssize_t item_index);
    size_t consume();
    size_t add_to_saga(size_t index, size_t value);
    size_t wound();
    size_t increase_combat_stat(size_t index);
    size_t increase_combat_stat(size_t index, size_t value);
    size_t increase_misc_stat(size_t index);
    size_t increase_misc_stat(size_t index, size_t value);
    size_t decrease_combat_stat(size_t index);
    size_t decrease_combat_stat(size_t index, size_t value);
    size_t decrease_misc_stat(size_t index);
    size_t decrease_misc_stat(size_t index, size_t value);
    size_t raise_skill(size_t index);
    size_t raise_skill(size_t index, size_t value);

  protected:
    std::string _name;
    std::vector<size_t> _combat_stats;
    std::vector<size_t> _misc_stats;
    std::vector<size_t> _skills;
    std::vector<size_t> _saga;
    ssize_t _house_id;
    TypeProfession& _profession;
    Inventory _inventory;
    bool _gender;
};

#endif
