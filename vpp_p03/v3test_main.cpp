#include "v3test.h"

#include <gtest/gtest.h>

int mmain(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);


  return RUN_ALL_TESTS();


}
