/**
 *
 * DataMergerApp.h
 *
 */

#ifndef DATAMERGERAPP_H
#define DATAMERGERAPP_H

#include <iostream>
#include <memory>
#include <string>

#include "ColumnMap.h"
#include "DataMap.h"

namespace datamerger {
class DataMergerApp {
 public:
  DataMergerApp(std::string, std::ostream&);
  DataMergerApp(std::string);

  bool processHeader(const std::string&);
  void generateOutput();

 private:
  std::string mainFile;
  std::ostream& outStream;
  std::unique_ptr<ColumnMap> columnMap;
  std::vector<std::pair<ColumnMapInfo, DataMap>> dataMaps;
};
}  // namespace datamerger

#endif /* end of include guard: DATAMERGERAPP_H */
