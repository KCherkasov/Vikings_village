#ifndef TYPE_OBJECTS_H
#define TYPE_OBJECTS_H

#include <stdint.h>
#include <vector>
#include <string>
#include "prototypes.h"

class TypeObject {
  public:
    TypeObject() { _name.clear(); _description.clear(); }
    virtual ~TypeObject() {}
    size_t get_name(std::string& result);
    size_t get_description(std::string& result);
    size_t set_name(std::string value);
    size_t set_name(char* value);
    size_t set_description(std::string value);
    size_t set_description(char* value);
    virtual size_t what(std::string& out) = 0;
  protected:
    std::string _name;
    std::string _description;
};

class TypeBuilding: public TypeObject {
  public:
    TypeBuilding();
    TypeBuilding(prototypes::TypeBuildingTable data);
    virtual ~TypeBuilding() {}
    size_t get_max_employees(std::vector<size_t>& result);
    size_t get_max_employees(size_t index, size_t& result);
    size_t get_resources(std::vector<size_t>& result);
    size_t get_resources(size_t index, size_t& result);
    size_t get_cost(std::vector<size_t>& result);
    size_t get_cost(size_t index, size_t& result);
    size_t get_building_time(size_t& result);
    size_t get_producable(std::vector<bool>& result);
    size_t get_producable(size_t index, bool& result);
    size_t get_save_data(prototypes::TypeBuildingTable& result);
    size_t set_max_employees(std::vector<size_t> value);
    size_t set_max_employees(size_t index, size_t value);
    size_t set_resources(std::vector<size_t> value);
    size_t set_resources(size_t index, size_t value);
    size_t set_cost(std::vector<size_t> value);
    size_t set_cost(size_t index, size_t value);
    size_t set_building_time(size_t value);
    size_t set_producable(std::vector<bool> value);
    size_t set_producable(size_t index, bool value);
    size_t what(std::string& out);
    size_t import_from_table(prototypes::TypeBuildingTable data);

    TypeBuilding& operator = (TypeBuilding& lhs, const TypeBuilding& rhs) {
      if(!lhs._name.empty()) {
        lhs._name.clear();
      }
      lhs._name = rhs._name;
      if (!lhs._description.empty()) {
        lhs._description.clear();
      }
      lhs._description = rhs._description;
      if (!lhs._max_employees.empty()) {
        lhs._max_employees.clear();
      }
      lhs._max_employees = rhs._max_employees;
      if (!lhs._resources.empty()) {
        lhs._resources.clear();
      }
      lhs._resources = rhs._resources;
      if (!lhs._cost.empty()) {
        lhs._cost.clear();
      }
      lhs._cost = rhs._cost;
      lhs._building_time = rhs._building_time;
      if (!lhs._producable.empty()) {
        lhs._producable.clear();
      }
      lhs._producable = rhs._producable;
      return lhs;
    }

  protected:
    std::vector<size_t> _max_employees;
    std::vector<size_t> _resources;
    std::vector<size_t> _cost;
    size_t _building_time;
    std::vector<bool> _producable;
};

class TypeProfession: public TypeObject {
  public:
    TypeProfession();
    TypeProfession(prototypes::TypeProfessionTable data);
    virtual ~TypeProfession() {}
    size_t get_consumation(std::vector<size_t>& result);
    size_t get_consumation(size_t index, size_t& result);
    size_t get_id(size_t& result);
    size_t get_can_slave(bool& result);
    size_t get_save_data(prototypes::TypeProfessionTable& result);
    size_t set_consumation(std::vector<size_t> value);
    size_t set_consumation(size_t index, size_t value);
    size_t set_id(size_t value);
    size_t set_can_slave(bool value);
    size_t what(std::string& out);
    size_t import_from_table(prototypes::TypeProfessionTable data);

    TypeProfession& operator = (TypeProfession& lhs, const TypeProfession& rhs) {
      if (!lhs._name.empty()) {
        lhs._name.clear();
      }
      lhs._name = rhs._name;
      if (!lhs._description.empty()) {
        lhs._description.clear();
      }
      lhs._description = rhs._description;
      if (!lhs._consumation.empty()) {
        lhs._consumation.clear();
      }
      lhs._consumation = rhs._consumation;
      lhs._id = rhs._id;
      lhs._can_slave = rhs._can_slave;
      return lhs;
    }

  protected:
    std::vector<size_t> _consumation;
    size_t _id;
    bool _can_slave;
};

#endif
