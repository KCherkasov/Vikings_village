#ifndef RAID_EVENT_H
#define RAID_EVENT_H

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "prototypes.h"
#include "IngameStorage.h"
#include "Human.h"
#include "Item.h"

class RaidEvent {
  public:
    RaidEvent(IngameStorage& storage, std::string name, std::vector<std::string> descriptions, size_t& raid_turns, std::vector<size_t>& raid_resources, std::vector<Human*>& raid_participants, std::vector<Human*>& raid_slaves, std::vector<Item*>& raid_loot);
    virtual ~RaidEvent();
    IngameStorage& get_storage() { return _storage; }
    size_t get_name(std::string& result);
    size_t get_descriptions(std::vector<std::string>& result);
    size_t get_descriptions(size_t index, std::string& result);
    size_t set_name(std::string value);
    size_t set_description(std::string value);
    virtual size_t execute() = 0;
    size_t get_combat_stats(size_t index, size_t human_id, size_t& result);
    size_t get_combat_stats(size_t human_id, std::vector<size_t>& result);
    size_t get_combat_stats(size_t index, size_t& result);
    size_t get_combat_stats(std::vector<size_t>& result);
    size_t get_misc_stats(size_t index, size_t human_id, size_t& result);
    size_t get_misc_stats(size_t human_id, std::vector<size_t>& result);
    size_t get_misc_stats(size_t index, size_t& result);
    size_t get_misc_stats(std::vector<size_t>& result);
  protected:
  	IngameStorage& _storage;
    std::string _name;
	std::vector<std::string> _descriptions;
	size_t& _raid_turns;
	std::vector<size_t>& _raid_resources;
	std::vector<Human*>& _raid_participants;
	std::vector<Human*>& _raid_slaves;
	std::vector<Item*>& _raid_loot;
	
	size_t get_difficulty(size_t& result);
	virtual size_t success() = 0;
	virtual size_t normal() = 0;
	virtual size_t failure() = 0;  
	
	size_t event_outcome(size_t stat);

    size_t add_random_item();
    size_t destroy_random_item();

    size_t add_random_resource();
    size_t add_random_resource(size_t amount);
    size_t remove_random_resource();
    size_t remove_random_resource(size_t amount);
    size_t remove_random_resource_percent(size_t percents);

    size_t add_resource(size_t index);
    size_t add_resource(size_t index, size_t amount);
    size_t remove_resource(size_t index);
    size_t remove_resource(size_t index, size_t amount);

    size_t add_participant();
    size_t kill_participant();
    size_t add_slave();
    size_t kill_slave();
    size_t add_random_human(bool is_slave);
    size_t kill_random_human();

    size_t increase_phase_duration(size_t amount);
    size_t decrease_phase_duration(size_t amount);
    
    size_t increase_misc_stat(size_t index, size_t amount);
    size_t decrease_misc_stat(size_t index, size_t amount);
    
    size_t increase_combat_stat(size_t index, size_t amount);
    size_t decrease_combat_stat(size_t index, size_t amount);
};

#endif
