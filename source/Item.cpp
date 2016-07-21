#include "Item.h"

Item::Item() {
  _name.clear();
  _description.clear();
  _cost = {SIZE_T_DEFAULT_VALUE};
  _slots = {BOOL_DEFAULT_VALUE};
  _bonuses = {SIZE_T_DEFAULT_VALUE};
  _penalties = {SIZE_T_DEFAULT_VALUE};
  _quality = IQ_COMMON;
}

Item::Item(prototypes::ItemTable data) {
  _name.clear();
  _description.clear();
  _name = data._name;
  _description = data._description;
  if (data._cost != NULL) {
    for (size_t i = 0; i < RI_SIZE; ++i) {
      _cost = data._cost;
    }
  } else {
    _cost = {SIZE_T_DEFAULT_VALUE};
  }
  if (data._slots != NULL) {
    for (size_t i = 0; i < IS_SIZE; ++i) {
      _slots[i] = data._slots[i];
    }
  } else {
    _slots = {BOOL_DEFAULT_VALUE};
  }
  if (data._bonuses != NULL) {
    for (size_t i = 0; i < SI_SIZE; ++i) {
      _bonuses[i] = data._bonuses[i];
    }
  } else {
    _bonuses = {SIZE_T_DEFAULT_VALUE};
  }
  if (data._penalties != NULL) {
    for (size_t i = 0; i < SI_SIZE; ++i) {
      _penalties[i] = data._penalties[i];
    }
  } else {
    _penalties = {SIZE_T_DEFAULT_VALUE};
  }
  _quality = data._quality;
}

Item::Item(prototypes::ItemTable data, size_t quality) {
  _name.clear();
  _description.clear();
  _name = data._name;
  _description = data._description;
  if (data._cost != NULL) {
    for (size_t i = 0; i < RI_SIZE; ++i) {
      _cost = data._cost;
    }
  } else {
    _cost = {SIZE_T_DEFAULT_VALUE};
  }
  if (data._slots != NULL) {
    for (size_t i = 0; i < IS_SIZE; ++i) {
      _slots[i] = data._slots[i];
    }
  } else {
    _slots = {BOOL_DEFAULT_VALUE};
  }
  if (data._bonuses != NULL) {
    for (size_t i = 0; i < SI_SIZE; ++i) {
      _bonuses[i] = data._bonuses[i];
    }
  } else {
    _bonuses = {SIZE_T_DEFAULT_VALUE};
  }
  if (data._penalties != NULL) {
    for (size_t i = 0; i < SI_SIZE; ++i) {
      _penalties[i] = data._penalties[i];
    }
  } else {
    _penalties = {SIZE_T_DEFAULT_VALUE};
  }
  _quality = quality;
}

size_t Item::get_name(std::string& result) {
  result.clear();
  result = _name;
  return 0;
}

size_t Item::get_description(std::string& result) {
  result.clear();
  result = _description;
  return 0;
}

size_t Item::get_cost(size_t*& result) {
  if (result == NULL) {
    delete[] result;
    result = new size_t[RI_SIZE];
  }
  for(size_t i = 0; i < RI_SIZE; ++i) {
    result[i] = _cost[i];
  }
  return 0;
}

size_t Item::get_cost(size_t index, size_t& result) {
  if (index < RI_SIZE) {
    result = _cost[index];
  }
  return 0;
}

size_t Item::get_bonuses(size_t*& result) {
  if (result == NULL) {
    delete[] result;
    result = new size_t[SI_SIZE];
  }
  for(size_t i = 0; i < SI_SIZE; ++i) {
    result[i] = _bonuses[i];
  }
  return 0;
}

size_t Item::get_bonuses(size_t index, size_t& result) {
  if (index < SI_SIZE) {
    result = _bonuses[index];
  }
  return 0;
}

size_t Item::get_penalties(size_t*& result) {
  if (result == NULL) {
    delete[] result;
    result = new size_t[SI_SIZE];
  }
  for (size_t i = 0; i < SI_SIZE; ++i) {
    result[i] = _penalties[i];
  }
  return 0;
}

size_t Item::get_penalties(size_t index, size_t& result) {
  if (index < SI_SIZE) {
    result = _penalties[index];
  }
  return 0;
}

size_t Item::get_slots(bool*& result) {
  if(result == NULL) {
    delete[] result;
    result = new bool[IS_SIZE];
  }
  for (size_t i = 0; i < IS_SIZE; ++i) {
    result[i] = _slots[i];
  }
  return 0;
}

size_t Item::get_slots(size_t index, bool& result) {
  if (index < IS_SIZE)) {
    result = _slots[index];
  }
  return 0;
}

size_t Item::get_quality(size_t& result) {
  result = _quality;
  return 0;
}

size_t Item::get_save_data(prototypes::ItemTable& result) {
  size_t response = SIZE_T_DEFAULT_VALUE;
  result._name.clear();
  result._description.clear();
  response = get_name(result._name);
  response = get_description(result._description);
  response = get_bonuses(result._bonuses);
  response = get_penalties(result._penalties);
  response = get_cost(result._cost);
  response = get_slots(result._slots);
  response = get_quality(result._quality);
  return response;
}

size_t Item::set_name(std::string value) {
  _name.clear();
  _name = value;
  return 0;
}

size_t Item::set_description(std::string value) {
  _name.clear();
  _description = value;
  return 0;
}

size_t Item::set_cost(size_t* value) {
  if (value != NULL) {
    for (size_t i = 0; i < RI_SIZE; ++i) {
      _cost[i] = value[i];
    }
  }
  return 0;
}

size_t Item::set_cost(size_t index, size_t value) {
  if (index < RI_SIZE) {
    _cost[index] = value;
  }
  return 0;
}

size_t Item::set_bonuses(size_t* value) {
  if (value != NULL) {
    for (size_t i = 0; i < SI_SIZE; ++i) {
      _bonuses[i] = value[i];
    }
  }
  return 0;
}

size_t Item::set_bonuses(size_t index, size_t value) {
  if (index < SI_SIZE) {
    _bonuses[index] = value;
  }
  return 0;
}

size_t Item::set_penalties(size_t* value) {
  if (value != NULL) {
    for (size_t i = 0; i < SI_SIZE; ++i) {
      _penalties[i] = value[i];
    }
  }
  return 0;
}

size_t Item::set_penalties(size_t index, size_t value) {
  if (index < SI_SIZE) {
    _penalties[index] = value;
  }
  return 0;
}

size_t Item::set_slots(bool* value) {
  if (value != NULL) {
    for (size_t i = 0; i < IS_SIZE; ++i) {
      _slots[i] = value[i];
    }
  }
  return 0;
}

size_t Item::set_slots(size_t index, bool value) {
  if (index < IS_SIZE) {
    _slots[index] = value;
  }
  return 0;
}

size_t Item::set_quality(size_t value) {
  _quality = value;
  return 0;
}

size_t Item::what(std::string& out) {
  out.clear();
  //code here to make pop-up text
  return 0;
}

size_t Item::import_from_table(prototypes::ItemTable data) {
  size_t response = SIZE_T_DEFAULT_VALUE;
  data._name.clear();
  data._description.clear();
  response = set_name(data._name);
  response = set_description(data._description);
  response = set_bonuses(data._bonuses);
  response = set_penalties(data._penalties);
  response = set_slots(data._slots);
  response = set_cost(data._cost);
  response = set_quality(data._quality);
  return response;
}
