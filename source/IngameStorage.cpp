#include "IngameStorage.h"

IngameStorage::IngameStorage() {
  _database = NULL;
  _building_kinds.clear();
  _professions.clear();
  _items.clear();
}

IngameStorage::IngameStorage(const char* db_name) {
  connect_database(db_name);
  _building_kinds.clear();
  _professions.clear();
  _items.clear();
}

IngameStorage::~IngameStorage() {
  close_database();
}

size_t IngameStorage::connect_database(const char* db_name) {
  size_t response;
  response = sqlite3_open(db_name, &_database);
  return response;
}

size_t IngameStorage::close_database() {
  size_t response;
  while (true) {
    response = sqlite3_close(_database);
    if (response != SQLITE_BUSY) {
      break;
    }
  }
  return response;
}

size_t IngameStorage::load_storage() {

  return 0;
}

size_t IngameStorage::unload_storage() {

  return 0;
}

size_t IngameStorage::get_item(size_t index, Item& result) {
  if (index < _items.size()) {
    result = _items[index];
  }
  return 0;
}

size_t IngameStorage::get_building_kind(size_t index, TypeBuilding& result) {
  if (index < _building_kinds.size()) {
    result = _building_kinds[index];
  }
  return 0;
}

size_t IngameStorage::get_profession(size_t index, TypeProfession& result) {
  if (index < _professions.size()) {
    result = _professions[index];
  }
  return 0;
}
