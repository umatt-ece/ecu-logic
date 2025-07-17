#include "ecu_logic.h"

#include <stdbool.h>
#include <stddef.h>

bool ecu_logic_init(ecu_logic_state_t *state) {
  if (state == NULL) {
    return false;
  }

  return true;
}