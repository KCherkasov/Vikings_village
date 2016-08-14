#include "Village.h"

Village::Village(IngameStorage& storage): _storage(storage) {
  _name.clear();
  _resources.clear();
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        delete _villagers[i];
	  }
	}
  }
  _villagers.clear();
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
        delete _buildings[i];
	  }
	}
  }
  _buildings.clear();
  if (!_items.empty()) {
    for (size_t i = 0; i < _items.size(); ++i) {
      if (_items[i] != NULL) {
        delete _items[i];
	  }
	}
  }
  _items.clear();
}

Village::Village(prototypes::VillageTable data, const IngameStorage& storage): _storage(storage) {
  _name.clear();
  _name = data._name;
  _resources.clear();
  _resources = data._resources;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        delete _villagers[i];
	  }
	}
  }
  _villagers.clear();
  for (size_t i = 0; i < data._villagers.size(); ++i) {
    Human* tmp = NULL;
    tmp = new Human(data._villagers[i], storage.get_profession(data._villagers[i]._profession_id));
    _villagers.push_back(tmp);
    tmp = NULL;
  }
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
        delete _buildings[i];
	  }
	}
  }
  _buildings.clear();
  for (size_t i = 0; i < data._buildings.size(); ++i) {
    Building* tmp = NULL;
    tmp = new Building(data._buildings[i], storage.get_building_kind(data._buildings[i]._kind_id));
    _buildings.push_back(tmp);
    tmp = NULL;
  }
  if (!_items.empty()) {
    for (size_t i = 0; i < _items.size(); ++i) {
      if (_items[i] != NULL) {
        delete _items[i];
	  }
	}
  }
  _items.clear();
  for (size_t i = 0; i < data._items.size(); ++i) {
    Item* tmp = NULL;
    tmp = new Item(data._items[i]);
    _items.push_back(tmp);
    tmp = NULL;
  }
}

Village::~Village() {
  _name.clear();
  _resources.clear();
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        delete _villagers[i];
	  }
	}
  }
  _villagers.clear();
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
        delete _buildings[i];
	  }
	}
  }
  _buildings.clear();
  if (!_items.empty()) {
    for (size_t i = 0; i < _items.size(); ++i) {
      if (_items[i] != NULL) {
        delete _items[i];
	  }
	}
  }
  _items.clear();
}

size_t Village::get_name(std::string& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _name;
  return 0;
}

size_t Village::get_storage(IngameStorage& result) {
  result = _storage;
  return 0;
}

size_t Village::get_resources(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result = _resources;
  return 0;
}

size_t Village::get_resources(size_t index, size_t& result) {
  if (index < _resources.size()) {
    result = _resources[index];
  }
  return 0;
}

size_t Village::get_villagers(size_t index, Human& result) {
  if (index < _villagers.size()) {
    result = *(_villagers[index]);
  }
  return 0;
}

Human& Village::get_villagers(size_t index) {
  return *(_villagers[index]);
}

size_t Village::get_villagers(std::vector<Human*>& result) {
  if (!result.empty()) {
    for (size_t i = 0; i < result.size(); ++i) {
      if (result[i] != NULL) {
        delete result[i];
	  }
	}
	result.clear();
  }
  result = _villagers;
  return 0;
}

size_t Village::get_villagers(std::vector<prototypes::HumanTable>& result) {
  if (!result.empty()) {
    result.clear();
  }
  for (size_t i = 0; i < _villagers.size(); ++i) {
    prototypes::HumanTable tmp;
    _villagers[i]->get_save_data(tmp);
    result.push_back(tmp);
  }
  return 0;
}

size_t Village::get_villagers_count(size_t& result) {
  result = _villagers.size();
  return 0;
}

size_t Village::get_villagers_count() {
  return _villagers.size();
}

size_t Village::get_slaves_count(size_t& result) {
  result = 0;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        bool flag;
        _villagers[i]->get_is_slave(flag);
        if (flag == SLAVE_STATE) {
          ++result;
		}
	  }
	}
  }
  return 0;
}

