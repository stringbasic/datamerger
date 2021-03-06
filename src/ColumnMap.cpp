/**
 *
 * ColumnMap.cpp
 *
 */

#include "ColumnMap.h"

#include <functional>

using namespace std;
using namespace datamerger;

ColumnMap::ColumnMap(const vector<string>& mainColumns)
    : mainColumns(mainColumns) {
}

ColumnMapInfo ColumnMap::getMappedColumn(const vector<string>& mapColumns) {
  int i = 0, j;
  auto lastIndex = this->mainColumns.size() - 1;
  string mappedColumnName;
  int mainIndex = -1;
  int mapIndex = -1;
  for (auto& mainC : this->mainColumns) {
    j = 0;
    for (auto& mapC : mapColumns) {
      if (mainC == mapC) {
        mappedColumnName = mapC;
        mainIndex = i;
        mapIndex = j;
      } else if (lastIndex == i) {
        this->extraColumns.push_back(mapC);
      }
      j++;
    }
    i++;
  }

  return {mainIndex, mapIndex, mappedColumnName};
}

vector<string> ColumnMap::getAllColumns() {
  vector<string> allColumns;
  allColumns.insert(allColumns.end(), this->mainColumns.begin(),
                    this->mainColumns.end());
  allColumns.insert(allColumns.end(), this->extraColumns.begin(),
                    this->extraColumns.end());
  return allColumns;
}
