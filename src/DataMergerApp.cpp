/**
 *
 * DataMergerApp.cpp
 *
 */

#include "DataMergerApp.h"

#include <iostream>
#include <list>
#include <string>
#include <utility>

#include "ColumnMap.h"
#include "DataMap.h"
#include "csv.hpp"

using namespace std;
using namespace datamerger;
using namespace csv;

DataMergerApp::DataMergerApp(string mainFile, ostream& outStream)
    : mainFile(move(mainFile)), outStream(outStream), dataMaps({}) {
}

DataMergerApp::DataMergerApp(string mainFile)
    : mainFile(move(mainFile)), outStream(cout), dataMaps({}) {
}

bool DataMergerApp::processHeader(const string& mapFile) {
  CSVReader mainReader(this->mainFile);
  CSVReader mapReader(mapFile);
  DelimWriter<ostream, ';', '"'> output(this->outStream);

  if (!columnMap) {
    columnMap = make_unique<ColumnMap>(mainReader.get_col_names());
  }
  auto mappedColumn = columnMap->getMappedColumn(mapReader.get_col_names());

  DataMap dMap(mappedColumn.columnName, mappedColumn.mapIndex);
  for (auto& mapRow : mapReader) {
    dMap.addDataRow(mapRow);
  }
  dataMaps.push_back(move(make_pair(mappedColumn, dMap)));

  return true;
}

void DataMergerApp::generateOuput() {
  CSVReader mainReader(this->mainFile);
  DelimWriter<ostream, ';', '"'> output(this->outStream);

  output << columnMap->getAllColumns();

  for (auto dataMap : dataMaps) {
    for (CSVRow& mainRow : mainReader) {
      list<string> allFields;
      for (CSVField& field : mainRow) {
        allFields.push_back(field.get<string>());
      }
      auto mappedValue = dataMap.second.getMappedValue(
          mainRow[dataMap.first.mainIndex].get<string>());
      for (auto& val : mappedValue) {
        allFields.push_back(val);
      }
      output << allFields;
    }
  }
}
