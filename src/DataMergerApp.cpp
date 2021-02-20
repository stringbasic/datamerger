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
  DelimWriter<ostream, ';', '"'> output(this->outStream);

  int mainMappedColumn = -1;
  int mapMappedColumn = -1;
  list<string> allColumns;
  string mappedColumnName;

  int i = 0, j = 0;
  int lastIndex = mainReader.get_col_names().size() - 1;
  for (auto& mainC : mainReader.get_col_names()) {
    CSVReader mapReader(mapFile);
    allColumns.push_back(mainC);
    j = 0;
    for (auto& mapC : mapReader.get_col_names()) {
      if (mainC == mapC) {
        mainMappedColumn = i;
        mapMappedColumn = j;
        mappedColumnName = mainC;
      } else if (lastIndex == i) {
        allColumns.push_back(mapC);
      }
      j++;
    }
    i++;
  }

  DataMap dMap(mappedColumnName, mapMappedColumn);
  for (auto& mapRow : CSVReader(mapFile)) {
    dMap.addDataRow(mapRow);
  }

  output << allColumns;

  for (CSVRow& mainRow : mainReader) {
    CSVReader mapReader(mapFile);
    list<string> allFields;
    for (CSVField& field : mainRow) {
      allFields.push_back(field.get<string>());
    }
    auto mappedValue =
        dMap.getMappedValue(mainRow[mainMappedColumn].get<string>());
    for (auto& val : mappedValue) {
      allFields.push_back(val);
    }
    output << allFields;
  }

  return true;
}
