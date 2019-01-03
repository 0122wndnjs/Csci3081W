/**
Copyright (c) 2018 Joowon Kim, University of Minnesota.
	...
*/

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"
#include "imagetools/image_editor.h"

using image_tools::ColorData;
using image_tools::PixelBuffer;
using image_tools::FloatMatrix;
using image_tools::ImageEditor;
using image_tools::ToolBlur;
using image_tools::ToolCalligraphyPen;
using image_tools::ToolChalk;
using image_tools::ToolEraser;
using image_tools::ToolHighlighter;
using image_tools::ToolPen;
using image_tools::ToolSprayCan;
using image_tools::ToolStamp;

class RegressionToolTest : public ::testing::Test {
  void SetUp() override {
    image_editor_test = new ImageEditor();
    pixelA = new PixelBuffer(50, 50, ColorData(1.0, 1.0, 1.0, 1.0));
    image_editor_test->set_pixel_buffer(pixelA);
    image_editor_compare = new ImageEditor();
    pixelB = new PixelBuffer(50, 50, ColorData(1.0, 1.0, 1.0, 1.0));
    image_editor_compare->set_pixel_buffer(pixelB);
  }

  void TearDown() override {
    delete image_editor_test;
    delete image_editor_compare;
    delete pixelA;
    delete pixelB;
  }

 protected:
  image_tools::ImageEditor* image_editor_test;
  image_tools::ImageEditor* image_editor_compare;
  image_tools::PixelBuffer* pixelA;
  image_tools::PixelBuffer* pixelB;

  ToolBlur blur_;
  ToolCalligraphyPen calligraphy_;
  ToolChalk chalk_;
  ToolEraser eraser_;
  ToolHighlighter highlighter_;
  ToolPen pen_;
  ToolSprayCan spraycan_;
  ToolStamp stamp_;
};

TEST_F(RegressionToolTest, ToolPenTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string pen_image = "resources/ToolTest/tool_pen.png";
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  PixelBuffer* buffer = image_editor_test->pixel_buffer();
  ColorData paint_color = ColorData(0.0, 0.7, 0.0);
  float tool_radius = 30.0;
  int x = 400;
  int y = 100;
  int y2 = 400;
  // ColorData previous_color = buffer->pixel(x,y);
  pen_.StartStroke(buffer, x, y, paint_color, tool_radius);
  pen_.AddToStroke(x, y2);
  pen_.EndStroke(x, y2);
  // ColorData new_color = buffer->pixel(x, y + (y2-y)/2);
  buffer = image_editor_test->pixel_buffer();
  image_editor_test->SaveToFile(pen_image);
  image_editor_compare->LoadFromFile(pen_image);

  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);
}

TEST_F(RegressionToolTest, ToolCalligraphyPenTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string calligraphypen_image =
                                  "resources/ToolTest/tool_calligraphypen.png";
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  PixelBuffer* buffer = image_editor_test->pixel_buffer();
  ColorData paint_color = ColorData(0.0, 0.7, 0.0);
  float tool_radius = 30.0;
  int x = 400;
  int y = 100;
  int y2 = 400;
  calligraphy_.StartStroke(buffer, x, y, paint_color, tool_radius);
  calligraphy_.AddToStroke(x, y2);
  calligraphy_.EndStroke(x, y2);

  buffer = image_editor_test->pixel_buffer();
  image_editor_test->SaveToFile(calligraphypen_image);
  image_editor_compare->LoadFromFile(calligraphypen_image);

  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);
}

TEST_F(RegressionToolTest, ToolChalkTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string chalk_image = "resources/ToolTest/tool_chalk.png";
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  PixelBuffer* buffer = image_editor_test->pixel_buffer();
  ColorData paint_color = ColorData(0.0, 0.7, 0.0);
  float tool_radius = 30.0;
  int x = 400;
  int y = 100;
  int y2 = 400;
  chalk_.StartStroke(buffer, x, y, paint_color, tool_radius);
  chalk_.AddToStroke(x, y2);
  chalk_.EndStroke(x, y2);

  buffer = image_editor_test->pixel_buffer();
  image_editor_test->SaveToFile(chalk_image);
  image_editor_compare->LoadFromFile(chalk_image);

  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);
}

