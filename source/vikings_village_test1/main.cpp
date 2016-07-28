#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>

#include "prototypes.h"
#include "TypeObjects.h"
#include "Item.h"
#include "Inventory.h"
#include "Human.h"

size_t make_item_table(prototypes::ItemTable& table) {
  srand(static_cast<unsigned int>(time(0)));
  table._name.clear();
  table._name.append("test item");
  table._name_size = table._name.size();
  table._description.clear();
  table._description.append("test description");
  table._description_size = table._description.size();
  table._cost.clear();
  table._cost.resize(RI_SIZE);
  for (size_t i = 0; i < table._cost.size(); ++i) {
    size_t rnd = rand() % BASE_SEED + 1;
    table._cost[i] = rnd;
  }
  table._bonuses.clear();
  table._bonuses.resize(SI_SIZE);
  for (size_t i = 0; i < table._bonuses.size(); ++i) {
    size_t rnd = rand() % BASE_SEED + 1;
    table._bonuses[i] = rnd;
  }
  table._penalties.clear();
  table._penalties.resize(SI_SIZE);
  for (size_t i = 0; i < table._penalties.size(); ++i) {
    size_t rnd = rand() % BASE_SEED + 1;
    table._penalties[i] = rnd;
  }
  table._quality = rand() % IQ_SIZE;
  table._slots.clear();
  table._slots.resize(IS_SIZE);
  for (size_t i = 0; i < table._slots.size(); ++i) {
    bool rnd = (rand() % 2) == 0;
    table._slots[i] = rnd;
  }
  table._is_players = true;
  return 0;
}

