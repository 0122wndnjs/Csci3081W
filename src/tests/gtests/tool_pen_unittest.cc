// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/tool_pen.h"

using image_tools::ToolPen;
using image_tools::FloatMatrix;
using image_tools::PixelBuffer;
using image_tools::ColorData;

class ToolPenTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ToolPen pen_;
};

TEST_F(ToolPenTest, HasCorrectName) {
  EXPECT_EQ(pen_.name(), "Pen");
}

TEST_F(ToolPenTest, HasCorrectMask) {
  // Get Mask from pen and compare with
  // what it is supposed to be.
  FloatMatrix* pen_FM_positive = pen_.CreateMask(3.3);  // radius = 3.3
    FloatMatrix* pen_FM_zero = pen_.CreateMask(0);

    // 1. check if size = 9 = 2 * ceil(3.3) + 1
    EXPECT_EQ(pen_FM_positive->width(), 9) << "Incorrect width of Pen Mask";
    EXPECT_EQ(pen_FM_positive->height(), 9) << "Incorrect height of Pen Mask";

    EXPECT_EQ(pen_FM_zero->width(), 1) << "Incorrect width of Pen Mask";
    EXPECT_EQ(pen_FM_zero->height(), 1) << "Incorrect height of Pen Mast";

    // 2. check center value, corner value of mask
    EXPECT_EQ(pen_FM_positive->value(3, 3), 1.0)
      << "Incorrect center value of Pen Mask";  // center should be 1.0
    EXPECT_EQ(pen_FM_positive->value(0, 0), 0.0)
      << "Incorrect corner value of Pen Mask";  // corner should be 0.0
    EXPECT_EQ(pen_FM_zero->value(0, 0), 1.0)
      << "Incorrect center value of Pen Mask";  // center should be 1.0

    // delete FloatMatrices
    delete pen_FM_positive;
    delete pen_FM_zero;
}