size_t Village::get_slaves_count() {
  size_t result = SIZE_T_DEFAULT_VALUE;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        bool flag;
        _villagers[i]->get_is_slave(flag);
        if (flag == SLAVE_STATE) {
          ++result;
		}
	  }
	}
  }
  return result;
}

size_t Village::get_freemen_count(size_t& result) {
  result = 0;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        bool flag;
        _villagers[i]->get_is_slave(flag);
        if (flag == FREEMEN_STATE) {
          ++result;
		}
	  }
	}
  }
  return 0;
}

size_t Village::get_freemen_count() {
  size_t result = SIZE_T_DEFAULT_VALUE;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        bool flag;
        _villagers[i]->get_is_slave(flag);
        if (flag == FREEEMEN_STATE) {
          ++result;
		}
	  }
	}
  }
  return result;
}

size_t Village::get_gender_count(bool freemen, bool gender, size_t& result) {
  result = 0;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size()) {
      if (_villagers[i] != NULL) {
        bool gnd;
        _villagers[i]->get_gender(gnd);
        bool frm;
        _villagers[i]->get_is_slave(frm);
        if (frm == freemen && gender == gnd) {
          ++result;
		}
	  }
	}
  }
  return 0;
}

size_t Village::get_gender_count(bool freemen, bool gender) {
  size_t result = SIZE_T_DEFAULT_VALUE;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size()) {
      if (_villagers[i] != NULL) {
        bool gnd;
        _villagers[i]->get_gender(gnd);
        bool frm;
        _villagers[i]->get_is_slave(frm);
        if (frm == freemen && gender == gnd) {
          ++result;
		}
	  }
	}
  }
  return result;
}

size_t Village::get_gender_count(bool gender, size_t& result) {
  result = 0;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        bool gnd;
        _villagers[i]->get_gender(gnd);
        if (gnd == gender) {
          ++result;
		}
	  }
	}
  }
  return 0;
}

size_t Village::get_gender_count(bool gender) {
  size_t result = SIZE_T_DEFAULT_VALUE;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        bool gnd;
        _villagers[i]->get_gender(gnd);
        if (gnd == gender) {
          ++result;
		}
	  }
	}
  }
  return result;
}

size_t Village::get_consumation(size_t index, size_t& result) {
  result = 0;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        size_t consumation = SIZE_T_DEFAULT_VALUE;
        _villagers[i]->get_consumation(index, consumation);
        result += consumation;
	  }
	}
  }
  return 0;
}

size_t Village::get_consumation(size_t index) {
  size_t result = SIZE_T_DEFAULT_VALUE;
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        size_t consumation = SIZE_T_DEFAULT_VALUE;
        _villagers[i]->get_consumation(index, consumation);
        result += consumation;
	  }
	}
  }
  return result;
}

size_t Village::get_consumation(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
    result.resize(RI_SIZE);
    for (size_t i = 0; i < result.size(); ++i) {
      result[i] = SIZE_T_DEFAULT_VALUE;
	}
  }
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        std::vector<size_t> consumation;
        if (!consumation.empty()) {
          consumation.clear();
		}
		_villagers[i]->get_consumation(consumation);
	    if (consumation.size() == result.size()) {
          for (size_t i = 0; i < result.size(); ++i) {
            result[i] += consumation[i];
		  }
		}
	  }
	}
  }
  return 0;
}

size_t Village::get_buildings(size_t index, Building& result) {
  if (index < _buildings.size()) {
    result = *(_buildings[index]);
  }
  return 0;
}

Building& Village::get_buildings(size_t index) {
  return *(_buildings[index]);
}

size_t Village::get_buildings(std::vector<Building*>& result) {
  if (!result.empty()) {
    for (size_t i = 0; i < result.size(); ++i) {
      if (result[i] != NULL) {
        delete result[i];
	  }
	}
	result.clear();
  }
  result = _buildings;
  return 0;
}

size_t Village::get_buildings(std::vector<prototypes::BuildingTable>& result) {
  if (!result.empty()) {
    result.clear();
  }
  for (size_t i = 0; i < _buildings.size(); ++i) {
    if (_buildings[i] != NULL) {
      prototypes::BuildingTable table;
      _buildings[i]->get_save_data(table);
      result.push_back(table);
	}
  }
  return 0;
}

