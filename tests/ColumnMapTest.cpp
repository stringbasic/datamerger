#include <gtest/gtest.h>

#include "ColumnMap.h"

using namespace std;
using namespace datamerger;

TEST(ColumnMapSuite, Constructor) {
  vector<string> mainColumns = {"name", "birthdate", "id_city"};
  ColumnMap cMap(mainColumns);
  vector<string> mapColumns = {"region", "id_city", "city"};
  auto mappedColumn = cMap.getMappedColumn(mapColumns);
  EXPECT_EQ(2, mappedColumn.mainIndex);
  EXPECT_EQ(1, mappedColumn.mapIndex);
  EXPECT_EQ("id_city", mappedColumn.columnName);
  vector<string> allColumnsExpected = {"name", "birthdate", "id_city", "region",
                                       "city"};
  auto allColumns = cMap.getAllColumns();
  EXPECT_EQ(allColumnsExpected.size(), allColumns.size());
  for (int i = 0; i < allColumnsExpected.size(); i++) {
    EXPECT_EQ(allColumnsExpected[i], allColumns[i]);
  }
}

TEST(ColumnMapSuite, MapDoubleHeader) {
  vector<string> mainColumns = {"name", "birthdate", "id_city"};
  ColumnMap cMap(mainColumns);
  vector<string> mapColumns = {"id_city", "city"};
  auto mappedColumn = cMap.getMappedColumn(mapColumns);
  EXPECT_EQ(2, mappedColumn.mainIndex);
  EXPECT_EQ(0, mappedColumn.mapIndex);
  EXPECT_EQ("id_city", mappedColumn.columnName);
  vector<string> allColumnsExpected = {"name", "birthdate", "id_city", "city"};
  auto allColumns = cMap.getAllColumns();
  EXPECT_EQ(allColumnsExpected.size(), allColumns.size());
  for (int i = 0; i < allColumnsExpected.size(); i++) {
    EXPECT_EQ(allColumnsExpected[i], allColumns[i]);
  }
}

TEST(ColumnMapSuite, MapTwice) {
  vector<string> mainColumns = {"name", "birthdate", "id_city", "id_location"};
  ColumnMap cMap(mainColumns);
  vector<string> mapFirstColumns = {"id_city", "city"};
  auto mappedFirstColumn = cMap.getMappedColumn(mapFirstColumns);
  EXPECT_EQ(2, mappedFirstColumn.mainIndex);
  EXPECT_EQ(0, mappedFirstColumn.mapIndex);
  EXPECT_EQ("id_city", mappedFirstColumn.columnName);
  vector<string> mapSecondColumns = {"id_location", "location"};
  auto mappedSecondColumn = cMap.getMappedColumn(mapSecondColumns);
  EXPECT_EQ(3, mappedSecondColumn.mainIndex);
  EXPECT_EQ(0, mappedSecondColumn.mapIndex);
  EXPECT_EQ("id_location", mappedSecondColumn.columnName);
  vector<string> allColumnsExpected = {"name",        "birthdate", "id_city",
                                       "id_location", "city",      "location"};
  auto allColumns = cMap.getAllColumns();
  EXPECT_EQ(allColumnsExpected.size(), allColumns.size());
  for (int i = 0; i < allColumnsExpected.size(); i++) {
    EXPECT_EQ(allColumnsExpected[i], allColumns[i]);
  }
}
