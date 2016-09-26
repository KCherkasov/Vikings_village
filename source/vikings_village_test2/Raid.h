#ifndef RAID_H
#define RAID_H

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "prototypes.h"
#include "IngameStorage.h"
#include "Human.h"
#include "Item.h"

class Raid {
  public:
    Raid(IngameStorage& storage);
    Raid(size_t turns_left, std::vector<size_t> terms, size_t food, std::vector<Human*> participants, IngameStorage& storage);
    Raid(prototypes::RaidTable data, IngameStorage& storage);
    ~Raid();
    size_t get_turns_left(std::vector<size_t>& result);
    size_t get_turns_left(size_t index, size_t& result);
    std::vector<size_t> get_turns_left() { return _turns_left; }
    std::vector<size_t>& get_turns_left_rel() { return _turns_left; }
    size_t get_stage(size_t& result);
    size_t get_stage() { return _stage; }
    size_t get_terms(std::vector<size_t>& result);
    size_t get_terms(size_t index, size_t& result);
    size_t get_terms(size_t index);
    size_t get_resources(std::vector<size_t>& result);
    size_t get_resources(size_t index, size_t& result);
    size_t get_resources(size_t index);
    std::vector<size_t>& get_resources() { return _resources; }
    size_t get_participants(std::vector<Human*>& result);
    size_t get_participants(size_t index, Human*& result);
    Human& get_participants(size_t index) { return *(_participants[index]); }
    std::vector<Human*>& get_participants() { return _participants; }
    size_t get_participants_count(size_t& result);
    size_t get_participants_count() { return _participants.size(); }
    size_t get_slaves(std::vector<Human*>& result);
    size_t get_slaves(size_t index, Human*& result);
    Human& get_slaves(size_t index) { return *(_slaves[index]); }
    size_t get_slaves_count(size_t& result);
    size_t get_slaves_count() { return _slaves.size(); }
    std::vector<Human*>& get_slaves() { return _slaves; }
    size_t get_loot(std::vector<Item*>& result);
    size_t get_loot(size_t index, Item*& result);
    Item& get_loot(size_t index) { return *(_loot[index]); }
    std::vector<Item*>& get_loot() { return _loot; }
    size_t get_loot_count(size_t& result);
    size_t get_loot_count() { return _loot.size(); }
    size_t get_save_data(prototypes::RaidTable& result);
    size_t set_turns_left(size_t value);
    size_t set_terms(std::vector<size_t> value);
    size_t set_terms(size_t index, size_t value);
    size_t set_resources(std::vector<size_t> value);
    size_t set_resources(size_t index, size_t value);
    size_t set_participants(std::vector<Human*> value);
    size_t set_participants(size_t index, Human* value);
    size_t set_slaves(std::vector<Human*> value);
    size_t set_slaves(size_t index, Human* value);
    size_t set_loot(std::vector<Item*> value);
    size_t set_loot(size_t index, Item* value);
    size_t what(std::string& out);
    size_t distribute_loot(std::vector<size_t>& village_resources, std::vector<Item*>& village_items, std::vector<Human*>& village_people);
    size_t consume();
    size_t turn();
    size_t add_resources(std::vector<size_t> amount);
    size_t add_resources(size_t index, size_t amount);
    size_t add_participant(Human* value);
    size_t add_participant(prototypes::HumanTable value);
    size_t add_slave(Human* value);
    size_t add_slave(prototypes::HumanTable value);
    size_t add_loot(Item* value);
    size_t add_loot(prototypes::ItemTable value);
    size_t remove_resources(std::vector<size_t> amount);
    size_t remove_resources(size_t index, size_t amount);
    size_t remove_participant(size_t index);
    size_t remove_slave(size_t index);
    size_t remove_loot(size_t index);
    
    Raid& operator = (const Raid& rhs) {
      _storage = rhs._storage;
      _stage = rhs._stage;
      if (!_turns_left.empty()) {
        _turns_left.clear();
	  }
      _turns_left = rhs._turns_left;
      if (!_terms.empty()) {
        _terms.clear();
	  }
	  _terms = rhs._terms;
	  if (!_resources.empty()) {
        _resources.clear();
	  }
	  _resources = rhs._resources;
	  if (!_participants.empty()) {
		_participants.clear();
	  }
	  _participants = rhs._participants;
	  if (!_slaves.empty()) {
        for (size_t i = 0; i < _slaves.size(); ++i) {
          if (_slaves[i] != NULL) {
            delete _slaves[i];
		  }
		}
		_slaves.clear();
	  }
	  _slaves = rhs._slaves;
	  if (!_loot.empty()) {
        for (size_t i = 0; i < _loot.size(); ++i) {
          if (_loot[i] != NULL) {
            delete _loot[i];
		  }
		}
		_loot.clear();
	  }
	  _loot = rhs._loot;
	  return *this;
	}
    
  protected:
  	IngameStorage& _storage;
  	size_t _stage;
    std::vector<size_t> _turns_left;
    std::vector<size_t> _terms;
    std::vector<size_t> _resources;
    std::vector<Human*> _participants;
    std::vector<Human*> _slaves;
    std::vector<Item*> _loot;
};

#endif