size_t Village::get_buildings_count(size_t& result) {
  result = _buildings.size();
  return 0;
}

size_t Village::get_buildings_count() {
  return _buildings.size();
}

size_t Village::get_resources_production(size_t index, size_t& result) {
  result = 0;
  if (index < RI_SIZE) {
    if (!_buildings.empty()) {
      for (size_t i = 0; i < _buildings.size(); ++i) {
        size_t production = 0;
        if (_buildings[i] != NULL) {
          _buildings[i]->get_resources(index, production);
		}
		result += production;
	  }
	}
  }
  return 0;
}

size_t Village::get_resources_production(size_t index) {
  size_t result = SIZE_T_DEFAULT_VALUE;
  if (index < RI_SIZE) {
    if (!_buildings.empty()) {
      for (size_t i = 0; i < _buildings.size(); ++i) {
        size_t production = 0;
        if (_buildings[i] != NULL) {
          _buildings[i]->get_resources(index, production);
		}
		result += production;
	  }
	}
  }
  return result;
}

size_t Village::get_resources_production(std::vector<size_t>& result) {
  if (!result.empty()) {
    result.clear();
  }
  result.resize(RI_SIZE);
  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = SIZE_T_DEFAULT_VALUE;
  }
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
      	std::vector<size_t> production;
        _buildings[i]->get_resources(production);
        if (production.size() == result.size()) {
          for (size_t j = 0; j < result.size(); ++j) {
            result[j] += production[j];
		  }
		}
	  }
	}
  }
  return 0;
}

size_t Village::get_living_space(size_t& result) {
  result = 0;
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      size_t space = SIZE_T_DEFAULT_VALUE;
      if (_buildings[i] != NULL) {
        _buildings[i]->get_kind().get_living_space(space);
	  }
	  result += space;
	}
  }
  return 0;
}

size_t Village::get_living_space() {
  size_t result = SIZE_T_DEFAULT_VALUE;
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      size_t space = SIZE_T_DEFAULT_VALUE;
      if (_buildings[i] != NULL) {
        _buildings[i]->get_kind().get_living_space(space);
	  }
	  result += space;
	}
  }
  return result;
}

size_t Village::get_construction_count(size_t& result) {
  result = 0;
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
        size_t btime = SIZE_T_DEFAULT_VALUE;
        _buildings[i]->get_building_time(btime);
        if (btime > 0) {
          ++result;
		}
	  }
	}
  }
  return 0;
}

size_t Village::get_construction_count() {
  size_t result = SIZE_T_DEFAULT_VALUE;
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
        size_t btime = SIZE_T_DEFAULT_VALUE;
        _buildings[i]->get_building_time(btime);
        if (btime > 0) {
          ++result;
		}
	  }
	}
  }
  return result;
}

size_t Village::get_items(size_t index, Item& result) {
  if (index < _items.size()) {
    result = *(_items[index]);
  }
  return 0;
}

Item& Village::get_items(size_t index) {
  return *(_items[index]);
}

size_t Village::get_items(std::vector<Item*>& result) {
  if (!result.empty()) {
    for (size_t i = 0; i < result.size()) {
      if (result[i] != NULL) {
        delete result[i];
	  }
	}
	result.clear();
  }
  result = _items;
  return 0;
}

size_t Village::get_items(std::vector<prototypes::ItemTable>& result) {
  if (!result.empty()) {
    result.clear();
  }
  for (size_t i = 0; i < _items.size(); ++i) {
    if (_items[i] != NULL) {
      prototype::ItemTable data;
      _items[i]->get_save_data(data);
      result.push_back(data);
	}
  }
  return 0;
}

size_t Village::get_items_count(size_t& result) {
  result = _items.size();
  return 0;
}

size_t Village::get_items_count() {
  return _items.size();
}

