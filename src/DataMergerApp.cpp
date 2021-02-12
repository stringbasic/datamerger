/**
 *
 * DataMergerApp.cpp
 *
 */

#include "DataMergerApp.h"
#include <iostream>
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
  CSVReader mapReader(mapFile);

  string mappedColumn;

  for (auto& mainC : mainReader.get_col_names()) {
    cout << "main C: " << mainC << endl;
    for (auto& mapC : mapReader.get_col_names()) {
      cout << "map C: " << mapC << endl;
      if (mainC == mapC) {
        cout << "mapped column: " << mapC << endl;
        mappedColumn = mapC;
      }
    }
  }

  for (CSVRow& mainRow : mainReader) {  // Input iterator
    for (CSVField& field : mainRow) {
      cout << " F: " << field.get<>();
    }
    cout << endl;
  }

  return true;
}
