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

size_t IngameStorage::get_item_namedescr(size_t query_id, std::string& name, std::string& description) {
  size_t response = 0;
  name.clear();
  description.clear();
  unsigned char* buffer = NULL;
  sqlite3_stmt* statement;
  response = sqlite3_prepare(_database, "select id, name, description from 'item_names_and_descrs' where id=?", -1, &statement, 0);
  sqlite3_bind_int(statement, 1, query_id);
  sqlite3_step(statement);
  buffer = sqlite3_column_text(statement, 1);
  if (buffer != NULL) {
    name.append(buffer);
  }
  delete[] buffer;
  buffer = sqlite3_column_text(statement, 2);
  if (buffer != NULL) {
    description.append(buffer);
  }
  delete[] buffer;
  return response;
}

size_t IngameStorage::get_item_bonuses(size_t query_id, std::vector<size_t>& bonuses) {
  size_t response = 0;
  bonuses.clear();
  bonuses.resize(CS_SIZE);
  sqlite3_stmt* statement;
  response = sqlite3_prepare(_database, "select id, wounds, melee, ranged, defense, initiative from 'item_bonuses' where id=?", -1, &statement, 0);
  sqlite3_bind_int(statement, 1, query_id);
  sqlite3_step(statement);
  for (size_t i = 0; i < SI_SIZE; ++i) {
    bonuses[i] = sqlite3_column_int(statement, i + 1);
  }
  return response;
}

size_t IngameStorage::get_item_penalties(size_t query_id, std::vector<size_t>& penalties) {
  size_t response = 0;
  penalties.clear();
  penalties.resize(CS_SIZE);
  sqlite3_stmt* statement;
  response = sqlite3_prepare(_database, "select id, wounds, melee, ranged, defense, initiative from 'item_penalties' where id=?", -1, &statement, 0);
  sqlite3_bind_int(statement, 1, query_id);
  sqlite3_step(statement);
  for (size_t i = 0; i < SI_SIZE; ++i) {
    penalties[i] = sqlite3_column_int(statement, i + 1);
  }
  return response;
}

size_t IngameStorage::get_item_slots(size_t query_id, std::vector<bool>& slots) {
  size_t response = 0;
  slots.clear();
  slots.resize(IS_SIZE);
  sqlite3_stmt* statement;
  response = sqlite3_prepare(_database, "select id, head, body, arms, legs, left_arm, right_arm, ranged from 'items_slots' where id=?", -1, &statement, 0);
  sqlite3_bind_int(statement, 1, query_id);
  sqlite3_step(statement);
  for (size_t i = 0; i < IS_SIZE; ++i) {
    size_t buffer = sqlite3_column_int(statement, i + 1);
    bool result;
    result = (buffer > 0);
    slots[i] = result;
  }
  return response;
}

size_t IngameStorage::get_item_cost(size_t query_id, std::vector<size_t>& cost) {
  size_t response = 0;
  cost.clear();
  cost.resize(RI_SIZE);
  sqlite3_stmt* statement;
  response = sqlite3_prepare(_database, "select id, gold, food, wood, iron, leather from 'item_costs' where id=?", -1, &statement, 0);
  sqlite3_bind_int(statement, 1, query_id);
  sqlite3_step(statement);
  for (size_t i = 0; i < RI_SIZE; ++i) {
    cost[i] = sqlite3_column_int(statement, i + 1);
  }
  return response;
}

size_t IngameStorage::form_item_record(size_t query_id, struct prototypes::ItemTable& data) {
  size_t response = 0;
  response = get_item_namedescr(query_id, data._name, data._description);
  response = get_item_bonuses(query_id, data._bonuses);
  response = get_item_penalties(query_id, data._penalties);
  response = get_item_slots(query_id, data._slots);
  response = get_item_cost(query_id, data._cost);
  return response;
}

size_t IngameStorage::get_nameparts(size_t query_id, bool gender) {
  size_t response = 0;
  sqlite3_stmt* statement;
  if (gender) {
    response = sqlite3_prepare(_database, "select id, part_one, part_two from 'male_nameparts' where id=?", -1, &statement, 0);
  } else {
    response = sqlite3_prepare(_database, "select id, part_one, part_two from 'female_nameparts' where id=?", -1, &statement, 0);
  }
  sqlite3_bind_int(statement, 1, query_id);
  sqlite3_step(statement);
  unsigned char* tmp1 = NULL;
  unsigned char* tmp2 = NULL;
  tmp1 = sqlite3_column_text(statement, 1);
  tmp2 = sqlite3_column_text(statement, 2);
  if (gender) {
    _male_nameparts_one.push_back();
    _male_nameparts_two.push_back();
    _male_nameparts_one[_male_nameparts_one.size() - 1].clear();
    _male_nameparts_one[_male_nameparts_one.size() - 1].append(tmp1);
    _male_nameparts_two[_male_nameparts_two.size() - 1].clear();
    _male_nameparts_two[_male_nameparts_two.size() - 1].append(tmp2);
  } else {
    _female_nameparts_one.push_back();
    _female_nameparts_two.push_back();
    _female_nameparts_one[_female_nameparts_one.size() - 1].clear();
    _female_nameparts_one[_female_nameparts_one.size() - 1].append(tmp1);
    _female_nameparts_two[_female_nameparts_two.size() - 1].clear();
    _female_nameparts_two[_female_nameparts_two.size() - 1].append(tmp2);
  }
  delete[] tmp1;
  delete[] tmp2;
  return response;
}

size_t IngameStorage::load_storage() {
  size_t response = 0;
  for (size_t i = 0; i < ITEMS_COUNT; ++i) {
    prototypes::ItemTable tmp;
    response = form_item_record(i+1, tmp);
    _items.push_back(tmp);
  }
  return response;
}

size_t IngameStorage::unload_storage() {
  size_t response = 0;
  _items.clear();
  _building_kinds.clear();
  _professions.clear();
  return response;
}
