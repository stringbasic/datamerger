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
