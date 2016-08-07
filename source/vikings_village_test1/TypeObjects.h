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
    size_t get_max_employees(size_t& result);
    size_t get_resources(std::vector<size_t>& result);
    size_t get_resources(size_t index, size_t& result);
    size_t get_cost(std::vector<size_t>& result);
    size_t get_cost(size_t index, size_t& result);
    size_t get_building_time(size_t& result);
    size_t get_living_space(size_t& result);
    size_t get_id(size_t& result);
    size_t get_producable(std::vector<bool>& result);
    size_t get_producable(size_t index, bool& result);
    size_t get_save_data(prototypes::TypeBuildingTable& result);
    size_t set_max_employees(size_t value);
    size_t set_resources(std::vector<size_t> value);
    size_t set_resources(size_t index, size_t value);
    size_t set_cost(std::vector<size_t> value);
    size_t set_cost(size_t index, size_t value);
    size_t set_building_time(size_t value);
    size_t set_living_space(size_t value);
    size_t set_id(size_t value);
    size_t set_producable(std::vector<bool> value);
    size_t set_producable(size_t index, bool value);
    size_t what(std::string& out);
    size_t import_from_table(prototypes::TypeBuildingTable data);

    TypeBuilding& operator = (const TypeBuilding& rhs) {
      if(!_name.empty()) {
        _name.clear();
      }
      _name = rhs._name;
      if (!_description.empty()) {
        _description.clear();
      }
      _description = rhs._description;
      if (!_resources.empty()) {
        _resources.clear();
      }
      _resources = rhs._resources;
      if (!_cost.empty()) {
        _cost.clear();
      }
      _cost = rhs._cost;
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

  protected:
    std::vector<size_t> _resources;
    std::vector<size_t> _cost;
    size_t _max_employees;
    size_t _building_time;
    size_t _living_space;
    size_t _id;
    std::vector<bool> _producable;
};

class TypeProfession: public TypeObject {
  public:
    TypeProfession();
    TypeProfession(prototypes::TypeProfessionTable data);
    virtual ~TypeProfession() {}
    size_t get_consumation(std::vector<size_t>& result);
    size_t get_consumation(size_t index, size_t& result);
    size_t get_id(ssize_t& result);
    size_t get_can_slave(bool& result);
    size_t get_save_data(prototypes::TypeProfessionTable& result);
    size_t set_consumation(std::vector<size_t> value);
    size_t set_consumation(size_t index, size_t value);
    size_t set_id(size_t value);
    size_t set_can_slave(bool value);
    size_t what(std::string& out);
    size_t import_from_table(prototypes::TypeProfessionTable data);

    TypeProfession& operator = (const TypeProfession& rhs) {
      if (!_name.empty()) {
        _name.clear();
      }
      _name = rhs._name;
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

  protected:
    std::vector<size_t> _consumation;
    size_t _id;
    bool _can_slave;
};

#endif
