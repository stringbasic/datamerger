find_package(cxxopts CONFIG REQUIRED)

add_executable(datamerger datamerger.cpp
  DataMergerApp.cpp
)

target_link_libraries(datamerger PUBLIC cxxopts::cxxopts)
