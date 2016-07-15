#ifndef INGAME_STORAGE_H
#define INGAME_STORAGE_H

#include <cstdlib>
#include <ctime>
#include <direct.h>

#include "sqlite3.h"
#include "prototypes.h"
#include "TypeObjects.h"
#include "Item.h"

class IngameStorage {
  public:
    IngameStorage();
    IngameStorage(const char* db_name);
    ~IngameStorage();
    size_t connect_database(const char* db_name);
    size_t close_database();
    size_t load_storage();
    size_t unload_storage();
    size_t get_item(size_t index, Item& result);
    size_t get_building_kind(size_t index, TypeBuilding& result);
    size_t get_profession(size_t index, TypeProfession& result);
  protected:
    sqlite3* _database;
    std::vector<TypeBuilding> _building_kinds;
    std::vector<TypeProfession> _professions;
    std::vector<Item> _items;
};

#endif
