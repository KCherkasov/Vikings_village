#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include <stdint.h>
#include <vector>
#include <string>


const size_t SIZE_T_DEFAULT_VALUE = 0;
const ssize_t SSIZE_T_DEFAULT_VALUE = -1;
const bool BOOL_DEFAULT_VALUE = false;

const ssize_t FREE_INDEX = -1;

const size_t DIGIT_STRING_SIZE = 3;

const size_t BASE_WOUNDS = 1;
const size_t DEATH_WOUND = 0;

const size_t BASE_MALE_COMBAT_STAT = 20;
const size_t BASE_FEMALE_COMBAT_STAT = 15;

const size_t BASE_MISC_STAT = 30;
const size_t BASE_SKILL = 10;

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
enum ProfessionIndexes { PI_UNEMPLOYED, PI_LUMBERJACK, PI_BLACKSMITH, PI_BUILDER, PI_LEATHERWORKER, PI_FISHER, PI_FARMER, PI_WARRIOR, PI_HUSCARL, PI_MINER, PI_PRIEST, PI_SKALD, PI_TRADER, PI_SIZE };
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

      TypeBuildingTable& operator = (const TypeBuildingTable& rhs) {
        _name_size = rhs._name_size;
        if (!_name.empty()) {
          _name.clear();
        }
        _name = rhs._name;
        _description_size = rhs._description_size;
        if (!_description.empty()) {
          _description.clear();
        }
        _description = rhs._description;
        if(!_cost.empty()) {
          _cost.clear();
        }
        _cost = rhs._cost;
        if(!_max_employees.empty()) {
          _max_employees.clear();
        }
        _max_employees = rhs._max_employees;
        if (!_resources.empty()) {
          _resources.clear();
        }
        _resources = rhs._resources;
        _building_time = rhs._building_time;
        if (!_producable.empty()) {
          _producable.clear();
        }
        _producable = rhs._producable;
        return *this;
      }
  };

  struct TypeProfessionTable {
    public:
      size_t _name_size;
      std::string _name;
      size_t _description_size;
      std::string _description;
      std::vector<size_t> _consumation;
      size_t _id;
      bool _can_slave;

      TypeProfessionTable& operator = (const TypeProfessionTable& rhs) {
        _name_size = rhs._name_size;
        if (!_name.empty()) {
          _name.clear();
        }
        _name = rhs._name;
        _description_size = rhs._description_size;
        if (!_description.empty()) {
          _description.clear();
        }
        _description = rhs._description;
        if (!_consumation.empty()) {
          _consumation.clear();
        }
        _consumation = rhs._consumation;
        _id = rhs._id;
        _can_slave = rhs._can_slave;
        return *this;
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

      ItemTable& operator = (const ItemTable& rhs) {
        _name_size = rhs._name_size;
        if (!_name.empty()) {
          _name.clear();
        }
        _name =rhs._name;
        _description_size = rhs._description_size;
        if (!_description.empty()) {
          _description.clear();
        }
        _description = rhs._description;
        if (!_cost.empty()) {
          _cost.clear();
        }
        _cost = rhs._cost;
        if (!_bonuses.empty()) {
          _bonuses.clear();
        }
        _bonuses = rhs._bonuses;
        if (!_penalties.empty()) {
          _penalties.clear();
        }
        _penalties = rhs._penalties;
        _quality = rhs._quality;
        if (!_slots.empty()) {
          _slots.clear();
        }
        _slots = rhs._slots;
        _is_players = rhs._is_players;
        return *this;
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

      HumanTable& operator = (const HumanTable& rhs) {
        _name_size = rhs._name_size;
        if (!_name.empty()) {
          _name.clear();
        }
        _name = rhs._name;
        if (!_combat_stats.empty()) {
          _combat_stats.clear();
        }
        _combat_stats = rhs._combat_stats;
        if (!_misc_stats.empty()) {
          _misc_stats.clear();
        }
        _misc_stats = rhs._misc_stats;
        if (!_skills.empty()) {
          _skills.clear();
        }
        _skills = rhs._skills;
        if (!_saga.empty()) {
          _saga.clear();
        }
        _saga = rhs._saga;
        if (!_equipment.empty()) {
          _equipment.clear();
        }
        _equipment = rhs._equipment;
        _house_id = rhs._house_id;
        _profession_id = rhs._profession_id;
        _gender = rhs._gender;
        return *this;
      }
  };
}

using namespace prototypes;

#endif
