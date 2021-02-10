#include <gtest/gtest.h>
#include "DataMergerApp.h"

using namespace datamerger;

TEST(Numbers, DataMergerAppOk) {
  DataMergerApp app;
  EXPECT_EQ(1, app.mergeIt());
}
