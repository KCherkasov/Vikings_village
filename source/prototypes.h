#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include <stdint.h>
#include <vector>
#include <string>
#include <pair>

const size_t SIZE_T_DEFAULT_VALUE = 0;
const ssize_t SSIZE_T_DEFAULT_VALUE = -1;
const bool BOOL_DEFAULT_VALUE = false;

const ssize_t FREE_INDEX = -1;

const size_t DIGIT_STRING_SIZE = 3;

const size_t BASE_WOUNDS = 1;
const size_t DEATH_WOUND = 0;

const size_t BASE_MALE_COMBAT_STAT = 20;
const size_t BASE_FEMALE_COMBAT_STAT = 15;

const size_t BASE_SEED = 15;

const size_t MIN_STAT_VALUE = 0;
const size_t MAX_STAT_VALUE = 100;

const size_t CHANCE_UPPER_CAP = 100;
const size_t CHANCE_LOWER_CAP = 0;

const size_t ITEMS_COUNT = 23;

const bool MALE_GENDER = true;
const bool FEMALE_GENDER = false;

const size_t MALE_GENDER_CHANCE = 50;

enum ItemQuality { IQ_THRASH, IQ_COMMON, IQ_GOOD, IQ_RARE, IQ_EPIC, IQ_LEGENDARY, IQ_SIZE };

enum PersonalSaga { PS_RAIDS, PS_KILLED, PS_LOOTED, PS_ENSLAVED, PS_SIZE };
enum StatsIndexes { SI_WOUNDS, SI_MELEE, SI_RANGED, SI_DEFENSE, SI_INITIATIVE, SI_SIZE };
enum MiscIndexes { MI_SAILORSHIP, MI_LOYALTY, MI_MORALE, MI_SIZE };
enum ProfessionIndexes { PI_UNEMPLOYED, PI_LUMBERJACK, PI_BLACKSMITH, PI_BUILDER, PI_LEATHERWORKER, PI_FISHER, PI_FARMER, PI_WARRIOR, PI_HUSCARL PI_MINER, PI_PRIEST, PI_SKALD, PI_TRADER, PI_SIZE };
enum InventorySlots { IS_HEAD, IS_BODY, IS_ARMS, IS_LEGS, IS_RIGHT_HAND, IS_LEFT_HAND, IS_RANGED, IS_SIZE };

enum ResourcesIndexes { RI_GOLD, RI_FOOD, RI_WOOD, RI_IRON, RI_LEATHER, RI_SIZE };

namespace prototypes {

  struct TypeBuildingTable {
    public:
      size_t _name_size;
      std::string _name;
      size_t _description_size;
      std::string _description;
      std::vector<size_t> _cost;
      std::vector<size_t> _max_employees;
      std::vector<size_t> _resources;
      size_t _building_time;
      std::vector<bool> _producable;

      TypeBuildingTable& operator = (TypeBuildingTable& lhs, const TypeBuildingTable& rhs) {
        lhs._name_size = rhs._name_size;
        if (!lhs._name.empty()) {
          lhs._name.clear();
        }
        lhs._name = rhs._name;
        lhs._description_size = rhs._description_size;
        if (!lhs._description.empty()) {
          lhs._description.clear();
        }
        lhs._description = rhs._description;
        if(!lhs._cost.empty()) {
          lhs._cost.clear();
        }
        lhs._cost = rhs._cost;
        if(!lhs._max_employees.empty()) {
          lhs._max_employees.clear();
        }
        lhs._max_employees = rhs._max_employees;
        if (!lhs._resources.empty()) {
          lhs._resources.clear();
        }
        lhs._resources = rhs._resources;
        lhs._building_time = rhs._building_time;
        if (!lhs._producable.empty()) {
          lhs._producable.clear();
        }
        lhs._producable = rhs._producable;
        return lhs;
      }
  };

  struct TypeProfessionTable {
    public:
      size_t _name_size;
      std::string _name;
      size_t _description_size;
      std::string _description;
      std::vector<size_t> _consumation;
      bool _can_slave;

      TypeProfessionTable& operator = (TypeProfessionTable& lhs, const TypeProfessionTable& rhs) {
        lhs._name_size = rhs._name_size;
        if (!lhs._name.empty()) {
          lhs._name.clear();
        }
        lhs._name = rhs._name;
        lhs._description_size = rhs._description_size;
        if (!lhs._description.empty()) {
          lhs._description.clear();
        }
        lhs._description = rhs._description;
        if (!lhs._consumation.empty()) {
          lhs._consumation.clear();
        }
        lhs._consumation = rhs._consumation;
        lhs._can_slave = rhs._can_slave;
        return lhs;
      }
  };

  struct ItemTable {
    public:
      size_t _name_size;
      std::string _name;
      size_t _description_size;
      std::string _description;
      std::vector<size_t> _cost;
      std::vector<size_t> _bonuses;
      std::vector<size_t> _penalties;
      size_t _quality;
      std::vector<bool> _slots;
      bool _is_players;

      ItemTable& operator = (ItemTable& lhs, const ItemTable& rhs) {
        lhs._name_size = rhs._name_size;
        if (!lhs._name.empty()) {
          lhs._name.clear();
        }
        lhs._name =rhs._name;
        lhs._description_size = rhs._description_size;
        is (!lhs._description.empty()) {
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
        lhs._is_players = rhs._is_players;
        return lhs;
      }
  };

  struct HumanTable {
    public:
      size_t _name_size;
      std::string _name;
      std::vector<size_t> _combat_stats;
      std::vector<size_t> _misc_stats;
      std::vector<size_t> _skills;
      std::vector<size_t> _saga;
      std::vector<ItemTable> _equipment;
      ssize_t _house_id;
      ssize_t _profession_id;
      bool _gender;

      HumanTable& operator = (HumanTable& lhs, const HumanTable& rhs) {
        lhs._name_size = rhs._name_size;
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
        if (!lhs._equipment.empty()) {
          lhs._equipment.clear();
        }
        lhs._equipment = rhs._equipment;
        lhs._house_id = rhs._house_id;
        lhs._profession_id = rhs._profession_id;
        lhs._gender = rhs._gender;
        return lhs;
      }
  };
}

using namespace prototypes;

#endif
