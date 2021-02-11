#include <iostream>
#include "DataMergerApp.h"
#include "csv.hpp"
#include "cxxopts.hpp"

using namespace std;
using namespace datamerger;
using namespace csv;

int main(int argc, char* argv[]) {
  DataMergerApp app;
  app.mergeIt();

  cxxopts::Options options("datamerger", "Merge data");
  options.add_options()("h,help", "print this help")(
      "main", "main file", cxxopts::value<std::string>())(
      "references", "mapping files",
      cxxopts::value<std::vector<std::string>>());
  options.parse_positional({"main", "references"});

  if (argc == 1) {
    cout << options.help({""}) << endl;
    exit(0);
  }

  auto result = options.parse(argc, argv);
  if (result.count("help")) {
    cout << options.help({""}) << endl;
    exit(0);
  }

  if (result.count("main")) {
    cout << "main: " << result["main"].as<std::string>() << endl;
  }

  if (result.count("references")) {
    for (auto& reference :
         result["references"].as<std::vector<std::string>>()) {
      cout << "reference: " << reference << endl;
    }
  }

  CSVRow row;
}
