/**
 *
 * DataMergerApp.h
 *
 */

#ifndef DATAMERGERAPP_H
#define DATAMERGERAPP_H

#include <iostream>
#include <string>

namespace datamerger {
class DataMergerApp {
 public:
  DataMergerApp(std::string, std::ostream&);
  DataMergerApp(std::string);
  ~DataMergerApp();

  bool processMap(std::string);

 private:
  std::string mainFile;
  std::ostream& outStream;
};
}  // namespace datamerger

#endif /* end of include guard: DATAMERGERAPP_H */
