#include "ecu_logic.h"

#include <stdbool.h>
#include <stddef.h>

bool ecu_logic_init(ecu_logic_config_t *config, ecu_logic_state_t *state) {
  if (config == NULL || state == NULL) {
    return false;
  }

  return true;
}

void ecu_logic_loop(ecu_logic_state_t *state) {}