#ifndef INGAME_STORAGE_H
#define INGAME_STORAGE_H

#include <cstdlib>
#include <ctime>
#include <direct.h>

#include "sqlite3.h"
#include "prototypes.h"
#include "TypeObjects.h"

class IngameStorage {
  public:
    IngameStorage();
    IngameStorage(const char* db_name);
    ~IngameStorage();
    size_t connect_database(const char* db_name);
    size_t close_database();
    size_t load_storage();
    size_t unload_storage();
    size_t get_item_table(size_t index, prototypes::ItemTable& result);
    size_t get_building_kind(size_t index, TypeBuilding& result);
    size_t get_profession(size_t index, TypeProfession& result);
    size_t form_name(bool gender, std::string& result);

    std::vector<TypeBuilding> _building_kinds;
    std::vector<TypeProfession> _professions;
    std::vector<prototypes::ItemTable> _items;

  protected:
    sqlite3* _database;
    std::vector<std::string> _male_nameparts_one;
    std::vector<std::string> _male_nameparts_two;
    std::vector<std::string> _female_nameparts_one;
    std::vector<std::string> _female_nameparts_two;

    size_t get_item_namedescr(size_t query_id, std::string& name, std::string& description);
    size_t get_item_bonuses(size_t query_id, std::vector<size_t>& bonuses);
    size_t get_item_penalties(size_t query_id, std::vector<size_t>& penalties);
    size_t get_item_slots(size_t query_id, std::vector<bool>& slots);
    size_t get_item_cost(size_t query_id, std::vector<size_t>& cost);
    size_t form_item_record(size_t query_id, struct prototypes::ItemTable& data);

    size_t get_nameparts(size_t query_id, bool gender);
};

#endif
