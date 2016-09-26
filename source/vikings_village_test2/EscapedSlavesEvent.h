#ifndef ESCAPED_SLAVES_EVENT_H
#define ESCAPED_SLAVES_EVENT_H

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "prototypes.h"
#include "TypeObjects.h"
#include "RaidEvent.h"

class EscapedSlavesEvent: public RaidEvent {
  public:
    EscapedSlavesEvent(IngameStorage& storage, std::string name, std::vector<std::string> descriptions, size_t& raid_turns, std::vector<size_t>& raid_ersources, std::vector<Human*>& raid_participants, std::vectorr<Human*>& raid_slaves, std::vector<Item*> raid_loot): RaidEvent(storage, name, description, raid_turns, raid_resources, raid_participants, raid_slaves, raid_loot) {}
    virtual ~EscapedSlavesEvent() {}
    size_t execute();
  protected:
    size_t success();
    size_t normal();
    size_t failure();
};

#endif
