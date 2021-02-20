/**
 *
 * DataMap.h
 *
 */

#ifndef DATAMAP_H
#define DATAMAP_H

#include <map>
#include <string>
#include <vector>

namespace datamerger {
class DataMap {
 public:
  DataMap(std::string, int);

  void addDataRow(const std::vector<std::string>&);
  const std::string& getColumnName();
  const int& getColumnIndex();
  std::vector<std::string> getMappedValue(const std::string&);

 private:
  int columnIndex;
  std::vector<std::string>::size_type maxSize;
  std::string columnName;
  std::map<std::string, std::vector<std::string>> data;
};
}  // namespace datamerger

#endif /* end of include guard: DATAMAP_H */
