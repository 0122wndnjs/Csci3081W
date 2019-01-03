/**
Copyright (c) 2018 Joowon Kim, University of Minnesota.
	...
*/

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/filter_threshold.h"

using image_tools::FilterThreshold;

class FilterThresholdTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  FilterThreshold thresh_;
};

TEST_F(FilterThresholdTest, HasCorrectName) {
  EXPECT_EQ(thresh_.name(), "Threshold");
}

TEST_F(FilterThresholdTest, HasCorrectMask) {
  // Get Mask from pen and compare with
  // what it is supposed to be.
}
