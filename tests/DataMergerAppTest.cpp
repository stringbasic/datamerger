#include <gtest/gtest.h>
#include "DataMergerApp.h"

using namespace datamerger;

TEST(Numbers, DataMergerAppOk) {
  DataMergerApp app("mainFile");
  EXPECT_EQ(true, app.processMap("mapFile"));
}
