/**
Copyright (c) 2018 Joowon Kim, University of Minnesota.
	...
*/

#include <math.h>
#include <iostream>
#include <exception>
#include "gtest/gtest.h"
#include "mia/command_line_processor.h"
#include "imagetools/pixel_buffer.h"

using image_tools::CommandLineProcessor;

class CommandLineTest : public ::testing::Test {
  void SetUp() override {
  command_line_processor = new CommandLineProcessor();
}

 protected:
  image_tools::CommandLineProcessor* command_line_processor;
};

TEST_F(CommandLineTest, HasHelpMessage) {
  testing::internal::CaptureStdout();
  command_line_processor->PrintHelpMessage();
  std::string output = testing::internal::GetCapturedStdout();

  std::string expecting = std::string(
  "usage: mia infile.png [image processing commands ...] outfile.png\n\n"
  "infile.png:          input image file in png format\n"
  "outfile.png:         filename to use for saving the result\n\n"
  "image processing commands:\n"
  "-blur r:             apply a gaussian blur of radius r\n"
  "-edgedetect:         apply an edge detection filter\n"
  "-sharpen r:          apply a sharpening filter of radius r\n"
  "-red s:              scale the red channel by factor s\n"
  "-green s:            scale the green channel by factor s\n"
  "-blue s              scale the blue cahnnel by factos s\n"
  "-quantize n:         quantize each color channel into n bins\n"
  "-saturate s:         saturate colors by scale factos s\n"
  "-threshold c:        threshold using cutoff value c\n"
  "-motionblur-n-s r:   north-south motion blur with kernel radius r\n"
  "-motionblur-e-w r:   east-west motion blur with kernel radius r\n"
  "-motionblur-ne-sw r: ne-sw motion blur with kernel radius r\n"
  "-motionblur-nw-se r: nw-se motion blur with kernel radius r\n");

  EXPECT_EQ(output, expecting);
}

TEST_F(CommandLineTest, inValidCommandLine) {
  // CommandLineProcessor test = new CommandLineProcessor();
  char* argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(2, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, EdgeCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("edge"), strdup("resources/edge_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(4, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, BlurCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("blur"), strdup("5"),
                  strdup("resources/blur_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, SharpenCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("sharpen"), strdup("5"),
                  strdup("resources/sharpen5_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, RedCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("red"), strdup("3"),
                  strdup("resources/red3_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, GreenCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("green"), strdup("3"),
                  strdup("resources/green3_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, BlueCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("blue"), strdup("3"),
                  strdup("resources/blue3_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, QuantizeCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("quantize"), strdup("2"),
                  strdup("resources/quantize2_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, SaturateCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("saturate"), strdup("3"),
                  strdup("resources/saturate3_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, ThresholdCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("threshold"), strdup("0.7"),
                  strdup("resources/threshold0.7_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, MBLUR_NSCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("motionblur-n-s"), strdup("5"),
                  strdup("resources/motionblurNS5_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, MBLUR_EWCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("motionblur-e-w"), strdup("5"),
                  strdup("resources/motionblurEW5_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, MBLUR_NESWCommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("motionblur-ne-sw"), strdup("5"),
                  strdup("resources/motionblurNESW5_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(CommandLineTest, MBLUR_NWSECommandLine) {
  char * argv[] = {strdup("./build/bin/mia"), strdup("resources/test.png"),
                  strdup("motionblur-nw-se"), strdup("5"),
                  strdup("resources/motionblurNWSE5_output.png")};
  testing::internal::CaptureStdout();
  command_line_processor->ProcessCommandLine(5, argv);
  std::string output = testing::internal::GetCapturedStdout();
}