TEST_F(RegressionToolTest, ToolHighlighterTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string highlighter_image = "resources/ToolTest/tool_highlighter.png";
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  PixelBuffer* buffer = image_editor_test->pixel_buffer();
  ColorData paint_color = ColorData(0.0, 0.7, 0.0);
  float tool_radius = 30.0;
  int x = 400;
  int y = 100;
  int y2 = 400;
  highlighter_.StartStroke(buffer, x, y, paint_color, tool_radius);
  highlighter_.AddToStroke(x, y2);
  highlighter_.EndStroke(x, y2);

  buffer = image_editor_test->pixel_buffer();
  image_editor_test->SaveToFile(highlighter_image);
  image_editor_compare->LoadFromFile(highlighter_image);

  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);
}

TEST_F(RegressionToolTest, ToolSprayCanTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string spraycan_image = "resources/ToolTest/tool_spraycan.png";
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  PixelBuffer* buffer = image_editor_test->pixel_buffer();
  ColorData paint_color = ColorData(0.0, 0.7, 0.0);
  float tool_radius = 30.0;
  int x = 400;
  int y = 100;
  int y2 = 400;
  spraycan_.StartStroke(buffer, x, y, paint_color, tool_radius);
  spraycan_.AddToStroke(x, y2);
  spraycan_.EndStroke(x, y2);

  buffer = image_editor_test->pixel_buffer();
  image_editor_test->SaveToFile(spraycan_image);
  image_editor_compare->LoadFromFile(spraycan_image);

  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);
}

TEST_F(RegressionToolTest, ToolStampTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string stamp_image = "resources/ToolTest/tool_stamp.png";
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  PixelBuffer* buffer = image_editor_test->pixel_buffer();
  ColorData paint_color = ColorData(0.0, 0.7, 0.0);
  float tool_radius = 30.0;
  int x = 400;
  int y = 100;
  int y2 = 400;
  stamp_.StartStroke(buffer, x, y, paint_color, tool_radius);
  stamp_.AddToStroke(x, y2);
  stamp_.EndStroke(x, y2);

  buffer = image_editor_test->pixel_buffer();
  image_editor_test->SaveToFile(stamp_image);
  image_editor_compare->LoadFromFile(stamp_image);

  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);
}

TEST_F(RegressionToolTest, ToolBlurTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string blur_image = "resources/ToolTest/tool_blur.png";
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  PixelBuffer* buffer = image_editor_test->pixel_buffer();
  ColorData paint_color = ColorData(0.0, 0.7, 0.0);
  float tool_radius = 30.0;
  int x = 400;
  int y = 100;
  int y2 = 400;
  blur_.StartStroke(buffer, x, y, paint_color, tool_radius);
  blur_.AddToStroke(x, y2);
  blur_.EndStroke(x, y2);

  buffer = image_editor_test->pixel_buffer();
  image_editor_test->SaveToFile(blur_image);
  image_editor_compare->LoadFromFile(blur_image);

  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);
}

TEST_F(RegressionToolTest, ToolEraserTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string eraser_image = "resources/ToolTest/tool_eraser.png";
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  PixelBuffer* buffer = image_editor_test->pixel_buffer();
  ColorData paint_color = ColorData(0.0, 0.7, 0.0);
  float tool_radius = 30.0;
  int x = 400;
  int y = 100;
  int y2 = 400;
  eraser_.StartStroke(buffer, x, y, paint_color, tool_radius);
  eraser_.AddToStroke(x, y2);
  eraser_.EndStroke(x, y2);

  buffer = image_editor_test->pixel_buffer();
  image_editor_test->SaveToFile(eraser_image);
  image_editor_compare->LoadFromFile(eraser_image);

  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);
}
