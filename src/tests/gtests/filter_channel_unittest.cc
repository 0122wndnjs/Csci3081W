/**
Copyright (c) 2018 Joowon Kim, University of Minnesota.
	...
*/

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/filter_channel.h"

using image_tools::FilterChannel;

class FilterChannelTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  FilterChannel chann_;
};

TEST_F(FilterChannelTest, HasCorrectName) {
  EXPECT_EQ(chann_.name(), "Channel");
}

TEST_F(FilterChannelTest, HasCorrectMask) {
  // Get Mask from pen and compare with
  // what it is supposed to be.
}
