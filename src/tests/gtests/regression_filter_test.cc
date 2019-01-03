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
using image_tools::FilterThreshold;
using image_tools::FilterSaturate;
using image_tools::FilterQuantize;
using image_tools::FilterChannel;
using image_tools::ConvolutionFilterBlur;
using image_tools::ConvolutionFilterSharpen;
using image_tools::ConvolutionFilterEdge;
using image_tools::ConvolutionFilterMotionBlur;

class RegressionFilterTest : public ::testing::Test {
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
};

TEST_F(RegressionFilterTest, FilterSaturateTest) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string saturate_image = "resources/FilterTest/saturate_3_test.png";

  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplySaturateFilter(3.0);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(saturate_image);

  PixelBuffer* applied_buffer =
                          new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the saved image and loaded image
  image_editor_compare->LoadFromFile(saturate_image);

  PixelBuffer* new_buffer = new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the pixel by using EXPECT_EQ
  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);

  delete applied_buffer;
  delete new_buffer;
}

TEST_F(RegressionFilterTest, FilterThreshold) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string threshold_image = "resources/FilterTest/threshold_0.7_test.png";

  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyThresholdFilter(0.7);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(threshold_image);

  PixelBuffer* applied_buffer =
                            new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the saved image and loaded image
  image_editor_compare->LoadFromFile(threshold_image);

  PixelBuffer* new_buffer = new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the pixel by using EXPECT_EQ
  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);

  delete applied_buffer;
  delete new_buffer;
}

TEST_F(RegressionFilterTest, FilterQuantize) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string quantize_image = "resources/FilterTest/quantize_2_test.png";

  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyQuantizeFilter(2);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(quantize_image);

  PixelBuffer* applied_buffer =
                            new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the saved image and loaded image
  image_editor_compare->LoadFromFile(quantize_image);

  PixelBuffer* new_buffer = new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the pixel by using EXPECT_EQ
  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);

  delete applied_buffer;
  delete new_buffer;
}

TEST_F(RegressionFilterTest, FilterChannel) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string red_image = "resources/FilterTest/red_3.0_test.png";
  std::string green_image = "resources/FilterTest/green_3.0_test.png";
  std::string blue_image = "resources/FilterTest/blue_3.0_test.png";

  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyChannelsFilter(3.0, 1.0, 1.0);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(red_image);
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyChannelsFilter(1.0, 3.0, 1.0);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(green_image);
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyChannelsFilter(1.0, 1.0, 3.0);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(blue_image);

  PixelBuffer* applied_buffer =
                            new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the saved image and loaded image
  image_editor_compare->LoadFromFile(red_image);
  image_editor_compare->LoadFromFile(green_image);
  image_editor_compare->LoadFromFile(blue_image);
  PixelBuffer* new_buffer = new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the pixel by using EXPECT_EQ
  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);

  delete applied_buffer;
  delete new_buffer;
}

TEST_F(RegressionFilterTest, ConvolutionFilterEdge) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string edge_image = "resources/FilterTest/edge_test.png";

  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyEdgeDetectFilter();
  // by using image_editor, save output file
  image_editor_test->SaveToFile(edge_image);

  PixelBuffer* applied_buffer =
                            new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the saved image and loaded image
  image_editor_compare->LoadFromFile(edge_image);

  PixelBuffer* new_buffer = new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the pixel by using EXPECT_EQ
  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);

  delete applied_buffer;
  delete new_buffer;
}

TEST_F(RegressionFilterTest, ConvolutionFilterSharpen) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string sharpen_image = "resources/FilterTest/sharpen_5_test.png";

  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplySharpenFilter(5.0);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(sharpen_image);

  PixelBuffer* applied_buffer =
                            new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the saved image and loaded image
  image_editor_compare->LoadFromFile(sharpen_image);

  PixelBuffer* new_buffer = new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the pixel by using EXPECT_EQ
  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);

  delete applied_buffer;
  delete new_buffer;
}

TEST_F(RegressionFilterTest, ConvolutionFilterBlur) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string blur_image = "resources/FilterTest/blur_5_test.png";

  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyBlurFilter(5.0);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(blur_image);

  PixelBuffer* applied_buffer =
                            new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the saved image and loaded image
  image_editor_compare->LoadFromFile(blur_image);

  PixelBuffer* new_buffer = new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the pixel by using EXPECT_EQ
  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);

  delete applied_buffer;
  delete new_buffer;
}

TEST_F(RegressionFilterTest, ConvolutionFilterMotionBlur) {
  // setting the original image path
  std::string orig_image = "resources/test.png";
  // setting the output file image path
  std::string n_s_image = "resources/FilterTest/motionblur_ns_5_test.png";
  std::string e_w_image = "resources/FilterTest/motionblur_ew_5_test.png";
  std::string ne_sw_image = "resources/FilterTest/motionblur_nesw_5_test.png";
  std::string nw_se_image = "resources/FilterTest/motionblur_nwse_5_test.png";

  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyMotionBlurFilter(5.0,
                                    ConvolutionFilterMotionBlur::MBLUR_DIR_N_S);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(n_s_image);
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyMotionBlurFilter(5.0,
                                    ConvolutionFilterMotionBlur::MBLUR_DIR_E_W);
  image_editor_test->SaveToFile(e_w_image);
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyMotionBlurFilter(5.0,
                                  ConvolutionFilterMotionBlur::MBLUR_DIR_NE_SW);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(ne_sw_image);
  // by using image_editor, load the original file
  image_editor_test->LoadFromFile(orig_image);
  // by using image_editor, apply filter
  image_editor_test->ApplyMotionBlurFilter(5.0,
                                  ConvolutionFilterMotionBlur::MBLUR_DIR_NW_SE);
  // by using image_editor, save output file
  image_editor_test->SaveToFile(nw_se_image);

  PixelBuffer* applied_buffer =
                            new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the saved image and loaded image
  image_editor_compare->LoadFromFile(n_s_image);
  image_editor_compare->LoadFromFile(e_w_image);
  image_editor_compare->LoadFromFile(ne_sw_image);
  image_editor_compare->LoadFromFile(nw_se_image);

  PixelBuffer* new_buffer = new PixelBuffer(*image_editor_test->pixel_buffer());
  // compare the pixel by using EXPECT_EQ
  EXPECT_EQ(((*image_editor_test->pixel_buffer())) ==
                                (*image_editor_compare->pixel_buffer()), true);

  delete applied_buffer;
  delete new_buffer;
}
