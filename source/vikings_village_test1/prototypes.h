#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include <stdint.h>
#include <vector>
#include <string>
#include <sstream>


const size_t SIZE_T_DEFAULT_VALUE = 0;
const ssize_t SSIZE_T_DEFAULT_VALUE = -1;
const bool BOOL_DEFAULT_VALUE = false;

const size_t NAMEPARTS_COUNT = 2;

const size_t COMMON_CHANCE = 75;
const size_t GOOD_CHANCE = 25;
const size_t RARE_CHANCE = 13;
const size_t EPIC_CHANCE = 6;
const size_t LEGENDARY_CHANCE = 3;

const size_t BUILD_DONE = 0;
const size_t RAID_END = 0;

const size_t MAX_BUILDINGS = 100;
const size_t MAX_PEOPLE_ID = 9999999;
const size_t MAX_PRODUCTION_QUEUE_SIZE = 15;

const ssize_t FREE_INDEX = -1;

const size_t DIGIT_STRING_SIZE = 3;

const size_t BASE_WOUNDS = 1;
const size_t DEATH_WOUND = 0;

const size_t BASE_MALE_COMBAT_STAT = 20;
const size_t BASE_FEMALE_COMBAT_STAT = 15;

const size_t BASE_MISC_STAT = 30;
const size_t BASE_SKILL = 10;

const size_t BASE_AGE = 12;
const size_t AGE_SEED = 25;

const size_t YOUNG_STEP = 13;
const size_t OLD_STEP = 40;

const size_t SHIP_SLOT_FOOD_CAPACITY = 50;
const size_t SHIP_SLOT_GOLD_CAPACITY = 100;
const size_t SHIP_SLOT_IRON_CAPACITY = 50;
const size_t SHIP_SLOT_LEATHER_CAPACITY = 25;
const size_t SHIP_SLOT_WOOD_CAPACITY = 10;
const size_t SHIP_SLOT_HUMAN_CAPACITY = 1;
const size_t SHIP_SLOT_ITEM_CAPACITY = 10;

const size_t BASE_SEED = 15;

const size_t MIN_STAT_VALUE = 0;
const size_t MAX_STAT_VALUE = 100;

const size_t MAX_PLANK_VALUE = 90;
const size_t BASE_PLANK_VALUE = 50;
const size_t MIN_PLANK_VALUE = 10;

const size_t BASE_DEATH_CHANCE = 80;
const size_t BASE_DROP_CHANCE = 40;

const size_t CHANCE_UPPER_CAP = 100;
const size_t CHANCE_LOWER_CAP = 0;

const size_t ITEMS_COUNT = 23;

const bool MALE_GENDER = true;
const bool FEMALE_GENDER = false;

const bool FREEMEN_STATE = true;
const bool SLAVE_STATE = false;

const size_t MALE_GENDER_CHANCE = 50;

const size_t SUCCESS_FAIL_RANGE = 15;

enum ItemQuality { IQ_THRASH, IQ_COMMON, IQ_GOOD, IQ_RARE, IQ_EPIC, IQ_LEGENDARY, IQ_SIZE };

enum PersonalSaga { PS_RAIDS, PS_KILLED, PS_LOOTED, PS_ENSLAVED, PS_SIZE };
enum StatsIndexes { SI_WOUNDS, SI_MELEE, SI_RANGED, SI_DEFENSE, SI_INITIATIVE, SI_SIZE };
enum MiscIndexes { MI_SAILORSHIP, MI_LOYALTY, MI_MORALE, MI_SIZE };
enum ProfessionIndexes { PI_UNEMPLOYED, PI_LUMBERJACK, PI_BLACKSMITH, PI_BUILDER, PI_LEATHERWORKER, PI_FISHER, PI_FARMER, PI_WARRIOR, PI_HUSCARL, PI_MINER, PI_PRIEST, PI_SKALD, PI_TRADER, PI_SIZE };
enum InventorySlots { IS_HEAD, IS_BODY, IS_ARMS, IS_LEGS, IS_RIGHT_HAND, IS_LEFT_HAND, IS_RANGED, IS_SIZE };

enum ResourcesIndexes { RI_GOLD, RI_FOOD, RI_WOOD, RI_IRON, RI_LEATHER, RI_SIZE };

enum TermsIndexes { TI_PAYMENT, TI_SHARE, TI_SHIP_COST, TI_FOOD_COST, TI_SIZE };
enum RaidStages { RS_THERE, RS_LAND, RS_BACK, RS_SIZE };

enum EventDescriptions { ED_DESCRIPTION, ED_SUCCESS, ED_NORMAL, ED_FAILURE, ED_SIZE };
enum EventOutcomes { EO_SUCCESS, EO_NORMAL, EO_FAILURE, EO_SIZE };

