/**
Copyright (c) 2018 Joowon Kim, University of Minnesota.
	...
*/

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/filter_saturate.h"

using image_tools::FilterSaturate;

class FilterSaturateTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  FilterSaturate satur_;
};

TEST_F(FilterSaturateTest, HasCorrectName) {
  EXPECT_EQ(satur_.name(), "Saturate");
}

TEST_F(FilterSaturateTest, HasCorrectMask) {
  // Get Mask from pen and compare with
  // what it is supposed to be.
}
