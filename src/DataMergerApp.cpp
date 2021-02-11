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
  CSVReader reader(this->mainFile);

  for (auto& column : reader.get_col_names()) {
    cout << "C: " << column << endl;
  }

  for (CSVRow& row : reader) {  // Input iterator
    for (CSVField& field : row) {
      // By default, get<>() produces a std::string.
      // A more efficient get<string_view>() is also available, where the
      // resulting string_view is valid as long as the parent CSVRow is alive
      cout << "F: " << field.get<>() << endl;
    }
  }

  return true;
}
