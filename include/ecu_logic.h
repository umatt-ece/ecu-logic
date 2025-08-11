#ifndef ECU_LOGIC_H
#define ECU_LOGIC_H

#include <stdbool.h>

typedef struct ecu_logic_state {
} ecu_logic_state_t;

typedef struct ecu_logic_config {
} ecu_logic_config_t;

/**
 * Initializes the ECU logic state.
 *
 * @param config Pointer to the ECU logic configuration structure.
 * @param state Pointer to the ECU logic state structure to initialize.
 * @return True if initialization was successful, false if the state pointer was
 * NULL.
 */
bool ecu_logic_init(ecu_logic_config_t *config, ecu_logic_state_t *state);

/**
 * Runs the main loop of the ECU logic.
 *
 * @param state Pointer to the ECU logic state structure.
 */
void ecu_logic_loop(ecu_logic_state_t *state);

#endif  // ECU_LOGIC_H