size_t make_item_test(prototypes::ItemTable table, size_t& error_count, std::ofstream& out) {
  Item* test_item = NULL;
  test_item = new Item(table);
  std::string buffer;
  buffer.clear();
  printf("\tget_name() method test: ");
  out << "\tget_name() method test: ";
  test_item->get_name(buffer);
  if (!buffer.empty()) {
    if (buffer == table._name) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  buffer.clear();
  printf("\tget_description() method test: ");
  out << "\tget_description() method test: ";
  test_item->get_description(buffer);
  if (!buffer.empty()) {
    if (buffer == table._description) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
	}
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\tget_cost(vector mode) method test: ");
  out << "\tget_cost(vector mode) method test: ";
  std::vector<size_t> vect_buffer;
  vect_buffer.clear();
  test_item->get_cost(vect_buffer);
  if (!vect_buffer.empty()) {
    if (vect_buffer == table._cost) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\tget_cost(element mode) method test:\n");
  out << "\tget_cost(element mode) method test:\n";
  size_t elem_buffer = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < table._cost.size(); ++i) {
    printf("\t\telement number %d: ", i);
    out << "\t\telement number " << i << ": ";
    elem_buffer = SIZE_T_DEFAULT_VALUE;
    test_item->get_cost(i, elem_buffer);
    if (elem_buffer != SIZE_T_DEFAULT_VALUE) {
      if (elem_buffer == table._cost[i]) {
        printf("OK.\n");
        out << "OK.\n";
      } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
      }
    } else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
    }
  }
  printf("\tget_bonuses(vector mode) method test: ");
  out << "\tget_bonuses(vector mode) method test: ";
  vect_buffer.clear();
  test_item->get_bonuses(vect_buffer);
  if (!vect_buffer.empty()) {
    if (vect_buffer == table._bonuses) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\tget_bonuses(element mode) method test:\n");
  out << "\tget_bonuses(element mode) method test:\n";
  for (size_t i = 0; i < table._bonuses.size(); ++i) {
    printf("\t\telement number %d: ", i);
    out << "\t\telement number " << i << ": ";
    elem_buffer = SIZE_T_DEFAULT_VALUE;
    test_item->get_bonuses(i, elem_buffer);
    if (elem_buffer != SIZE_T_DEFAULT_VALUE) {
      if (elem_buffer == table._bonuses[i]) {
        printf("OK.\n");
        out << "OK.\n";
      } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
      }
    } else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
    }
  }
  printf("\tget_penalties(vector mode) method test: ");
  out << "\tget_penalties(vector mode) method test: ";
  vect_buffer.clear();
  test_item->get_penalties(vect_buffer);
  if (!vect_buffer.empty()) {
    if (vect_buffer == table._penalties) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\tget_penalties(element mode) method test:\n");
  out << "\tget_penalties(element mode) method test:\n";
  for (size_t i = 0; i < table._penalties.size(); ++i) {
    printf("\t\telement number %d: ", i);
    out << "\t\telement number " << i << ": ";
    elem_buffer = SIZE_T_DEFAULT_VALUE;
    test_item->get_penalties(i, elem_buffer);
    if (elem_buffer != SIZE_T_DEFAULT_VALUE) {
      if (elem_buffer == table._penalties[i]) {
        printf("OK.\n");
        out << "OK.\n";
      } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
      }
    } else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
    }
  }
  printf("\tget_quality() method test: ");
  out << "\tget_quality() method test: ";
  elem_buffer = IQ_SIZE;
  test_item->get_quality(elem_buffer);
  if (elem_buffer != IQ_SIZE) {
    if (elem_buffer == table._quality) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  std::vector<bool> bool_vect_buffer;
  bool_vect_buffer.clear();
  printf("\tget_slots(vector mode) method test: ");
  out << "\tget_slots(vector mode) method test: ";
  test_item->get_slots(bool_vect_buffer);
  if (!bool_vect_buffer.empty()) {
    if (bool_vect_buffer == table._slots) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\tget_slots(element mode) method test:\n");
  out << "\tget_slots(element mode) method test:\n";
  bool bool_elem_buffer;
  for (size_t i = 0; i < table._slots.size(); ++i) {
    printf("\t\telement number %d: ", i);
    out << "\t\telement number " << i << ": ";
    test_item->get_slots(i, bool_elem_buffer);
    if (bool_elem_buffer == table._slots[i]) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  }
  printf("\tget_is_players() method test: ");
  out << "\tget_is_players() method test: ";
  test_item->get_is_players(bool_elem_buffer);
  if (bool_elem_buffer == table._is_players) {
    printf("OK.\n");
    out << "OK.\n";
  } else {
    printf("object data is not equal to the source data.\n");
    out << "object data is not equal to the source data.\n";
    ++error_count;
  }
  printf("\tget_save_data() method test:\n");
  out << "\tget_save_data() method test:\n";
  prototypes::ItemTable table_buffer;
  test_item->get_save_data(table_buffer);
  printf("\t\t_name_size field: ");
  out << "\t\t_name_size field: ";
  if (table_buffer._name_size != SIZE_T_DEFAULT_VALUE) {
    if (table_buffer._name_size == table._name_size) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\t\t_name field: ");
  out << "\t\t_name field: ";
  if (!table_buffer._name.empty()) {
    if (table_buffer._name ==  table._name) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
	++error_count;
  }
  printf("\t\t_description_size field: ");
  out << "\t\t_description_size field: ";
  if (table_buffer._description_size != SIZE_T_DEFAULT_VALUE) {
    if (table_buffer._description_size == table._description_size) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\t\t_description field: ");
  out << "\t\t_description field: ";
  if (!table_buffer._description.empty()) {
    if (table_buffer._description == table._description) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\t\t_cost field: ");
  out << "\t\t_cost field: ";
  if (!table_buffer._cost.empty()) {
    if (table_buffer._cost == table._cost) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\t\t_bonuses field: ");
  out << "\t\t_bonuses field: ";
  if (!table_buffer._bonuses.empty()) {
    if (table_buffer._bonuses == table._bonuses) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\t\t_penalties field: ");
  out << "\t\t_penalties field: ";
  if (!table_buffer._penalties.empty()) {
    if (table_buffer._penalties == table._penalties) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\t\t_quality field: ");
  out << "\t\t_quality field: ";
  if (table_buffer._quality != IQ_SIZE) {
    if (table_buffer._quality == table._quality) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source field.\n");
      out << "object data is not equal to the source field.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\t\t_slots field: ");
  out << "\t\t_slots field: ";
  if (!table_buffer._slots.empty()) {
    if (table_buffer._slots == table._slots) {
      printf("OK.\n");
      out << "OK.\n";
    } else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
    }
  } else {
    printf("failed to retrieve the field data.\n");
    out << "failed to retrieve the field data.\n";
    ++error_count;
  }
  printf("\t\t_is_players field: ");
  out << "\t\t_is_players field: ";
  if (table_buffer._is_players == table._is_players) {
    printf("OK.\n");
    out << "OK.\n";
  } else {
    printf("object data is not equal to the source data.\n");
    out << "object data is not equal to the source data.\n";
    ++error_count;
  }
  delete test_item;
  return 0;
}

size_t make_item_quick_test(prototypes::ItemTable source, Item* item, size_t& error_count, std::ofstream& out) {
  size_t total_errors = 0;
  printf("\t<<============================>>\n");
  out << "\t<<============================>>\n";
  printf("\t  item quick test start:\n");
  if (item != NULL) {
    prototypes::ItemTable table_buffer;
    item->get_save_data(table_buffer);
    printf("\t\t_name field test: ");
    out << "\t\t_name field test: ";
    if (!table_buffer._name.empty()) {
      if (table_buffer._name == source._name) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++total_errors;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
	}
	printf("\t\t_description field test: ");
	out << "\t\t_description field test: ";
	if (!table_buffer._description.empty()) {
      if (table_buffer._description == source._description) {
        if (table_buffer._description == source._description) {
          printf("OK.\n");
          out << "OK.\n";
		}
	  } else {
	  	printf("object data is not equal to the source data.\n");
	  	out << "object data is not equal to the source data.\n";
        ++total_errors;
	  }
	} else {
      printf("failed to retrieve field data.\n");
      out << "failed to retrieve field data.\n";
      ++total_errors;
	}
	printf("\t\t_cost field test: ");
	out << "\t\t_cost field test: ";
	if (!table_buffer._cost.empty()) {
      if (table_buffer._cost == source._cost) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
	  	printf("object data is not equal to the source data.\n");
	  	out << "object data is not equal to the source data.\n";
        ++total_errors;
	  }
	} else {
		printf("failed to retrieve the field data.\n");
		out << "failed to retrieve the field data.\n";
      ++total_errors;
	}
	printf("\t\t_bonuses field test: ");
	out << "\t\t_bonuses field test: ";
	if (!table_buffer._bonuses.empty()) {
      if (table_buffer._bonuses == source._bonuses) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++total_errors;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++total_errors;
	}
	printf("\t\t_penalties field test: ");
	out << "\t\t_penalties field test: ";
	if (!table_buffer._penalties.empty()) {
	  if (table_buffer._penalties == source._penalties) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++total_errors;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++total_errors;
	}
	printf("\t\t_quality field test: ");
	out << "\t\t_quality field test: ";
	if (table_buffer._quality != IQ_SIZE) {
      if (table_buffer._quality == source._quality) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++total_errors;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++total_errors;
	}
	printf("\t\t_slots field test: ");
	out << "\t\t_slots field test: ";
	if (!table_buffer._slots.empty()) {
      if (table_buffer._slots == source._slots) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++total_errors;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++total_errors;
	}
	printf("\t\t_is_players field test: ");
	out << "\t\t_is_players field test: ";
	if (table_buffer._is_players == source._is_players) {
      printf("OK.\n");
      out << "OK.\n";
	} else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++total_errors;
	}
  } else {
  	printf("\t\tnull reference sent to the test.\n");
  	out << "\t\tnull reference sent to the test.\n";
  	++total_errors;
  }
  error_count += total_errors;
  printf("\t  item quick test end, total errors: %d\n", total_errors);
  out << "\t  item quick test end, total errors: " << total_errors << "\n";
  printf("\t<<============================>>\n");
  out << "\t<<============================>>\n";
  return total_errors;
}

size_t make_inventory_test(size_t& error_count, std::ofstream& out) {
  Inventory* test_inventory = NULL;
  std::vector<prototypes::ItemTable> table_vector;
  if (!table_vector.empty()) {
    table_vector.clear();
  }
  for (size_t i = 0; i < IS_SIZE; ++i) {
    prototypes::ItemTable buffer;
    make_item_table(buffer);
    table_vector.push_back(buffer);
  }
  printf("\tInventory(vector mode) method test: ");
  out << "\tInventory(vector mode) method test: ";
  test_inventory = new Inventory(table_vector);
  if (test_inventory != NULL) {
  	printf("OK.\n");
  	out << "OK.\n";
  	printf("\tget_size() method test: ");
  	out << "\tget_size() method test: ";
  	size_t elem_buffer = SIZE_T_DEFAULT_VALUE;
  	test_inventory->get_size(elem_buffer);
  	if (elem_buffer != SIZE_T_DEFAULT_VALUE) {
      if (elem_buffer == table_vector.size()) {
        printf("OK.\n");
        out << "OK.\n";
	  }	else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
	  }
	} else {
	  printf("failed to retrieve the field data.\n");
	  out << "failed to retrieve the field data.\n";
	  ++error_count;
	}
	std::vector<size_t> bonuses_buffer;
	if (!bonuses_buffer.empty()) {
      bonuses_buffer.clear();
	}
	std::vector<size_t> source_buffer;
	if (!source_buffer.empty()) {
      source_buffer.clear();
	}
	source_buffer.resize(SI_SIZE);
	for (size_t i = 0; i < source_buffer.size(); ++i) {
      source_buffer[i] = SIZE_T_DEFAULT_VALUE;
	}
	for (size_t i = 0; i < table_vector.size(); ++i) {
	  for (size_t j = 0; j < source_buffer.size(); ++j) {
		if (j < table_vector[i]._bonuses.size()) {
          source_buffer[j] += table_vector[j]._bonuses[j];
		}
	  }
	}
	printf("\tget_bonuses(vector mode) method test: ");
	out << "\tget_bonuses(vector mode) method test: ";
	test_inventory->get_bonuses(bonuses_buffer);
	if (!bonuses_buffer.empty()) {
      if (bonuses_buffer == source_buffer) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
	}
	printf("\tget_bonuses(element mode) method test:\n");
	out << "\tget_bonuses(element mode) method test:\n";
	for (size_t i = 0; i < source_buffer.size(); ++i) {
      printf("\t\telement number %d test: ", i);
      out << "\t\telement number " << i << " test: ";
      elem_buffer = SIZE_T_DEFAULT_VALUE;
      test_inventory->get_bonuses(i, elem_buffer);
      if (elem_buffer != SIZE_T_DEFAULT_VALUE) {
        if (elem_buffer == source_buffer[i]) {
          printf("OK.\n");
          out << "OK.\n";
		} else {
          printf("object data is not equal to the source data.\n");
          out << "object data is not equal to the source data.\n";
          ++error_count;
		}
	  } else {
        printf("failed to retrieve the field data.\n");
        out << "failed to retrieve the field data.\n";
        ++error_count;
	  }
	}
	std::vector<Item*> equipped_buffer_p;
	if (!equipped_buffer_p.empty()) {
      equipped_buffer_p.clear();
	}
	printf("\tget_equipped(vector mode) method test:\n");
	out << "\tget_equipped(vector mode) method test:\n";
	test_inventory->get_equipped(equipped_buffer_p);
	if (!equipped_buffer_p.empty()) {
      bool is_all_ok = true;
      for (size_t i = 0; i < table_vector.size(); ++i) {
        bool i_ok;
		printf("\t\telement %d test:\n", i);
        out << "\t\telement " << i << " test:\n";
        if (make_item_quick_test(table_vector[i], equipped_buffer_p[i], error_count, out) == 0) {
          i_ok = true;
		} else {
          i_ok = false;
		}
		is_all_ok = is_all_ok && i_ok;
	  }
	  if (is_all_ok) {
	  	printf("\tall tests went successfully.\n");
	  	out << "\tall tests went successfully.\n";
	  } else {
        printf("\tsome tests are with errors (see logs above).\n");
        out << "\tsome tests are with errors (see logs above).\n";
	  }
	  for (size_t i = 0; i < equipped_buffer_p.size(); ++i) {
        equipped_buffer_p[i] = NULL;
	  }
	} else {
      printf("\tfailed to retrieve the field data.\n");
      out << "\tfailed to retrieve the field data.\n";
      ++error_count;
	}
	printf("\tget_equipped(element mode) test:\n");
	out << "\tget_equipped(element mode) test:\n";
	for (size_t i = 0; i < table_vector.size(); ++i) {
      printf("\t\telement %d test:\n", i);
      out << "\t\telement " << i << " test:\n";
      Item* item_buffer = NULL;
      test_inventory->get_equipped(i, item_buffer);
      if (item_buffer != NULL) {
	    make_item_quick_test(table_vector[i], item_buffer, error_count, out);
	  }
	  item_buffer = NULL;
	}
	printf("\tget_save_data() method test:\n");
	out << "\tget_save_data() method test:\n";
	std::vector<prototypes::ItemTable> table_buffer;
	if (!table_buffer.empty()) {
      table_buffer.clear();
	}
	test_inventory->get_save_data(table_buffer);
	if (!table_buffer.empty()) {
      if (table_buffer.size() == table_vector.size()) {
      	for (size_t i = 0; i < table_buffer.size(); ++i) {
          printf("\t\telement %d test:\n", i);
          out << "\t\telement " << i << " test:\n";
          printf("\t\t\t_name_size field test: ");
          out << "\t\t\t_name_size field test: ";
          if (table_buffer[i]._name_size != SIZE_T_DEFAULT_VALUE) {
            if (table_buffer[i]._name_size == table_vector[i]._name_size) {
              printf("OK.\n");
              out << "OK.\n";
			} else {
              printf("object data is not equal to the source data.\n");
              out << "object data is not equal to the source data.\n";
              ++error_count;
			}
		  } else {
            printf("failed to retrieve the field data.\n");
            out << "failed to retrieve the field data.\n";
            ++error_count;
		  }
		  printf("\t\t\t_name field test: ");
		  out << "\t\t\t_name field test: ";
		  if (!table_buffer[i]._name.empty()) {
            if (table_buffer[i]._name == table_vector[i]._name) {
              printf("OK.\n");
              out << "OK.\n";
			} else {
              printf("object data is not equal to the source data.\n");
              out << "object data is not equal to the source data.\n";
              ++error_count;
			}
		  } else {
            printf("failed to retrieve the field data.\n");
            out << "failed to retrieve the field data.\n";
            ++error_count;
		  }
		  printf("\t\t\t_description_size field test: ");
		  out << "\t\t\t_description_size field test: ";
		  if (table_buffer[i]._description_size != SIZE_T_DEFAULT_VALUE) {
            if (table_buffer[i]._description_size == table_vector[i]._description_size) {
              printf("OK.\n");
              out << "OK.\n";
			} else {
              printf("object data is not equal to the source data.\n");
              out << "object data is not equal to the source data.\n";
              ++error_count;
			}
		  } else {
            printf("failed to retrieve the field data.\n");
            out << "failed to retrieve the field data.\n";
            ++error_count;
		  }
		  printf("\t\t\t_description field test: ");
		  out << "\t\t\t_description field test: ";
		  if (!table_buffer[i]._description.empty()) {
            if (table_buffer[i]._description == table_vector[i]._description) {
              printf("OK.\n");
              out << "OK.\n";
			} else {
              printf("object data is not equal to the source data.\n");
              out << "object data is not equal to the source data.\n";
              ++error_count;
			}
		  } else {
            printf("failed to retrieve the field data.\n");
            out << "failed to retrieve the field data.\n";
            ++error_count;
		  }
		  printf("\t\t\t_cost field test: ");
		  out << "\t\t\t_cost field test: ";
		  if (!table_buffer[i]._cost.empty()) {
            if (table_buffer[i]._cost == table_vector[i]._cost) {
              printf("OK.\n");
              out << "OK.\n";
			} else {
              printf("object data is not equal to the source data.\n");
              out << "object data is not equal to the source data.\n";
              ++error_count;
			}
		  } else {
		  	printf("failed to retrieve the field data.\n");
		  	out << "failed to retrieve the field data.\n";
		  	++error_count;
		  }
		  printf("\t\t\t_bonuses field test: ");
		  out << "\t\t\t_bonuses field test: ";
		  if (!table_buffer[i]._bonuses.empty()) {
		  	if (table_buffer[i]._bonuses == table_vector[i]._bonuses) {
              printf("OK.\n");
              out << "OK.\n";
		    } else {
              printf("object data is not equal to the source data.\n");
              out << "object data is not equal to the source data.\n";
              ++error_count;
			}
		  } else {
		  	printf("failed to retrieve the field data.\n");
		  	out << "failed to retrieve the field data.\n";
            ++error_count;
		  }
		  printf("\t\t\t_penalties field test: ");
		  out << "\t\t\t_penalties field test: ";
		  if (!table_buffer[i]._penalties.empty()) {
            if (table_buffer[i]._penalties == table_vector[i]._penalties) {
              printf("OK.\n");
              out << "OK.\n";
			} else {
			  printf("object data is not equal to the source data.\n");
			  out << "object data is not equal to the source data.\n";
			  ++error_count;
			}
		  } else {
		  	printf("failed to retrieve the field data.\n");
		  	out << "failed to retrieve the field data.\n";
		  	++error_count;
		  }
		  printf("\t\t\t_quality field test: ");
		  out << "\t\t\t_quality field test: ";
		  if (table_buffer[i]._quality != IQ_SIZE) {
            if (table_buffer[i]._quality == table_vector[i]._quality) {
              printf("OK.\n");
              out << "OK.\n";
			} else {
              printf("object data is not equal to the source data.\n");
              out << "object data is not equal to the source data.\n";
              ++error_count;
			}
		  } else {
	        printf("failed to retrieve the field data.\n");
	        out << "failed to retrieve the field data.\n";
	        ++error_count;
		  }
		  printf("\t\t\t_slots field test: ");
		  out << "\t\t\t_slots field test:";
		  if (!table_buffer[i]._slots.empty()) {
            if (table_buffer[i]._slots == table_vector[i]._slots) {
              printf("OK.\n");
              out << "OK.\n";
			} else {
              printf("object data is not equal to the source data.\n");
              out << "object data is not equal to the source data.\n";
              ++error_count;
			}
		  } else {
            printf("failed to retrieve the field data.\n");
            out << "failed to retrieve the field data.\n";
            ++error_count;
		  }
		  printf("\t\t\t_is_players field test: ");
		  out << "\t\t\t_is_players field test: ";
		  if (table_buffer[i]._is_players == table_vector[i]._is_players) {
            printf("OK.\n");
            out << "OK.\n";
		  } else {
            printf("object data is not equal to the source data.\n");
            out << "object data is not equal to the source data.\n";
            ++error_count;
		  }
	    }
	  } else {
	  	printf("\tobject data size is not equal to the source data size.\n");
	  	out << "\tobject data size is not equal to the source data size.\n";
	  	++error_count;
	  }
	} else {
      printf("\tfailed to retrieve the field data.\n");
      out << "\tfailed to retrieve the field data.\n";
      ++error_count;
	}
  } else {
    printf("failed to create an object.\n");
    out << "failed to create an object.\n";
    ++error_count;
  }
  delete test_inventory;
  return 0;
}

size_t make_human_table(prototypes::HumanTable& result) {
  srand(static_cast<unsigned int>(time(0)));
  if (!result._name.empty()) {
    result._name.clear();
  }
  result._name.append("test_name test_surname");
  result._name_size = result._name.size();
  if(!result._combat_stats.empty()) {
    result._combat_stats.clear();
  }
  result._combat_stats.resize(SI_SIZE);
  for (size_t i = 0; i < result._combat_stats.size(); ++i) {
    size_t rnd = rand() % MAX_STAT_VALUE + 1;
    result._combat_stats[i] = rnd;
  }
  if (!result._misc_stats.empty()) {
    result._misc_stats.clear();
  }
  result._misc_stats.resize(MI_SIZE);
  for  (size_t i = 0; i < result._misc_stats.size(); ++i) {
    size_t rnd = rand() % MAX_STAT_VALUE + 1;
    result._misc_stats[i] = rnd;
  }
  if (!result._skills.empty()) {
    result._skills.clear();
  }
  result._skills.resize(PI_SIZE);
  for (size_t i = 0; i < result._skills.size(); ++i) {
    size_t rnd = rand() % MAX_STAT_VALUE + 1;
    result._skills[i] = rnd;
  }
  if (!result._saga.empty()){
    result._saga.clear();
  }
  result._saga.resize(PS_SIZE);
  for (size_t i = 0; i < result._saga.size(); ++i) {
    size_t rnd = rand() % MAX_STAT_VALUE + 1;
    result._saga[i] = rnd;
  }
  if (!result._equipment.empty()) {
    result._equipment.clear();
  }
  for (size_t i = 0; i < IS_SIZE; ++i) {
    prototypes::ItemTable table;
    make_item_table(table);
    result._equipment.push_back(table);
  }
  ssize_t rnd = rand() % MAX_STAT_VALUE;
  result._house_id = rnd;
  rnd = rand() % PI_SIZE;
  result._profession_id = rnd;
  result._gender = (rand() % MAX_STAT_VALUE) <= MALE_GENDER_CHANCE;
  return 0;
}

size_t make_type_profession_table(prototypes::TypeProfessionTable& result) {
  srand(static_cast<unsigned int>(time(0)));
  if (!result._name.empty()) {
    result._name.clear();
  }
  result._name.append("test profession");
  result._name_size = result._name.size();
  if (!result._description.empty()) {
    result._description.clear();
  }
  result._description.append("test profession description");
  result._description_size = result._description.size();
  if (!result._consumation.empty()) {
    result._consumation.clear();
  }
  result._consumation.resize(RI_SIZE);
  for (size_t i = 0; i < result._consumation.size()) {
    size_t rnd = rand() % MAX_STAT_VALUE + 1;
    result._consumation[i] = rnd;
  }
  result._id = rand() % PI_SIZE;
  result._can_slave = (rand() % MAX_STAT_VALUE) <= MALE_GENDER_CHANCE;
  return 0;
}

size_t make_type_building_table(prototypes::TypeBuildingTable& result) {
  srand(static_cast<unsigned int>(time(0)));
  if (!result._name.empty()) {
    result._name.clear();
  }
  result._name.append("test building");
  result._name_size = result._name.size();
  if (!result._description.empty()) {
    result._description.clear();
  }
  result._description.append("test building description");
  result._description_size = result._description.size();
  if (!result._cost.empty()) {
    result._cost.clear();
  }
  result._cost.resize(RI_SIZE);
  for (size_t i = 0; i < result._cost.size(); ++i) {
    size_t rnd = rand() % MAX_STAT_VALUE + 1;
    result._cost[i] = rnd;
  }
  if (!result._max_employees.empty()) {
    result._max_employees.clear();
  }
  result._max_employees.resize(PI_SIZE);
  for (size_t i = 0; i < result._max_employees.size(); ++i) {
    size_t rnd = rand() % MAX_STAT_VALUE + 1;
    result._max_employees[i] = rnd;
  }
  if (!result._resources.empty()) {
    result._resources.clear();
  }
  result._resources.resize(RI_SIZE);
  for (size_t i = 0; i < result._resources.size(); ++i) {
    size_t rnd = rand() % MAX_STAT_VALUE + 1;
    result._resources[i] = rnd;
  }
  result._building_time = rand() % MAX_STAT_VALUE + 1;
  if (!result._producable.empty()) {
    result._producable.clear();
  }
  result._producable.resize(ITEMS_COUNT);
  for (size_t i = 0; i < result._producable.size(); ++i) {
    result._producable[i] = (rand() % MAX_STAT_VALUE) <= MALE_GENDER_CHANCE;
  }
  return 0;
}

size_t make_type_profession_test(size_t& error_count, std::ofstream& out) {
  TypeProfession* test_profession = NULL;
  prototypes::TypeProfessionTable source_table;
  make_type_profession_table(source_table);
  printf("\tTypeProfession(prototypes::TypeProfessionTable) constructor test: ");
  out << "\tTypeProfession(prototypes::TypeProfessionTable) constructor test: ";
  test_profession = new TypeProfession(source_table);
  if (test_profession != NULL) {
    printf("OK.\n");
    out << "OK.\n";
    printf("\tget_name() method test: ");
    out << "\tget_name() method test: ";
    std::string string_buffer;
    if (!string_buffer.empty()) {
      string_buffer.clear();
	}
	test_profession->get_name(string_buffer);
	if (!string_buffer.empty()) {
      if (string_buffer = source_table._name) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
	}
	printf("\tget_description() method test: ");
	out << "\tget_description() method test: ";
	string_buffer.clear();
	test_profession->get_description(string_buffer);
    if (!string_buffer.empty()) {
      if (string_buffer == source_table._description) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
	}
	printf("\tget_consumation(vector mode) method test: ");
	out << "\tget_consumation(vector mode) method test: ";
	std::vector<size_t> vector_buffer;
	if (!vector_buffer.empty()) {
      vector_buffer.clear();
	}
	test_profession->get_consumation(vector_buffer);
	if (!vector_buffer.empty()) {
      if (vector_buffer == source_table._consumation) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
	}
	printf("\tget_consumation(element mode) method test:\n");
	out << "\tget_consumation(element mode) method test:\n";
	size_t elem_buffer = SIZE_T_DEFAULT_VALUE;
	for(size_t i = 0; i < source_table._consumation.size(); ++i) {
      printf("\t\telement %d test: ", i);
      out << "\t\telement " << i << " test: ";
      test_profession->get_consumation(i, elem_buffer);
      if (elem_buffer != SIZE_T_DEFAULT_VALUE) {
        if (elem_buffer == source_table._consumation[i]) {
          printf("OK.\n");
          out << "OK.\n";
		} else {
          printf("object data is not equal to the source data.\n");
          out << "object data is not equal to the source data.\n";
          ++error_count;
		}
	    elem_buffer = SIZE_T_DEFAULT_VALUE;
	  } else {
        printf("failed to retrieve the field data.\n");
        out << "failed to retrieve the field data.\n";
        ++error_count;
	  }
	}
	printf("\tget_id() method test: ");
	out << "\tget_id() method test: ";
	elem_buffer = SIZE_T_DEFAULT_VALUE;
	test_profession->get_id(elem_buffer);
	if (elem_buffer != SIZE_T_DEFAULT_VALUE) {
      if (elem_buffer == source_table._id) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n");
        ++error_count;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
	}
	pritnf("\tget_can_slave() method test: ");
	out << "\tget_can_slave() method test: ";
	bool bool_buffer;
	test_profession->get_can_slave(bool_buffer);
	if (bool_buffer == source_table._can_slave) {
      printf("OK.\n");
      out << "OK.\n";
	} else {
      printf("object data is not equal to the source data.\n");
      out << "object data is not equal to the source data.\n";
      ++error_count;
	}
	printf("\tget_save_data() method test:\n");
	out << "\tget_save_data() method test:\n";
	prototypes::TypeProfessionTable table_buffer;
	test_profession->get_save_data(table_buffer);
	printf("\t\t_name_size field test: ");
	out << "\t\t_name_size field test: ";
	if (table_buffer._name_size != SIZE_T_DEFAULT_VALUE) {
	  if (table_buffer._name_size == source_table._name_size) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
	  }
    } else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
	}
	printf("\t\t_name field test: ");
	out << "\t\t_name field test: ";
	if (!table_buffer._name.empty()) {
      if (table_buffer._name == source_table._name) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "object data is not equal to the source data.\n";
        ++error_count;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
	}
	printf("\t\t_description_size field test: ");
	out << "\t\t_description_size field test: ";
	if (table_buffer._description_size != SIZE_T_DEFAULT_VALUE) {
      if (table_buffer._description_size == source_table._description_size) {
        printf("OK.\n");
        out << "OK.\n";
	  } else {
        printf("object data is not equal to the source data.\n");
        out << "objecy data is not equal to the source data.\n";
        ++error_count;
	  }
	} else {
      printf("failed to retrieve the field data.\n");
      out << "failed to retrieve the field data.\n";
      ++error_count;
	}
	
  } else {
    printf("failed to create an object.\n");
    out << "failed to create an object.\n";
    ++error_count;
  }
  delete test_profession;
  return 0;
} 

size_t make_human_test(size_t& error_count, std::ofstream& out) {
  Human* test_human = NULL;
  
  delete test_human;
  return 0;
}

int main()
{
  srand(static_cast<unsigned int>(time(0)));
  size_t tests_count = rand() % 150 + 300;
  std::string file_exec;
  file_exec.clear();
  file_exec.append(".log");
  std::string file_name_base;
  file_name_base.clear();
  file_name_base.append("test_log");
  std::string full_fname;
  full_fname.clear();
  full_fname += file_name_base;
  full_fname += file_exec;
  size_t errors = 0;
  std::ofstream out(full_fname.data(), std::ios_base::out | std::ios_base::trunc);
  printf("Item class tests:\n\n");
  out << "Item class tests:\n\n";
  for (size_t i = 0; i < tests_count; ++i) {
    printf("<==============================>\n");
    out << "<==============================>\n";
    printf("test %d:\n\n", i);
    out << "test " << i << ":\n\n";
    prototypes::ItemTable source;
    make_item_table(source);
    make_item_test(source, errors, out);
    printf("<==============================>\n\n");
    out << "<==============================>\n\n";
  }  
  printf("\ntotal errors: %d\n", errors);
  out << "\n\ntotal errors: " << errors << "\n";
  printf("\n\n\n");
  out << "\n\n\n";
  printf("Inventory class testing:\n\n");
  out << "Inventory class testing:\n\n";
  tests_count = rand() % 100 + 200;
  for (size_t i = 0; i < tests_count; ++i) {
    printf("<==============================>\n");
    out << "<==============================>\n";
    printf("test %d:\n\n", i);
    out << "test " << i << ":\n\n";
    make_inventory_test(errors, out);
    printf("<==============================>\n\n");
    out << "<==============================>\n\n";
  } 
  printf("\ntotal errors: %d\n", errors);
  out << "\n\ntotal errors: " << errors << "\n";
  out.close();
  system("pause");
  return 0;
}

