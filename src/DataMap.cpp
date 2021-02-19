/**
 *
 * DataMap.cpp
 *
 */

#include "DataMap.h"

using namespace datamerger;
using namespace std;

DataMap::DataMap(string columnName, int columnIndex) {
  this->columnName = columnName;
  this->columnIndex = columnIndex;
}

const string& DataMap::getColumnName() {
  return this->columnName;
}

const int& DataMap::getColumnIndex() {
  return this->columnIndex;
}

void DataMap::addDataRow(const vector<string>& row) {
  vector<string> newrow(row);
  newrow.erase(newrow.begin() + this->columnIndex);
  this->data.insert(
      pair<string, vector<string>>(row[this->columnIndex], newrow));
}

optional<vector<string>> DataMap::getMappedValue(const string& value) {
  auto index = this->data.find(value);
  if (index != this->data.end()) {
    return index->second;
  }
  return {};
}
