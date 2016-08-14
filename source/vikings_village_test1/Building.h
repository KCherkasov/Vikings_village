#ifndef BUILDING_H
#define BUILDING_H

#include <stdint.h>
#include <string>
#include <vector>

#include "prototypes.h"
#include "TypeObjects.h"
#include "IngameStorage.h"
#include "Item.h"

class Building {
  public:
    Building(TypeBuilding& kind);
    Building(prototypes::BuildingTable data, TypeBuilding& kind);
	~Building() {}
	TypeBuilding& get_kind() { return _kind; }
	size_t get_name(std::string& result);
	size_t get_description(std::string& result);
	size_t get_employees_id(std::vector<size_t>& result);
	size_t get_employees_id(size_t index, size_t& result);
	size_t get_employees_count(size_t& result);
	size_t get_employees_count();
	size_t get_inhabitants(std::vector<size_t>& result);
	size_t get_inhabitants(size_t index, size_t& result);
	size_t get_production_queue(std::vector<size_t>& result);
	size_t get_production_queue(size_t index, size_t& result);
	size_t get_building_time(size_t& result);
	size_t get_save_data(prototypes::BuildingTable& result);
	size_t set_employees_id(std::vector<size_t> value);
	size_t set_employees_id(size_t index, size_t value);
	size_t set_inhabitants(std::vector<size_t> value);
	size_t set_inhabitants(size_t index, size_t value);
	size_t set_production_queue(std::vector<size_t> value);
	size_t set_production_queue(size_t index, size_t value);
	size_t set_building_time(size_t value);
	size_t add_to_queue(size_t value);
	size_t remove_from_queue();
	size_t remove_from_queue(size_t index);
	size_t add_inhabitant(size_t value);
	size_t remove_inhabitant();
	size_t remove_inhabitant(size_t index);
	size_t add_employee(size_t value);
	size_t remove_employee();
	size_t remove_employee(size_t index);
	size_t what(std::string& out);
	size_t turn(std::storage<size_t>& storage, std::vector<Item*>& items, const IngameStorage& database);
  protected:
  	TypeBuilding& _kind;
    std::vector<size_t> _employees_id;
    std::vector<size_t> _inhabitants;
    std::vector<size_t> _production_queue;
    size_t _building_time;
};

#endif
