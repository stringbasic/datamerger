file(GLOB tests_SOURCES "*Test.cpp")

include_directories("../src")
include_directories("../lib/csv-parser/single_include")
add_executable(datamerger_tests
  ${tests_SOURCES}
  ../src/DataMergerApp.cpp
  ../src/DataMap.cpp
  ../src/ColumnMap.cpp
)

target_link_libraries(datamerger_tests PRIVATE GTest::gtest_main)
add_test(datamerger datamerger_tests)