enum BattleOutcome { BO_RAIDERS_WON, BO_LOCALS_WON, BO_SIZE };
enum FightOutcome {FO_RAIDER_WON, FO_LOCAL_WON, FO_SIZE};
enum BattleStage { BS_RANGED, BS_THROWING, BS_MELEE, BS_SIZE };

namespace prototypes {

  struct TypeBuildingTable {
    public:
      size_t _name_size;
      std::string _name;
      size_t _description_size;
      std::string _description;
      std::vector<size_t> _cost;
      std::vector<size_t> _resources;
      size_t _max_employees;
      size_t _building_time;
      size_t _living_space;
      size_t _id;
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
        if (!_resources.empty()) {
          _resources.clear();
        }
        _resources = rhs._resources;
        _max_employees = rhs._max_employees;
        _building_time = rhs._building_time;
        _living_space = rhs._living_space;
        _id = rhs._id;
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
      ssize_t _owner_id;

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
        _owner_id = rhs._owner_id;
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
      size_t _age;
      size_t _own_id;
      ssize_t _house_id;
      ssize_t _profession_id;
      bool _gender;
      bool _is_slave;

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
        _age = rhs._age;
        _own_id = rhs._own_id;
        _equipment = rhs._equipment;
        _house_id = rhs._house_id;
        _profession_id = rhs._profession_id;
        _gender = rhs._gender;
        _is_slave = rhs._is_slave;
        return *this;
      }
  };
  
  struct BuildingTable{
  	public:
      size_t _kind_id;
  	  size_t _employees_count;
      std::vector<size_t> _employees_id;
      size_t _inhabitants_count;
      std::vector<size_t> _inhabitants;
      size_t _queue_size;
      std::vector<size_t> _production_queue;
      size_t _building_time;
    
      BuildingTable& operator = (const BuildingTable& rhs) {
        _kind_id = rhs._kind_id;
        _employees_count = rhs._employees_count;
        if (!_employees_id.empty()) {
       	  _employees_id.clear();
	    }
	    _employees_id = rhs._employees_id;
	    _inhabitants_count = rhs._inhabitants_count;
	    if (!_inhabitants.empty()) {
          _inhabitants.clear();
	    }
	    _inhabitants = rhs._inhabitants;
	    _queue_size = rhs._queue_size;
	    if (!_production_queue.empty()) {
          _production_queue.clear();
	    }
	    _production_queue = rhs._production_queue;
	    _building_time = rhs._building_time;
	    return *this;
	  }
  };

  struct RaidTable {
    public:
      size_t _stage;
      std::vector<size_t> _turns_left;
      std::vector<size_t> _terms;
      std::vector<size_t> _resources;
      size_t _participants_count;
      std::vector<HumanTable> _participants;
      size_t _slaves_count;
      std::vector<HumanTable> _slaves;
      size_t _loot_count;
      std::vector<ItemTable> _loot;
      
      RaidTable& operator = (const RaidTable& rhs) {
        _stage = rhs._stage;
        if (!_turns_left.empty()) {
          _turns_left.clear();
		}
		_turns_left = rhs._turns_left;
        if (!_terms.empty()) {
          _terms.clear();
		}
		_terms = rhs._terms;
		if (!_resources.empty()) {
          _resources.clear();
		}
		_resources = rhs._resources;
		_participants_count = rhs._participants_count;
		if (!_participants.empty()) {
          _participants.clear();
		}
		_participants = rhs._participants;
		_slaves_count = rhs._slaves_count;
		if (_slaves.empty()) {
          _slaves.clear();
		}
		_slaves = rhs._slaves;
		_loot_count = rhs._loot_count;
		if (!_loot.empty()) {
          _loot.clear();
		}
		_loot = rhs._loot;
		return *this;
	  }
  };
  
  struct VillageTable {
  	public:
      size_t _name_size;
      std::string _name;
      std::vector<size_t> _resources;
      size_t _villagers_count;
      std::vector<HumanTable> _villagers;
      size_t _buildings_count;
      std::vector<BuildingTable> _buildings;
      size_t _items_count;
      std::vector<ItemTable> _items;
      
      VillageTable& operator = (const VillageTable& rhs) {
        _name_size = rhs._name_size;
        if (!_name.empty()) {
          _name.clear();
		}
		_name = rhs._name;
		if (!_resources.empty()) {
          _resources.clear();
		}
		_resources = rhs._resources;
		_villagers_count = rhs._villagers_count;
		if (!_villagers.empty()) {
	      _villagers.clear();
		}
		_villagers = rhs._villagers;
		_items_count = rhs._items_count;
		if(!_items.empty()) {
          _items.clear();
		}
		_items = rhs._items;
		return *this;
	  }
  };
}

template<class T>
size_t convert_to_string(const T& value, std::string& result) {
  std::ostringstream converter;
  converter << value;
  result += converter.str();
  return 0;
}

template<class T>
size_t convert_from_string(const std::string& source, T& result) {
  std::istringstream converter(source);
  converter >> result;
  return 0;
}

using namespace prototypes;

#endif
