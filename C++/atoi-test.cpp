#include <gtest/gtest.h>
#include <cmath>
#include "atoi.hpp"

using namespace std;

TEST(suite1, test1){
  string s = "3";
  ASSERT_EQ(myAtoi(s), 3);
}

TEST(suite1, test2){
  string s = "  3";
  ASSERT_EQ(myAtoi(s), 3);
}

TEST(suite1, test3){
  string s = "  -8";
  ASSERT_EQ(myAtoi(s), -8);
}

TEST(suite1, test4){
  string s = "-10000";
  ASSERT_EQ(myAtoi(s), -10000);
}

TEST(suite1, test5){
  string s = "2147483649";
  ASSERT_EQ(myAtoi(s), pow(2, 31)-1);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}