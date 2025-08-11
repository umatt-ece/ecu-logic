#include <gtest/gtest.h>

extern "C" {
#include "ecu_logic.h"
}

TEST(EcuLogicTest, InitSuccess) {
  ecu_logic_config_t config;
  ecu_logic_state_t state;

  EXPECT_TRUE(ecu_logic_init(&config, &state));
}
