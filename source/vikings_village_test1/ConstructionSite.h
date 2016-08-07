#ifndef CONSTRUCTION_SITE_H
#define CONSTRUCTION_SITE_H

#include "prototypes.h"
#include "TypeObjects.h"
#include "Building.h"

class ConstructionSite {
  public:
    ConstructionSite(TypeBuilding& building);
    ~ConstructionSite() {}
    TypeBuilding& get_kind() { return _kind; }
    size_t get_turns_left(size_t& result);
    size_t get_is_built(bool& result);
    //develop and add get_save_data() method
	size_t set_kind(TypeBuilding& value);
	size_t set_turns_left(size_t value);
	size_t set_is_built(bool value);
	size_t what(std::string& out);
	size_t turn();
	size_t make_building(Building*& building);
  protected:
    TypeBuilding& _kind;
	size_t _turns_left;
	bool _is_built;
};

#endif