size_t Village::get_save_data(prototypes::VillageTable& result) {
  if (!result._name.empty()) {
    result._name.clear();
  }
  result._name = _name;
  result._name_size = result._name.size();
  if (!result._resources.empty()) {
    result._resources.clear();
  }
  result._resources = _resources;
  if (!result._villagers.empty()) {
    result._villagers.clear();
  }
  for (size_t i = 0; i < _villagers.size(); ++i) {
    if (_villagers[i] != NULL) {
      prototypes::HumanTable table;
      _villagers[i]->get_save_data(table);
      result._villagers.push_back(table);
	}
  }
  result._villagers_count = result._villagers.size();
  if (!result._buildings.empty()) {
    result._buildings.clear();
  }
  for (size_t i = 0; i < _buildings.size(); ++i) {
    if (_buildings[i] != NULL) {
      prototypes::BuildingTable table;
      _buildings[i]->get_save_data(table);
      result._buildings.push_back(table);
	}
  }
  result._buildings_count = result._buildings.size();
  if (!result._items.empty()) {
    result._items.clear();
  }
  for (size_t i = 0; i < _items.size(); ++i) {
    if (_items[i] != NULL) {
      prototypes::ItemTable table;
      _items[i]->get_save_data(table);
      result._items.push_back(table);
	}
  }
  result._items_count = result._items.size();
  return 0;
}

size_t Village::set_name(std::string value) {
  _name = value;
  return 0;
}

size_t Village::set_storage(IngameStorage& value) {
  _storage = value;
  return 0;
}

size_t Village::set_resources(std::vector<size_t> value) {
  _resources = value;
  return 0;
}

size_t Village::set_resources(size_t index, size_t value) {
  if (index < _resources.size()) {
    _resources[index] = value;
  }
  return 0;
}

size_t Village::set_villagers(std::vector<Human*> value) {
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        delete _villagers[i];
	  }
	}
  }
  _villagers = value;
}

size_t Villagers::set_villagers(size_t index, Human* value) {
  if (index < _villagers.size()) {
    if (_villagers[index] != NULL) {
      delete _villagers[index];
	}
	_villagers[index] = value;
  }
  return 0;
}

size_t Village::set_buildings(std::vector<Building*> value) {
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
        delete _buildings[i];
	  }
	}
	_buildings.clear();
  }
  _buildings = value;
  return 0;
}

size_t Village::set_buildings(size_t index, Building* value) {
  if (index < _buildings.size()) {
    if (_buildings[index] != NULL) {
      delete _buildings[index];
	}
	_buildings[index] = value;
  }
  return 0;
}

size_t Village::set_items(std::vector<Item*> value) {
  if (!_items.empty()) {
    for (size_t i = 0; i < _items.size(); ++i) {
      if (_items[i] != NULL) {
        delete _items[i];
	  }
	}
	_items.clear();
  }
  _items = value;
  return 0;
}

size_t Village::set_items(size_t index, Item* value) {
  if (index < _items.size()) {
    if (_items[index] != NULL) {
      delete _items[index];
	}
	_items[index] = value;
  }
  return 0;
}

size_t Village::consume() {
  if (!_villagers.empty()) {
    for (size_t i = 0; i < _villagers.size(); ++i) {
      if (_villagers[i] != NULL) {
        _villagers[i]->consume(_resources);
	  }
	}
  }
  return 0;
}

size_t Village::produce() {
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
        _buildings[i]->turn(_resources, _items, _storage);
	  }
	}
  }
  return 0;
}

