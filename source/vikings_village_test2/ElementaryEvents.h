#ifndef ELEMENTARY_EVENTS_H
#define ELEMENTARY_EVENTS_H

#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

#include "prototypes.h"
#include "Item.h"
#include "Human.h"
#include "IngameStorage.h"

size_t event_outcome(size_t difficulty, size_t stat);

size_t add_random_item(std::vector<Item*>& target, size_t owner_id);
size_t destroy_random_item(std::vector<Item*>& target);

size_t add_random_resource(std::vector<size_t>& target);
size_t add_random_resource(std::vector<size_t>& target, size_t amount);
size_t remove_random_resource(std::vector<size_t>& target);
size_t remove_random_resource(std::vector<size_t>& target, size_t amount);

size_t add_resource(size_t& target);
size_t add_resource(size_t& target, size_t amount);
size_t remove_resource(size_t& target);
size_t remove_resource(size_t& target, size_t amount);

size_t add_random_human(std::vector<Human*>& target, TypeProfession& profession, bool is_slave);
size_t kill_random_human(std::vector<Human*>& target);

size_t increase_phase_length(size_t& target, size_t amount);
size_t decrease_phase_length(size_t& target, size_t amount);

#endif
