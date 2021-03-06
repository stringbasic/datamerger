/**
 *
 * ColumnMap.h
 *
 */

#ifndef COLUMNMAP_H
#define COLUMNMAP_H

#include <string>
#include <utility>
#include <vector>

namespace datamerger {

struct ColumnMapInfo {
  int mainIndex;
  int mapIndex;
  std::string columnName;
};

class ColumnMap {
 public:
  ColumnMap(const std::vector<std::string>&);
  ColumnMapInfo getMappedColumn(const std::vector<std::string>&);
  std::vector<std::string> getAllColumns();

 private:
  const std::vector<std::string> mainColumns;
  std::vector<std::string> extraColumns;
};
}  // namespace datamerger

#endif /* end of include guard: COLUMNMAP_H */
