/**
Copyright (c) 2018 Joowon Kim, University of Minnesota.
	...
*/

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/filter_quantize.h"

using image_tools::FilterQuantize;

class FilterQuantizeTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  FilterQuantize quant_;
};

TEST_F(FilterQuantizeTest, HasCorrectName) {
  EXPECT_EQ(quant_.name(), "Quantize");
}

TEST_F(FilterQuantizeTest, HasCorrectMask) {
  // Get Mask from pen and compare with
  // what it is supposed to be.
}
