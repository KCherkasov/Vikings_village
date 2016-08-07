#include "ConstructionSite.h"

ConstructionSite::ConstructionSite(TypeBuilding& building): _kind(building), _is_built(false) {
  building.get_building_time(_turns_left);
}

size_t ConstructionSite::get_turns_left(size_t& result) {
  result = _turns_left;
  return 0;
}

size_t ConstructionSite::get_is_built(bool& result) {
  result = _is_built;
  return 0;
}

size_t ConstructionSite::set_kind(TypeBuilding& value) {
  _kind = value;
  return 0;
}

size_t ConstructionSite::set_turns_left(size_t value) {
  _turns_left = value;
  return 0;
}

size_t ConstructionSite::set_is_built(bool value) {
  _is_built = value;
  return 0;
}

size_t ConstructionSite::what(std::string& out) {
  //code here to make a pop-up text;
  return 0;
}

size_t ConstructionSite::turn() {
  if (_turns_left > BUILD_DONE) {
    --_turns_left;
    _is_built = _turns_left == BUILD_DONE;
  }
  return 0;
}

size_t ConstructionSite::make_building(Building*& building) {
  if (_is_built) {
    if (building != NULL) {
      delete building;
	}
  }
  return 0;
}
