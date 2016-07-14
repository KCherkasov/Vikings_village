#ifndef INGAME_STORAGE_H
#define INGAME_STORAGE_H

#include <cstdlib>
#include <ctime>
#include <direct.h>

#include "prototypes.h"
#include "sqlite3.h"

class IngameStorage {
  public:
    IngameStorage();
    IngameStorage(const char* db_name);
    ~IngameStorage();
    size_t connect_database(const char* db_name);
    size_t close_database();
  protected:
    sqlite3* _database;
};

#endif
