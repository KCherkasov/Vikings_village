#include "Battle.h"

size_t Battle::roll_dice(size_t& result) {
  srand(static_cast<unsigned int>(time(0)));
  result = rand() % MAX_STAT_VALUE;
  return 0;
}

size_t Battle::is_end() {
  if (_raiders.empty()) {
    return BO_LOCALS_WON;
  }
  if (_locals.empty()) {
    return BO_RAIDERS_WON;
  }
  return BO_SIZE;
}

size_t Battle::get_own_id(std::vector<Human*> from, size_t& result) {
  if (!from.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    result = MAX_PEOPLE_ID;
    while (true) {
      size_t index = rand() % from.size();
      if (from[index] != NULL) {
        from[index]->get_own_id(result);
        break;
      }
    }
  }
  return 0;
}

size_t Battle::get_own_id(std::vector<Human*> from, std::vector<size_t> keys, size_t& result) {
  result = MAX_PEOPLE_ID;
  if (!from.empty()) {
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
      size_t index = rand() % from.size();
      if (from[index] != NULL) {
        from[index]->get_own_id(result);
      }
      for (size_t i = 0; i < keys.size(); ++i) {
        if (result == keys[i]) {
          result = MAX_PEOPLE_ID;
          break;
        }
      }
      if (result != MAX_PEOPLE_ID) {
        break;
      }
    }
  }
  return 0;
}

size_t Battle::set_pairs(std::vector<size_t>& raiders_queue, std::vector<size_t>& locals_queue) {
  if (!raiders_queue.empty()) {
    raiders_queue.clear();
  }
  if (!locals_queue.empty()) {
    locals_queue.clear();
  }
  if (!_locals.empty() && !_raiders.empty()) {
    size_t pairs_count = SIZE_T_DEFAULT_VALUE;
    if (_locals.size() < _raiders.size()) {
      pairs_count = _locals.size();
    } else {
      pairs_count = _raiders.size();
    }
    for (size_t i = 0; i < pairs_count; ++i) {
      size_t raider_id = MAX_PEOPLE_ID;
      size_t local_id = MAX_PEOPLE_ID;
      get_own_id(_raiders, raiders_queue, raider_id);
      get_own_id(_locals, locals_queue, local_id);
      _raiders_queue.push_back(raider_id);
      _locals_queue.push_back(local_id);
    }
    if (pairs_count < _raiders.size()) {
      for (size_t i = 0; i < _locals.size() - pairs_count; ++i) {
        size_t raider_id = MAX_PEOPLE_ID;
        size_t local_id = MAX_PEOPLE_ID;
        get_own_id(_raiders, raider_id);
        raiders_queue.push_back(raider_id);
        get_own_id(_locals, locals_queue, local_id);
        locals_queue.push_back(local_id);
      }
    }
    if (pairs_count < _raiders.size()) {
      for (size_t i = 0; i < _raiders.size() - pairs_count; ++i) {
        size_t raider_id = MAX_PEOPLE_ID;
        size_t local_id = MAX_PEOPLE_ID;
        get_own_id(_raiders, raiders_queue, raider_id);
        raiders_queue.push_back(raider_id);
        get_own_id(_locals, local_id);
        locals_queue.push_back(local_id);
      }
    }
  }
  return 0;
}

size_t Battle::fight_round(size_t raider_id, size_t local_id) {
  size_t stat_id = SI_SIZE;
  if (_turn == BS_RANGED || _turn == BS_THROWING) {
    stat_id = SI_RANGED;
  } else {
    stat_id = SI_MELEE;
  }
  // resolving raider's and local's ids into vector indices
  size_t raider_index = _raiders.size();
  size_t local_index = _locals.size();
  for (size_t i = 0; i < _raiders.size(); ++i) {
    if (_raiders[i] != NULL) {
      size_t own_id = MAX_PEOPLE_ID;
      _raiders[i]->get_own_id(own_id);
      if (raider_id == own_id) {
        raider_index = i;
        break;
      }
    }
  }
  for (size_t i = 0; i < _locals.size(); ++i) {
    size_t own_id = MAX_PEOPLE_ID;
    if (_locals[i] != NULL) {
      _locals[i]->get_own_id(own_id);
      if (local_id == own_id) {
        local_index = i;
        break;
      }
    }
  }
  // fight mechanics block
  if ((raider_index != _raiders.size()) && (_local_index != _locals.size())) {
    size_t raider_initiative = SIZE_T_DEFAULT_VALUE;
    size_t raider_stat = SIZE_T_DEFAULT_VALUE;
    size_t raider_def = SIZE_T_DEFAULT_VALUE;
    size_t local_initiative = SIZE_T_DEFAULT_VALUE;
    size_t local_stat = SIZE_T_DEFAULT_VALUE;
    size_t local_def = SIZE_T_DEFAULT_VALUE;
    _raiders[raider_index]->get_combat_stats(true, SI_INITIATIVE, raider_initiative);
    _raiders[raider_index]->get_combat_stats(true, stat_id, raider_stat);
    _raiders[raider_index]->get_combat_stats(true, SI_DEFENSE, raider_def);
    _locals[local_index]->get_combat_stats(true, SI_INITIATIVE, local_initiative);
    _locals[local_index]->get_combat_stats(true, stat_id, local_stat);
    _locals[local_index]->get_combat_stats(true, SI_DEFENSE, local_def);
    // defining who strikes first (by default it's raider)
    bool is_raider_first = true;
    if (local_initiative == raider_initiative) {
      if (local_stat == raider_stat) {
        size_t raider_roll = SIZE_T_DEFAULT_VALUE;
        size_t local_roll = SIZE_T_DEFAULT_VALUE;
        while (true) {
          dice_roll(raider_roll);
          dice_roll(local_roll);
          if (raider_roll != local_roll) {
            break;
          }
        }
        if (raider_roll < local_roll) {
          is_raider_first = false;
        }
      } else {
        if (raider_stat < local_stat) {
          is_raider_first = false;
        }
      }
    } else {
      if (raider_initiative < local_initiative) {
        is_raider_first = false;
      }
    }
    if (is_raider_first) {

    } else {

    }
  }
  return 0;
}
