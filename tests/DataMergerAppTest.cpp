#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include "DataMergerApp.h"

using namespace std;
using namespace datamerger;

TEST(Numbers, DataMergerAppOk) {
  ostringstream output;
  DataMergerApp app("../../tests/test1-input1.csv", output);
  EXPECT_EQ(true, app.processMap("../../tests/test1-input2.csv"));
  ifstream expectedFile("../../tests/test1-output.csv", std::ios::in);
  stringstream expectedBuffer;
  expectedBuffer << expectedFile.rdbuf();
  EXPECT_EQ(expectedBuffer.str(), output.str());
}
