//#include <cmath>
#include <gtest/gtest.h>

#include "solution.h"

using namespace std;

//------------------------------------------------------------------------------
class TestClass : public ::testing::Test {
protected:
  void SetUp()
  { }
};

//------------------------------------------------------------------------------
TEST_F(TestClass, testExample1) {
  vector<int> numbers{100,-23,-23,404,100,23,23,23,3,404};
  Solution s;
  ASSERT_EQ(3, s.minJumps(numbers));
}

//------------------------------------------------------------------------------
TEST_F(TestClass, testExample2) {
  vector<int> numbers{7};
  Solution s;
  ASSERT_EQ(0, s.minJumps(numbers));
}

//------------------------------------------------------------------------------
TEST_F(TestClass, testExample3) {
  vector<int> numbers{7,6,9,6,9,6,9,7};
  Solution s;
  ASSERT_EQ(1, s.minJumps(numbers));
}

//------------------------------------------------------------------------------
TEST_F(TestClass, testExample4) {
  vector<int> numbers{6,1,9};
  Solution s;
  ASSERT_EQ(2, s.minJumps(numbers));
}

//------------------------------------------------------------------------------
TEST_F(TestClass, testExample5) {
  vector<int> numbers{11,22,7,7,7,7,7,7,7,22,13};
  Solution s;
  ASSERT_EQ(3, s.minJumps(numbers));
}

//------------------------------------------------------------------------------


