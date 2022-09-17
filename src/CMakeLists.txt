include_directories("../lib/csv-parser/single_include")
add_executable(datamerger datamerger.cpp
  DataMergerApp.cpp
  DataMap.cpp
  ColumnMap.cpp
)

target_link_libraries(datamerger PUBLIC cxxopts::cxxopts)
target_link_libraries(datamerger PUBLIC csv)
