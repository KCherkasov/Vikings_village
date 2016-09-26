#include "Battle.h"

size_t Battle::roll_dice(size_t& result) {
  srand(static_cast<unsigned int>(time(0)));
  result = rand() % MAX_STAT_VALUE;
  return 0;
}

size_t Battle::stats_test(size_t raider_stat, size_t local_stat, bool raider_strikes) {
  size_t result = FO_SIZE;
  size_t plank = BASE_PLANK_VALUE;
  if (raider_strikes) {
    plank += raider_stat;
    if (plank > local_stat) {
      plank -= local_stat;
      if (plank < MIN_PLANK_VALUE) {
        plank = MIN_PLANK_VALUE;
      }
    } else {
      plank = MIN_PLANK_VALUE;
    }
    size_t roll;
    roll_dice(roll);
    if (roll < plank) {
      return FO_RAIDER_WON;
    } else {
      return FO_LOCAL_WON;
    }
  } else {
    plank += local_stat;
    if (plank > raider_stat) {
      plank -= raider_stat;
      if (plank < MIN_PLANK_VALUE) {
        plank = MIN_PLANK_VALUE;
      }
    } else {
      plank = MIN_PLANK_VALUE;
    }
    size_t roll;
    roll_dice(roll);
    if (roll < plank) {
      return FO_LOCAL_WON;
    } else {
      return FO_RAIDER_WON;
    }
  }
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

size_t Battle::drop_items(std::vector<Human*> from, size_t chance) {
  if (!from.empty()) {
    for (size_t i = 0; i < from.size(); ++i) {
      if (from[i] != NULL) {
        std::vector<prototype::ItemTable> equipment;
        equipment.clear();
        from[i]->get_inventory(equipment);
        for (size_t j = 0; j < equipment.size(); ++j) {
          equipment[j]._own_id = SSIZE_T_DEFAULT_VALUE;
          size_t roll;
          roll_dice(roll);
          if (roll < chance) {
            Item* new_loot = new Item(equipment[j]);
            _loot_pull.push_back(new_loot);
            new_loot = NULL;
          }
        }
      }
    }
  }
  return 0;
}

size_t Battle::clean_dead() {
  if (!_killed_locals.empty()) {
    for (size_t i = 0; i < _killed_locals.size(); ++i) {
      if (_killed_locals[i] != NULL) {
        delete _killed_locals[i];
      }
    }
  }
  _killed_locals.clear();
  if (!_killed_raiders.empty()) {
    for (size_t i = 0; i < _killed_raiders.size(); ++i) {
      if (_killed_raiders[i] != NULL) {
        delete _killed_raiders[i];
      }
    }
  }
  _killed_raiders.clear();
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
          roll_dice(raider_roll);
          roll_dice(local_roll);
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
  /      }
      }
    } else {
      if (raider_initiative < local_initiative) {
        is_raider_first = false;
      }
    }
    // mechanics itself
    // first comes hit test, if it's successful for attacker, then roll the wound test. If attacker succeeds in wounding his opponent,
    // roll the death wound test. If attacked is local, he either dies or becomes enslaved, if attacked is raider he either dies or
    // becomes wounded.
    // if attacker fails to hit his target and it's a melee phase of the battle, attacked strikes back with the same rules.
    if (is_raider_first) {
      size_t hit = FO_SIZE;
      if (_turn >= BS_MELEE) {
        hit = stats_test(raider_stat, local_stat, is_raider_first);
      } else {
        if (_raiders[raider_index]->can_shoot()) {
          hit = stats_test(raider_stat, local_stat, is_raider_first);
        }
      }
      if (hit != FO_SIZE) {
        if (hit == FO_RAIDER_WON) {
          size_t wounded = stats_test(raider_stat, local_def, is_raider_first);
          if (wounded == FO_RAIDER_WON) {
            size_t death_roll;
            roll_dice(death_roll);
            if (death_roll < BASE_DEATH_CHANCE) {
              kill_local(local_index);
              _raiders[raider_index]->add_to_saga(PS_KILLED, 1);
            } else {
              enslave_local(local_index);
              _raiders[raider_index]->add_to_saga(PS_ENSLAVED, 1);
            }
          }
        } else {
          if (_turn >= BS_MELEE) {
            hit = stats_test(raider_stat, local_stat, !is_raider_first);
            if (hit == FO_LOCAL_WON) {
              size_t wounded = stats_test(raider_def, local_stat, !is_raider_first);
              if (wounded == FO_LOCAL_WON) {
                size_t death_roll;
                roll_dice(death_roll);
                if (death_roll < BASE_DEATH_CHANCE) {
                  kill_raider(raider_index);
                } else {
                  wound_raider(raider_index);
                }
              }
            } 
          }
        }
      }
    } else {
      size_t hit = FO_SIZE; 
      if (_turn >= BS_MELEE) {
        hit = stats_test(raider_stat, local_stat, is_raider_first);
      } else {
        if (_locals[local_index]->can_shoot()) {
          hit = stats_test(raider_stat, local_stat, is_raider_first);
        }
      }
      if (hit != FO_SIZE) {
        if (hit == FO_LOCAL_WON) {
          size_t wounded = stats_test(raider_def, local_stat, is_raider_first);
          if (wounded == FO_LOCAL_WON) {
            size_t death_roll;
            roll_dice(death_roll);
            if (death_roll < BASE_DEATH_CHANCE) {
              kill_raider();
            } else {
              wound_raider();
            }
          }
        } else {
          if (_turn >= BS_MELEE) {
            hit = stats_test(raider_stat, local_stat, !is_raider_first);
            if (hit == FO_RAIDER_WON) {
              size_t wounded = stats_test(raider_stat, local_def, !is_raider_first);
              if (wounded == FO_RAIDER_WON) {
                size_t death_roll;
                roll_dice(death_roll);
                if (death_roll < BASE_DEATH_CHANCE) {
                  kill_local(local_index);
                  _raiders[raider_index]->add_to_saga(PS_KILLED, 1);
                } else {
                  enslave_local(local_index);
                  _raiders[raider_index]->add_to_saga(PS_ENSLAVED, 1);
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

size_t Battle::kill_raider(size_t index) {
  if (index < _raiders.size()) {
    Human* buf = _raiders[index];
    _raiders[index] = NULL;
    _raiders.erase(_raiders.begin() + index);
    _killed_raiders.push_back(buf);
    buf = NULL;
  }
  return 0;
}

size_t Battle::wound_raider() {
  if (index < _raiders.size()) {
    Human* buf = _raiders[index];
    _raiders[index] = NULL;
    _raiders.erase(_raiders.begin() + index);
    _wounded_pool.push_back(buf);
    buf = NULL;
  }
  return 0;
}

size_t Battle::kill_local(size_t index) {
  if (index < _locals.size()) {
    Human* buf = _locals[index];
    _locals[index] = NULL;
    _locals.erase(_locals.begin() + index);
    _killed_locals.push_back(buf);
    buf = NULL;
  }
  return 0;
}

size_t Battle::enslave_local(size_t index) {
  if (index < _locals.size()) {
    Human* buf = _locals[index];
    _locals[index] = NULL;
    _locals.erase(_locals.begin() + index);
    _slaves_pool.push_back(buf);
    buf = NULL;
  }
  return 0;
}

size_t Battle::afterfight() {
  if (!_raiders.empty()) {
    drop_items(_killed_locals, BASE_DROP_CHANCE);
    drop_items(_killed_raiders, BASE_DROP_CHANCE);
    for (size_t i = 0; i < _slaves_pool.size(); ++i) {
      if (_slaves_pool[i] != NULL) {
        Human* buf = _slaves_pool[i];
        _slaves_pool[i] = NULL;
        _slaves.push_back(buf);
        buf = NULL;
      }
    }
    _slaves_pool.clear();
    for (size_t i = 0; i < _loot_pool.size(); ++i {
      if (_loot_pool[i] != NULL) {
        Item* buf = _loot_pool[i];
        _loot.push_back(buf);
        _loot_pool[i] = NULL;
        buf = NULL;
      }
    }
    _loot_pool.clear();
  } else {
      for (size_t i = 0; i < _loot_pool.size(); ++i) {
        if (_loot_pool[i] != NULL) {
          delete _loot_pool[i];
        }
      }
      _loot_pool.clear();
      for (size_t i = 0; i < _slaves_pool.size(); ++i) {
        if (_slaves_pool[i] != NULL) {
          delete _slaves_pool[i];
        }
      }
      _slaves_pool.clear();
    }
    for (size_t i = 0; i < _locals.size(); ++i) {
      if (_locals[i] != NULL) {
        delete _locals[i];
      }
    }
    _locals.clear();
  }
  for (size_t i = 0; i < _wounded_pool; ++i) {
    if (_wounded_pool[i] != NULL) {
      Human* buf = _wounded_pool[i];
      _wounded_pool[i] = NULL;
      _raiders.push_back(buf);
      buf = NULL;
    }
  }
  _wounded_pool.clear();
  clean_dead();
  return 0;
}

size_t Battle::turn() {
  ++_turn;
  std::vector<size_t> raiders_queue;
  raiders_queue.clear();
  std::vector<size_t> locals_queue;
  locals_queue.clear();
  set_pairs(raiders_queue, locals_queue);
  if (raiders_queue.size() == locals_queue.size()) {
    for (size_t i = 0; i < raiders_queue.size(); ++i) {
      fight_round(raiders_queue[i], locals_queue[i]);
    }
  }
  return 0;
}

size_t Battle::generate_enemies(size_t battle_scale) {
  srand(static_cast<unsigned int>(time(0)));
  // following constants may be tweaked to change the number of generated enemies in each case
  const size_t SMALL_COUNT = 6;
  const size_t MEDIUM_COUNT = 12;
  const size_t BIG_COUNT = 24;
  size_t scale = SMALL_COUNT;
  if (battle_scale == FS_MEDIUM) {
    scale = MEDIUM_COUNT;
  } else {
    if (battle_scale == FS_BIG) {
      scale = BIG_COUNT;
    }
  }
  size_t locals_count = rand() % (scale / 2) + scale / 2 + 1;
  if (!_locals.empty()) {
    for (size_t i = 0; i < _locals.size(); ++i) {
      if (_locals[i] != NULL) {
        delete _locals[i];
      }
    }
    _locals.clear();
  }
  for (size_t i = 0; i < locals_count; ++i) {
    std::string name;
    _storage.form_name(MALE_GENDER, name);
    Human* to_add = new Human(_storage.get_profession(PI_UNEMPLOYED), MALE_GENDER, false, name);
    _locals.push_back(to_add);
    to_add = NULL;
  }
  return 0;
}

size_t Battle::play() {
  while (is_end() == BO_SIZE) {
    turn();
  }
  size_t outcome = is_end();
  afterfight();
  return outcome;
}

size_t Battle::get_raiders(size_t index, Human*& result) {
  if (index < _raiders.size()) {
    result = _raiders[index];
  }
  return 0;
}

size_t Battle::get_locals(size_t index, Human*& result) {
  if (index < _locals.size()) {
    result = _locals[index];
  }
  return 0;
}

size_t Battle::get_loot(size_t index, Item*& result) {
  if (index < _loot_pool.size()) {
    result = _loot_pool[index];
  }
  return 0;
}

size_t Battle::get_turn(size_t& result) {
  result = _turn;
  return 0;
}

