/**
Copyright (c) 2018 Joowon Kim, University of Minnesota.
	...
*/

#include <string>
#include <cmath>
#include <iostream>
#include <exception>
#include "mia/command_line_processor.h"
#include "mia/image_editor_commands.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/color_data.h"
#include "/classes/csel-f18c3081/include/imageio/image_manager.h"

namespace image_tools {
  CommandLineProcessor::CommandLineProcessor() {}

  CommandLineProcessor::~CommandLineProcessor() {}

  void CommandLineProcessor::ProcessCommandLine(int argc, char* argv[]) {
    try {
      char** argument = argv;
      std::string input_file_ = argument[1];  // setting input file
      std::string output_file_ = argument[argc - 1];  // setting output file
      int input_len = input_file_.length();  // setting input file length
      int output_len = output_file_.length();  // setting output file length

      image_editor_ = new ImageEditor();

      if (input_len > 4 && output_len > 4
        && input_file_.substr(input_len - 4) == ".png" &&
        output_file_.substr(output_len - 4) == ".png") {
        // when png is detected and when the length are longer than 4 since
        // .png is 4 characters, load image
        image_editor_command_ = new LoadCommand(image_editor_, input_file_);
        image_editor_command_->Execute();

      if (argc == 2) {
        // when only 2 arguments given, invalid
        std::cout << "invalid argument" << std::endl;
      }

      if (argc > 3) {
        // when 3 or more arguments given, apply filters
        for (int i = 2; i < argc - 1; i++) {
          if (argument[i] == std::string("-edgedetect")) {
            // edgedetect filter,
            image_editor_command_ =
              new EdgeFilterCommand(image_editor_);
            image_editor_command_->Execute();
          } else {
            if (i + 1 < argc - 1) {
              if (argument[i] == std::string("-blur")) {
                // blur filter
                float r = std::stof(argument[i+1]);
                if (r < 0) {
                  throw "Blur amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new BlurFilterCommand(image_editor_, r);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-sharpen")) {
                // sharpen filter
                float r = std::stof(argument[i+1]);
                if (r < 0) {
                  throw "Sharpen amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new SharpenFilterCommand(image_editor_, r);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-red")) {
                // channel filter red
                float s = std::stof(argument[i+1]);
                if (s < 0) {
                  throw "Red amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new ChannelsFilterCommand(image_editor_, s, 1.0, 1.0);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-green")) {
                // channel filter green
                float s = std::stof(argument[i+1]);
                if (s < 0) {
                  throw "Green amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new ChannelsFilterCommand(image_editor_, 1.0, s, 1.0);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-blue")) {
                // channel filter blue
                float s = std::stof(argument[i+1]);
                if (s < 0) {
                  throw "Blue amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new ChannelsFilterCommand(image_editor_, 1.0, 1.0, s);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-quantize")) {
                // quantize filter
                float n = std::stof(argument[i+1]);
                if (n < 0) {
                  throw "Quantize amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new QuantizeFilterCommand(image_editor_, n);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-saturate")) {
                // saturate filter
                float s = std::stof(argument[i+1]);
                if (s < 0) {
                  throw "saturate amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new SaturateFilterCommand(image_editor_, s);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-threshold")) {
                // threshold filter
                float c = std::stof(argument[i+1]);
                if (c < 0) {
                  throw "Threshold amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new ThresholdFilterCommand(image_editor_, c);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-motionblur-n-s")) {
                // motionblur north-south
                float r = std::stof(argument[i+1]);
                if (r < 0) {
                  throw "Blur amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new MotionBlurFilterCommand(image_editor_, r,
                    ConvolutionFilterMotionBlur::MBlurDir::MBLUR_DIR_N_S);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-motionblur-e-w")) {
                // motionblur east-west
                float r = std::stof(argument[i+1]);
                if (r < 0) {
                  throw "Blur amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new MotionBlurFilterCommand(image_editor_, r,
                    ConvolutionFilterMotionBlur::MBlurDir::MBLUR_DIR_E_W);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-motionblur-ne-sw")) {
                // motionblur northeast-southwest
                float r = std::stof(argument[i+1]);
                if (r < 0) {
                  throw "Blur amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new MotionBlurFilterCommand(image_editor_, r,
                    ConvolutionFilterMotionBlur::MBlurDir::MBLUR_DIR_NE_SW);
                image_editor_command_->Execute();
              } else if (argument[i] == std::string("-motionblur-nw-se")) {
                // motionblur northwest-southeast
                float r = std::stof(argument[i+1]);
                if (r < 0) {
                  throw "Blur amount cannot be less than 0.";
                }
                image_editor_command_ =
                  new MotionBlurFilterCommand(image_editor_, r,
                    ConvolutionFilterMotionBlur::MBlurDir::MBLUR_DIR_NW_SE);
                image_editor_command_->Execute();
              } else {
                // if those filters are not detected, throw error
                throw "-h or invalid arguments";
                return;
              }
              i++;
          } else {
              throw "-h or invalid arguments";
              return;
            }
          }
        }
      }
      // save image
      image_editor_command_ = new SaveCommand(image_editor_, output_file_);
      image_editor_command_->Execute();
    } else {  // if file name is detected wrong, throw error
      throw "-h or invalid arguments";
      return;
    }
  } catch (std::invalid_argument& e) {
    // if error occurs, print out the help message
    PrintHelpMessage();
    // std::cerr << "Exception" << e.what() << std::endl;
  } catch (const char* str) {
    // if error occurs, print out the help message
    PrintHelpMessage();
    // std::cerr << "Exception" << str << std::endl;
  }
  }

  void CommandLineProcessor::PrintHelpMessage() {
    // print out the help message
    std::cout <<
    "usage: mia infile.png [image processing commands ...] outfile.png"
    << std::endl << std::endl <<
    "infile.png:          input image file in png format" << std::endl <<
    "outfile.png:         filename to use for saving the result" << std::endl
    << std::endl <<
    "image processing commands:" << std::endl <<
    "-blur r:             apply a gaussian blur of radius r" << std::endl <<
    "-edgedetect:         apply an edge detection filter" << std::endl <<
    "-sharpen r:          apply a sharpening filter of radius r" << std::endl <<
    "-red s:              scale the red channel by factor s" << std::endl <<
    "-green s:            scale the green channel by factor s" << std::endl <<
    "-blue s              scale the blue cahnnel by factos s" << std::endl <<
    "-quantize n:         quantize each color channel into n bins"
    << std::endl <<
    "-saturate s:         saturate colors by scale factos s" << std::endl <<
    "-threshold c:        threshold using cutoff value c" << std::endl <<
    "-motionblur-n-s r:   north-south motion blur with kernel radius r"
    << std::endl <<
    "-motionblur-e-w r:   east-west motion blur with kernel radius r"
    << std::endl <<
    "-motionblur-ne-sw r: ne-sw motion blur with kernel radius r"
    << std::endl <<
    "-motionblur-nw-se r: nw-se motion blur with kernel radius r" << std::endl;
  }
}  // namespace image_tools
