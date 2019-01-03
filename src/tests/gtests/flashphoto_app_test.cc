// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <iostream>
#include "gtest/gtest.h"
#include "flashphoto/flashphoto_app.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_editor.h"
#include "imagetools/tool_pen.h"
#include "imageio/image_manager.h"
#include "imageio/image.h"

using image_tools::FlashPhotoApp;
using image_tools::ColorData;
using image_tools::PixelBuffer;
using image_tools::FloatMatrix;
using image_tools::ImageEditor;

class FlashPhotoAppTest : public ::testing::Test {
  void SetUp() override {
    app_ = new FlashPhotoApp(1024, 780, image_tools::ColorData(1, 1, 1));
  }

  void TearDown() override {
    delete app_;
  }

  // We need to write this method
  void ComparePixelBuffers(const PixelBuffer& bufA, const PixelBuffer& bufB) {
    ColorData newA, newB;

    for (int i = 0; i < bufA.width(); i++) {
      for (int j = 0; j < bufB.height(); j++) {
        newA = bufA.pixel(i, j);
        newB = bufB.pixel(i, j);

        if (newA.red()-newB.red() > 0 || newA.green()-newB.green() > 0
        || newA.blue()-newB.blue() > 0) {
        printf("Incorrect color at x = %d, y = %d\n", i, j);
        printf("Correct color: r = %f, g = %f, b = %f\n",
                                        newA.red(), newA.green(), newA.blue());
        printf("Actual color: r = %f, g = %f, b = %f\n",
                                        newB.red(), newB.green(), newB.blue());
        }
        return;
      }
    }
  }

 protected:
  FlashPhotoApp *app_;
};

TEST_F(FlashPhotoAppTest, GetToolTest) {
  // image_tools::Tool* pen = app_->GetToolByName("Pen");
  // EXPECT_TRUE(pen);
  // image_tools::Tool* unknownTool = app_->GetToolByName("Unknown");
  // EXPECT_FALSE(unknownTool);
}

TEST_F(FlashPhotoAppTest, CanApplyFilters) {
  // For each filter {
  //   Copy pixel buffer from app_
  //   Apply filter
  //   Get new pixel buffer
  //   ComparePixelBuffers() to see if there was a change
  // }
}