size_t Village::add_villager(size_t profession_id, bool is_slave) {
  size_t capacity = SIZE_T_DEFAULT_VALUE;
  if (!_buildings.empty()) {
    for (size_t i = 0; i < _buildings.size(); ++i) {
      if (_buildings[i] != NULL) {
        size_t space;
        _buildings[i]->get_kind().get_living_space(space);
        capacity += space;
	  }
	}
	if (capacity > _villagers.size()) {
  	  srand(static_cast<unsigned int>(time(0)));
  	  bool gender;
  	  size_t rnd = rand() % MAX_STAT_VALUE; 
  	  size_t plank = MAX_STAT_VALUE / 2;
      if (rnd < plank) {
  	    gender = MALE_GENDER;
      } else {
        gender = FEMALE_GENDER;
	  }
  	  std::string name;
  	  name.clear();
  	  _storage.form_name(gender, name);
	  size_t house;
	  for (size_t i = 0; i < _buildings.size(); ++i) {
        size_t house_capacity;
        std::vector<size_t> house_inhabitants;
        house_inhabitants.clear();
        _buildings[i]->get_kind().get_living_space(house_capacity);
        _buildings[i]->get_inhabitants(house_inhabitants);
        if (house_capacity > house_inhabitants.size()) {
          house = i;
          break;
	    }
	  }
	  Human* villager = new Human(_storage.get_profession(profession_id), gender, is_slave, house, name);
	  _building[house]->add_inhabitant(_villagers.size());
	  _villagers.push_back(villager);
	  villager = NULL;
    }
  }
  return 0;
}

size_t Village::add_villager(prototypes::HumanTable data) {
  if (data._house_id < _buildings.size()) {
    Human* villager = new Human(data, _storage.get_profession(data._profession_id));
    if (_buildings[data._house_id] != NULL) {
      _buildings[data._house_id]->add_inhabitant(_villagers.size());
	}
	_villagers.push_back(villager);
	villager = NULL;
  }
  return 0;
}

size_t Village::add_building(size_t kind_id) {
  Building* to_add = new Building(_storage.get_building_kind(kind_id));
  _buildings.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t Village::add_building(prototypes::BuildingTable data) {
  Building* to_add = new Building(data, _storage.get_building_kind(data._kind_id));
  _buildings.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t Village::add_item(size_t item_id) {
  srand(static_cast<unsigned int>(time(0)));
  size_t quality = IQ_THRASH;
  size_t rnd = rand() % MAX_STAT_VALUE;
  if (rnd < LEGENDARY_CHANCE) {
    quality = IQ_LEGENDARY;
  } else {
    rnd = rand() % MAX_STAT_VALUE;
    if (rnd < EPIC_CHANCE) {
      quality = IQ_EPIC;
	} else {
      rnd = rand() % MAX_STAT_VALUE;
      if (rnd < RARE_CHANCE) {
        quality = IQ_RARE;
	  } else {
        rnd = rand() % MAX_STAT_VALUE;
        if (rnd < GOOD_CHANCE) {
          quality = IQ_GOOD;
		} else {
          rnd = rand() % MAX_STAT_VALUE;
          if (rnd < COMMON_CHANCE) {
            quality = IQ_COMMON;
		  }
		}
	  }
	}
  }
  Item* to_add = new Item(_storage.get_item_table(item_id), quality, true);
  _items.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t Village::add_item(prototypes::ItemTable data) {
  Item* to_add = new Item(data);
  _items.push_back(to_add);
  to_add = NULL;
  return 0;
}

size_t Village::add_resources(size_t index, size_t amount) {
  if (index < _resources.size()) {
    _resources[index] += amount;
  }
  return 0;
}

size_t Village::add_resources(std::vector<size_t> amount) {
 if (amount.size() == _resources.size()) {
   for (size_t i = 0; i < _resources.size(); ++i) {
     _resources[i] += amount[i];
   }
 }
 return 0;
}

size_t Village::remove_villager(size_t index) {
  if (index < _villagers.size()) {
    if (_villagers[index] != NULL) {
      delete _villagers[index];
	}
	_villagers.erase(_villagers.begin() + index);
  }
  return 0;
}

size_t Village::remove_building(size_t index) {
  if (index < _buildings.size()) {
    if (_buildings[index] != NULL) {
      delete _buildings[index];
	}
	_buildings.erase(_buildings.begin() + index);
  }
  return 0;
}

size_t Village::remove_item(size_t index) {
  if (index < _items.size()) {
    if (_items[index] != NULL) {
      delete _items[index];
	}
	_items.erase(_items.begin() + index);
  }
  return 0;
}

size_t Village::clear_villagers() {
  return 0;
}

size_t Village::clear_buildings() {
  return 0;
}

size_t Village::clear_items() {
  return 0;
}
