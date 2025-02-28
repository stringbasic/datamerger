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

using namespace datamerger;
using namespace csv;

DataMergerApp::DataMergerApp(std::string mainFile, std::ostream& outStream)
    : mainFile(std::move(mainFile)), outStream(outStream), dataMaps({}) {
}

DataMergerApp::DataMergerApp(std::string mainFile)
    : mainFile(std::move(mainFile)), outStream(std::cout), dataMaps({}) {
}

bool DataMergerApp::processHeader(const std::string& mapFile) {
  CSVReader mainReader(this->mainFile);
  CSVReader mapReader(mapFile);

  if (!columnMap) {
    columnMap = std::make_unique<ColumnMap>(mainReader.get_col_names());
  }
  auto mappedColumn = columnMap->getMappedColumn(mapReader.get_col_names());

  DataMap dMap(mappedColumn.columnName, mappedColumn.mapIndex);
  for (auto& mapRow : mapReader) {
    dMap.addDataRow(mapRow);
  }
  dataMaps.push_back(std::move(std::make_pair(mappedColumn, dMap)));

  return true;
}

void DataMergerApp::generateOutput() {
  CSVReader mainReader(this->mainFile);
  DelimWriter<std::ostream, ';', '"'> output(this->outStream);

  output << columnMap->getAllColumns();

  for (CSVRow& mainRow : mainReader) {
    std::list<std::string> allFields;
    for (CSVField& field : mainRow) {
      allFields.push_back(field.get<std::string>());
    }
    for (auto dataMap : dataMaps) {
      auto mappedValue = dataMap.second.getMappedValue(
          mainRow[dataMap.first.mainIndex].get<std::string>());
      for (auto& val : mappedValue) {
        allFields.push_back(val);
      }
    }
    output << allFields;
  }
}
