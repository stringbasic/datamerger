#include <iostream>
#include "DataMergerApp.h"
#include "csv.hpp"
#include "cxxopts.hpp"

using namespace std;
using namespace datamerger;
using namespace csv;

int main(int argc, char *argv[]) {
  DataMergerApp app;
  app.mergeIt();

  cxxopts::Options options("datamerger", "Merge data");
  options.add_options()("h,help", "print this help");

  if (argc == 1) {
    cout << options.help({""}) << endl;
    exit(0);
  }

  auto result = options.parse(argc, argv);
  if (result.count("help")) {
    cout << options.help({""}) << endl;
    exit(0);
  }

  CSVRow row;
}
