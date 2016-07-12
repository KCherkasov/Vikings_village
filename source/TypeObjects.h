#ifndef TYPE_OBJECTS_H
#define TYPE_OBJECTS_H

#include <cstdint>
#include <vector>
#include <string>

class TypeObject {
  public:
    TypeObject() { _name.clear(); _description.clear(); }
    ~TypeObject() {}
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
    //TypeBuilding(TypeBuildingTable data);
    ~TypeBuilding() {}
    size_t get_max_employees(std::vector<size_t>& result);
    size_t get_max_employees(size_t index, size_t& result);
    size_t get_resources(std::vector<size_t>& result);
    size_t get_resources(size_t index, size_t& result);
    size_t get_cost(std::vector<size_t>& result);
    size_t get_cost(size_t index, size_t& result);
    size_t get_building_time(size_t& result);
    size_t get_producable(std::vector<bool>& result);
    size_t get_producable(size_t index, bool& result);
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
  protected:
    std::vector<size_t> _max_employees;
    std::vector<size_t> _resources;
    std::vector<size_t> _cost;
    size_t _building_time;
    std::vector<bool> _producable;
};

#endif
