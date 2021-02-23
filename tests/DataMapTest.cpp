#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "DataMap.h"

using namespace std;
using namespace datamerger;

TEST(DataMapSuite, Constructor) {
  DataMap dMap("columnMapped", 2);
  EXPECT_EQ("columnMapped", dMap.getColumnName());
  EXPECT_EQ(2, dMap.getColumnIndex());
}

TEST(DataMapSuite, FindOneRow) {
  DataMap dMap("columnMapped", 2);
  dMap.addDataRow({"val1", "val2", "val3indexed", "val4"});
  vector<string> mapValue = dMap.getMappedValue("val3indexed");
  vector<string> reference = {"val1", "val2", "val4"};
  EXPECT_EQ(reference.size(), mapValue.size());
  for (int i = 0; i < reference.size(); i++) {
    EXPECT_EQ(reference[i], mapValue[i]);
  }
}

TEST(DataMapSuite, NoResult) {
  DataMap dMap("columnMapped", 2);
  dMap.addDataRow({"val1", "val2", "val3indexed", "val4"});
  vector<string> mapValue = dMap.getMappedValue("dont-exist");
  vector<string> reference = {"", "", ""};
  EXPECT_EQ(reference.size(), mapValue.size());
  for (int i = 0; i < reference.size(); i++) {
    EXPECT_EQ(reference[i], mapValue[i]);
  }
}
