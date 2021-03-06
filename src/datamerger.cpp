#include <iostream>

#include "DataMergerApp.h"
#include "cxxopts.hpp"

using namespace std;
using namespace datamerger;
using namespace cxxopts;

int main(int argc, char* argv[]) {
  Options options("datamerger", "Merge data");
  options.add_options()("h,help", "print this help")(
      "main", "main file", value<string>())("references", "mapping files",
                                            value<vector<string>>());
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
    cout << "main: " << result["main"].as<string>() << endl;
    DataMergerApp app(result["main"].as<string>());
    if (result.count("references")) {
      for (auto& reference : result["references"].as<vector<string>>()) {
        cout << "reference: " << reference << endl;
        app.processMap(reference);
      }
    }
  }
}
