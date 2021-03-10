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
  string mappedColumnName;
  int mainIndex = 0;
  int mapIndex = 0;
  bool found = false;

  for (auto& mainC : this->mainColumns) {
    mapIndex = 0;
    for (auto& mapC : mapColumns) {
      if (mainC == mapC) {
        mappedColumnName = mapC;
        found = true;
        break;
      }
      mapIndex++;
    }
    if (!found)
      mainIndex++;
    else
      break;
  }

  for (auto& mapC : mapColumns) {
    if (mappedColumnName == mapC) continue;
    this->extraColumns.push_back(mapC);
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
