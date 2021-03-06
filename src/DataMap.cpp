/**
 *
 * DataMap.cpp
 *
 */

#include "DataMap.h"

using namespace datamerger;
using namespace std;

DataMap::DataMap(string columnName, int columnIndex)
    : columnName(move(columnName)), columnIndex(columnIndex), maxSize(0) {
}

const string& DataMap::getColumnName() {
  return this->columnName;
}

const int& DataMap::getColumnIndex() const {
  return this->columnIndex;
}

void DataMap::addDataRow(const vector<string>& row) {
  vector<string> newrow(row);
  newrow.erase(newrow.begin() + this->columnIndex);
  if (newrow.size() > this->maxSize) this->maxSize = newrow.size();
  this->data.insert(
      pair<string, vector<string>>(row[this->columnIndex], newrow));
}

vector<string> DataMap::getMappedValue(const string& value) {
  auto index = this->data.find(value);
  if (index != this->data.end()) {
    return index->second;
  }

  return {this->maxSize, ""};
}
