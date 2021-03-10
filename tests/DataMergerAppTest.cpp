#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

#include "DataMergerApp.h"

using namespace std;
using namespace datamerger;

TEST(DataMergerApp, MergeOneMap) {
  ostringstream output;
  DataMergerApp app("../../tests/test1-input1.csv", output);
  EXPECT_EQ(true, app.processHeader("../../tests/test1-input2.csv"));
  app.generateOutput();
  ifstream expectedFile("../../tests/test1-output.csv", ios::in);
  stringstream expectedBuffer;
  expectedBuffer << expectedFile.rdbuf();
  EXPECT_EQ(expectedBuffer.str(), output.str());
}

TEST(DataMergerApp, MergeTwoMaps) {
  ostringstream output;
  DataMergerApp app("../../tests/test2-input1.csv", output);
  EXPECT_EQ(true, app.processHeader("../../tests/test2-input2.csv"));
  EXPECT_EQ(true, app.processHeader("../../tests/test2-input3.csv"));
  app.generateOutput();
  ifstream expectedFile("../../tests/test2-output.csv", ios::in);
  stringstream expectedBuffer;
  expectedBuffer << expectedFile.rdbuf();
  EXPECT_EQ(expectedBuffer.str(), output.str());
}