#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include <cstdint>
#include <vector>
#include <string>
#include <pair>


const signed size_t FREE_INDEX = -1;

const size_t BASE_WOUNDS = 1;
const size_t DEATH_WOUND = 0;

const size_t BASE_MALE_COMBAT_STAT = 20;
const size_t BASE_FEMALE_COMBAT_STAT = 15;

const size_t BASE_SEED = 15;

const size_t MAX_STAT_VALUE = 100;

enum StatsIndexes { SI_WOUNDS, SI_MELEE, SI_RANGED, SI_DEFENSE, SI_INITIATIVE, SI_SIZE };
enum ProfessionIndexes { PI_UNEMPLOYED, PI_LUMBERJACK, PI_BLACKSMITH, PI_BUILDER, PI_LEATHERWORKER, PI_FISHER, PI_FARMER, PI_WARRIOR, PI_HUSCARL PI_MINER, PI_PRIEST, PI_SKALD, PI_TRADER, PI_SIZE };
enum InventorySlots { IS_HEAD, IS_BODY, IS_ARMS, IS_LEGS, IS_RIGHT_HAND, IS_LEFT_HAND, IS_RANGED, IS_SIZE };

enum ResourcesIndexes { RI_GOLD, RI_FOOD, RI_WOOD, RI_IRON, RI_LEATHER, RI_SIZE };

namespace prototypes {

  struct TypeBuildingTable {
    std::string _name;
    std::string _description;
    std::vector<size_t> _cost;
    std::vector<size_t> _max_employees;
    std::vector<size_t> _resources;
    size_t _building_time;
    std::vector<bool> _producable;
  };

  struct TypeProfessionTable {
    std::string _name;
    std::string _description;
    std::vector<size_t> _consumation;
    bool _can_slave;
  };

  struct ItemTable {
    std::string _name;
    std::string _description;
    std::vector<size_t> _cost;
    std::vector<size_t> _bonuses;
    std::vector<size_t> _penalties;
    std::vector<bool> _slots;
  };

}

using namespace prototypes;

#endif
