#ifndef BATTLE_H
#define BATTLE_H

#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

#include "prototypes.h"
#include "TypeObjects.h"
#include "Human.h"
#include "Item.h"

class Battle {
  public:
    Battle(IngameStorage& storage, std::vector<Human*>& raiders, std::vector<Human*>& slaves, std::vector<size_t>& resources, std::vector<Item*>& _loot): _storage(storage), _raiders(raiders), _slaves(slaves), _resources(resources), _loot(loot), _turn(0) {}
    ~Battle() {}
    size_t generate_enemies(size_t battle_scale);
    size_t play();
    size_t get_raiders(size_t index, Human*& result);
    Human& get_raiders(size_t index) { return *(_raiders[index]); }
    size_t get_raiders_count() { return _raiders.size(); }
    size_t get_locals(size_t index, Human*& result);
    Human& get_locals(size_t index) { return *(_locals[index]); }
    size_t get_locals_count() { return _locals.size(); }
    size_t get_loot(size_t index, Item*& result);
    Item& get_loot(size_t index) {return *(_loot_pool[index]); }
    size_t get_loot_count() { return _loot_pool.size(); }
    size_t get_wounded_count() { return _wounded_pool.size(); }
    size_t get_enslaved_count() { return _slaves_pool.size(); }
    size_t get_killed_raiders_count() { return _killed_raiders.size(); }
    size_t get_killed_locals_count() { return _killed_locals.size(); }
    size_t get_turn(size_t& result);
    size_t get_turn() { return _turn; }
    size_t set_turn(size_t value);
    size_t what(std::string& out);
  protected:
    IngameStorage& _storage;
    std::vector<Human*>& _raiders;
    std::vector<Human*>& _slaves;
    std::vector<size_t>& _resources;
    std::vector<Item*>& _loot;
    std::vector<Human*> _locals;
    std::vector<Human*> _wounded_pool;
    std::vector<Human*> _killed_raiders;
    std::vector<Human*> _slaves_pool;
    std::vector<Human*> _killed_locals;
    std::vector<Item*> _loot_pool;
    std::vector<size_t> _resources_pool;
    size_t _turn;

    size_t roll_dice(size_t& result);
    size_t stats_test(size_t raider_stat, size_t local_stat, bool raider_strikes);
    size_t is_end();
    size_t get_own_id(std::vector<Human*> from, size_t& result);
    size_t get_own_id(std::vector<Human*> from, std::vector<size_t> keys, size_t& result);
    size_t drop_items(std::vector<Human*> from, size_t chance);
    size_t clean_dead();
    size_t set_pairs(std::vector<size_t>& raiders_queue, std::vector<size_t>& locals_queue);
    size_t fight_round(size_t raider_id, size_t local_id);
    size_t kill_raider(size_t index);
    size_t wound_raider(size_t index);
    size_t kill_local(size_t index);
    size_t enslave_local(size_t index);
    size_t afterfight();
    size_t turn();
};

#endif
