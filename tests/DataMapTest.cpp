#include <gtest/gtest.h>
#include <optional>
#include <string>
#include <vector>
#include "DataMap.h"

using namespace datamerger;
using namespace std;

TEST(Construct, DataMapOk) {
  DataMap dMap("columnMapped", 2);
  EXPECT_EQ("columnMapped", dMap.getColumnName());
  EXPECT_EQ(2, dMap.getColumnIndex());
}

TEST(MapOneRow, DataMapOk) {
  DataMap dMap("columnMapped", 2);
  dMap.addDataRow({"val1", "val2", "val3indexed", "val4"});
  optional<vector<string>> mapValue = dMap.getMappedValue("val3indexed");
  EXPECT_EQ(true, mapValue.has_value());
  vector<string> reference = {"val1", "val2", "val4"};
  vector<string> empty = {};
  vector<string> valueOrEmpty = mapValue.value_or(empty);
  EXPECT_EQ(reference.size(), valueOrEmpty.size());
  for (int i = 0; i < reference.size(); i++) {
    EXPECT_EQ(reference[i], valueOrEmpty[i]);
  }
}
