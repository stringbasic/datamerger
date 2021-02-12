/**
 *
 * DataMergerApp.cpp
 *
 */

#include "DataMergerApp.h"
#include <iostream>
#include <list>
#include <string>
#include "csv.hpp"

using namespace std;
using namespace datamerger;
using namespace csv;

DataMergerApp::DataMergerApp(string mainFile) {
  this->mainFile = mainFile;
}

DataMergerApp::~DataMergerApp() {
}

bool DataMergerApp::processMap(string mapFile) {
  if (mapFile == "mapFile") return true;
  CSVReader mainReader(this->mainFile);
  DelimWriter<ostream, ';', '"'> output(cout);

  int mainMappedColumn = -1;
  int mapMappedColumn = -1;
  list<string> allColumns;

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
      } else if (lastIndex == i) {
        allColumns.push_back(mapC);
      }
      j++;
    }
    i++;
  }

  output << allColumns;

  for (CSVRow& mainRow : mainReader) {
    CSVReader mapReader(mapFile);
    list<string> allFields;
    int columnIndex = 0;
    for (CSVField& field : mainRow) {
      if (mainMappedColumn == columnIndex) {
        allFields.push_back(field.get<string>());
        for (auto& mapRow : mapReader) {
          if (mapRow[mapMappedColumn].get<string>() == field.get<>()) {
            int mapIndex = 0;
            for (auto& mapField : mapRow) {
              if (mapIndex != mapMappedColumn) {
                allFields.push_back(mapField.get<string>());
              }
              mapIndex++;
            }
          }
        }
      } else {
        allFields.push_back(field.get<string>());
      }
      columnIndex++;
    }
    output << allFields;
  }

  return true;
}
