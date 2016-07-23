#ifndef HUMAN_H
#define HUMAN_H

#include <stdint.h>
#include <vector>
#include <string>

#include "prototypes.h"
#include "TypeObjects.h"
#include "Inventory.h"

class Human {
  public:
    Human(TypeProfession& profession, bool gender, ssize_t house_id, std::string& name);
    Human(prototypes::HumanTable data, TypeProfession& profession);
    ~Human() {}
    size_t get_name(std::string& result);
    size_t get_combat_stats(bool with_items, std::vector<size_t>& result);
    size_t get_combat_stats(bool with_items, size_t index, size_t& result);
    size_t get_misc_stats(std::vector<size_t>& result);
    size_t get_misc_stats(size_t index, size_t& result);
    size_t get_skills(std::vector<size_t>& result);
    size_t get_skills(size_t index, size_t& result);
    size_t get_saga(std::vector<size_t>& result);
    size_t get_saga(size_t index, size_t& result);
    size_t get_age(size_t& result);
    size_t get_house_id(ssize_t& result);
    size_t get_profession(TypeProfession& result);
    size_t get_inventory(Inventory& result);
    size_t get_inventory(std::vector<prototypes::ItemTable>& result);
    size_t get_inventory(size_t index, prototypes::ItemTable& result)
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
    size_t set_age(size_t value);
    size_t set_house_id(ssize_t value);
    size_t set_profession(TypeProfession& value);
    size_t set_inventory(Inventory& value);
    size_t set_inventory(std::vector<prototypes::ItemTable> value);
    size_t set_inventory(size_t index, prototypes::ItemTable value);
    size_t set_inventory(size_t index, Item* value);
    size_t set_gender(bool value);
    size_t what(std::string& out);
    size_t consume(); //add there argument - either std::vector<size_t> or Village class
    size_t add_to_saga(size_t index, size_t value);
    size_t wound();
    size_t increase_combat_stat(size_t index);
    size_t increase_combat_stat(size_t index, size_t value);
    size_t increase_misc_stat(size_t index);
    size_t increase_misc_stat(size_t index, size_t value);
    size_t increase_skill(size_t index);
    size_t increase_skill(size_t index, size_t value);
    size_t increase_age();
    size_t decrease_combat_stat(size_t index);
    size_t decrease_combat_stat(size_t index, size_t value);
    size_t decrease_misc_stat(size_t index);
    size_t decrease_misc_stat(size_t index, size_t value);
    size_t decrease_skill(size_t index);
    size_t decrease_skill(size_t index, size_t value);

    Human& operator = (Human& lhs, const Human& rhs) {
      if (!lhs._name.empty()) {
        lhs._name.clear();
      }
      lhs._name = rhs._name;
      if (!lhs._combat_stats.empty()) {
        lhs._combat_stats.clear();
      }
      lhs._combat_stats = rhs._combat_stats;
      if (!lhs._misc_stats.empty()) {
        lhs._misc_stats.clear();
      }
      lhs._misc_stats = rhs._misc_stats;
      if (!lhs._skills.empty()) {
        lhs._skills.clear();
      }
      lhs._skills = rhs._skills;
      if (!lhs._saga.empty()) {
        lhs._saga.clear();
      }
      lhs._saga = rhs._saga;
      lhs._age = rhs._age;
      lhs._house_id = rhs._house_id;
      lhs._profession = rhs._profession;
      lhs._inventory = rhs._inventory;
      lhs._gender = rhs._gender;
      return lhs;
    }

  protected:
    std::string _name;
    std::vector<size_t> _combat_stats;
    std::vector<size_t> _misc_stats;
    std::vector<size_t> _skills;
    std::vector<size_t> _saga;
    size_t _age;
    ssize_t _house_id;
    TypeProfession& _profession;
    Inventory _inventory;
    bool _gender;
};

#endif
