#include "Human.h"

Human::Human() {
  _name.clear();
  _combat_stats.clear();
  _misc_stats.clear();
  _skills.clear();
  _saga.clear();
  _combat_stats.resize(SI_SIZE);
  _misc_stats.resize(MI_SIZE);
  _skills.resize(PI_SIZE);
  _saga.reserve(PS_SIZE);
  _house_id = SSIZE_T_DEFAULT_VALUE;

}
