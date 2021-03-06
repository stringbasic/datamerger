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

  bool processMap(const std::string&);

 private:
  std::string mainFile;
  std::ostream& outStream;
};
}  // namespace datamerger

#endif /* end of include guard: DATAMERGERAPP_H */
