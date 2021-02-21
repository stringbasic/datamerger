/**
 *
 * DataMergerApp.cpp
 *
 */

#include "DataMergerApp.h"
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include "ColumnMap.h"
#include "DataMap.h"
#include "csv.hpp"

using namespace std;
using namespace datamerger;
using namespace csv;

DataMergerApp::DataMergerApp(string mainFile, ostream& outStream)
    : mainFile(mainFile), outStream(outStream) {
}

DataMergerApp::DataMergerApp(string mainFile)
    : mainFile(mainFile), outStream(cout) {
}

bool DataMergerApp::processMap(string mapFile) {
  CSVReader mainReader(this->mainFile);
  CSVReader mapReader(mapFile);
  DelimWriter<ostream, ';', '"'> output(this->outStream);

  ColumnMap cMap(mainReader.get_col_names());
  auto mappedColumn = cMap.getMappedColumn(mapReader.get_col_names());

  DataMap dMap(mappedColumn.columnName, mappedColumn.mapIndex);
  for (auto& mapRow : mapReader) {
    dMap.addDataRow(mapRow);
  }

  output << cMap.getAllColumns();

  for (CSVRow& mainRow : mainReader) {
    list<string> allFields;
    for (CSVField& field : mainRow) {
      allFields.push_back(field.get<string>());
    }
    auto mappedValue =
        dMap.getMappedValue(mainRow[mappedColumn.mainIndex].get<string>());
    for (auto& val : mappedValue) {
      allFields.push_back(val);
    }
    output << allFields;
  }

  return true;
}
