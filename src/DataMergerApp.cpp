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

  int mainMappedColumn = -1;
  int mapMappedColumn = -1;

  int i = 0, j = 0;
  int lastIndex = mainReader.get_col_names().size() - 1;
  for (auto& mainC : mainReader.get_col_names()) {
    CSVReader mapReader(mapFile);
    cout << mainC << ",";
    j = 0;
    for (auto& mapC : mapReader.get_col_names()) {
      if (mainC == mapC) {
        mainMappedColumn = i;
        mapMappedColumn = j;
      } else if (lastIndex == i) {
        cout << mapC << ",";
      }
      j++;
    }
    i++;
  }
  cout << endl;

  for (CSVRow& mainRow : mainReader) {
    CSVReader mapReader(mapFile);
    int columnIndex = 0;
    for (CSVField& field : mainRow) {
      if (mainMappedColumn == columnIndex) {
        cout << field.get<>() << ",";
        for (auto& mapRow : mapReader) {
          if (mapRow[mapMappedColumn].get<string>() == field.get<>()) {
            int mapIndex = 0;
            for (auto& mapField : mapRow) {
              if (mapIndex != mapMappedColumn) cout << mapField.get<>() << ",";
              mapIndex++;
            }
          }
        }
      } else {
        cout << field.get<>() << ",";
      }
      columnIndex++;
    }
    cout << endl;
  }

  return true;
}
