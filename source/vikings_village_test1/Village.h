#ifndef VILLAGE_H
#define VILLAGE_H

#include <string>
#include <vector>
#include <stdint.h>
#include <ctime>
#include <cstdlib>

#include "prototypes.h"
#include "TypeObjects.h"
#include "IngameStorage.h"
#include "Human.h"
#indlude "Building.h"
#include "Item.h"

class Village {
  public:
    Village(IngameStorgae& storage);
    //Village(std::string name, const IngameStorage& storage) //uncomment when storage is done - constructor for new game
    Village(prototypes::VillageTable data, IngameStorage& storage); // construtor for load game
    ~Village();
    size_t get_name(std::string& result);
    size_t get_storage(IngameStorage& result);
    IngameStorage& get_storage() { return _storage; }
    size_t get_resources(std::vector<size_t>& result);
    size_t get_resources(size_t index, size_t& result);
    size_t get_villagers(size_t index, Human& result);
    Human& get_villagers(size_t index);
	size_t get_villagers(std::vector<Human*>& result);
	size_t get_villagers(std::vector<prototypes::HumanTable>& result);
    size_t get_villagers_count(size_t& result);
    size_t get_villagers_count();
    size_t get_slaves_count(size_t& result);
    size_t get_slaves_count();
    size_t get_freemen_count(size_t& result);
    size_t get_freemen_count();
    size_t get_gender_count(bool freemen, bool gender, size_t& result);
    size_t get_gender_count(bool freemen, bool gender);
    size_t get_gender_count(bool gender, size_t& result);
    size_t get_gender_count(bool gender);
	size_t get_consumation(size_t index, size_t& result);
	size_t get_consumation(size_t index);
    size_t get_consumation(std::vector<size_t>& result);
    size_t get_buildings(size_t index, Building& result);
    Building& get_buildings(size_t index);
    size_t get_buildings(std::vector<Building*>& result);
    size_t get_buildings(std::vector<prototypes::BuildingTable>& result);
    size_t get_buildings_count(size_t& result);
    size_t get_buildings_count();
    size_t get_resources_production(size_t index, size_t& result);
    size_t get_resources_production(size_t index);
    size_t get_resources_production(std::vector<size_t>& result);
    size_t get_living_space(size_t& result);
    size_t get_living_space();
    size_t get_construction_count(size_t& result);
    size_t get_construction_count();
    size_t get_items(size_t index, Item& result);
    Item& get_items(size_t index);
    size_t get_items(std::vector<Item*>& result);
    size_t get_items(std::vector<prototypes::ItemTable>& result);
    size_t get_items_count(size_t& result);
    size_t get_items_count();
    size_t get_save_data(prototypes::VillageTable& result);
    size_t set_name(std::string value);
    size_t set_storage(IngameStorage& value);
    size_t set_resources(std::vector<size_t> value);
    size_t set_resources(size_t index, size_t value);
    size_t set_villagers(std::vector<Human*> value);
    size_t set_villagers(size_t index, Human* value);
    size_t set_buildings(std::vector<Building*> value);
    size_t set_buildings(size_t index, Building* value);
    size_t set_items(std::vector<Item*> value);
    size_t set_items(size_t index, Item* value);
    size_t consume();
    size_t produce();
    size_t add_villager(size_t profession_id, bool is_slave);
    size_t add_villager(prototypes::HumanTable data);
    size_t add_building(size_t kind_id);
    size_t add_building(prototypes::BuildingTable data);
    size_t add_item(size_t item_id);
    size_t add_item(prototypes::ItemTable data);
    size_t add_resources(size_t index, size_t amount);
    size_t add_resources(std::vector<size_t> amount);
    size_t remove_villager(size_t index);
    size_t remove_building(size_t index);
    size_t remove_item(size_t index);
    size_t clear_villagers();
    size_t clear_buildings();
    size_t clear_items();
    //size_t equip_villager(size_t item_index, size_t villager_index);
    size_t turn();
    size_t what(std::string& out);
  protected:
    std::string _name;
    IngameStorage& _storage;
    std::vector<size_t> _resources;
    std::vector<Human*> _villagers;
    std::vector<Building*> _buildings;
    std::vector<Item*> _items;
};

#endif
