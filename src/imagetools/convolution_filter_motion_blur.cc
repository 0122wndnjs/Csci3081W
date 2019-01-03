/**
 This file is part of the CSCI-3081W Project Support Code, which was developed
 at the University of Minnesota.
 This code is to be used for student coursework.  It is not an open source
 project.
 Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
 Minnesota.
 Original Author(s) of this File:
 Seth Johnson, 2/15/15, University of Minnesota
 Author(s) of Significant Updates/Modifications to the File:
 ...
 */

#include "imagetools/convolution_filter_motion_blur.h"
#include <cmath>

namespace image_tools {

ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur()
    : radius_(5.0), dir_(MBLUR_DIR_N_S) {}

ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur(float radius,
                                                         MBlurDir dir)
    : radius_(radius), dir_(dir) {}

ConvolutionFilterMotionBlur::~ConvolutionFilterMotionBlur() {}

FloatMatrix* ConvolutionFilterMotionBlur::CreateKernel() {
  FloatMatrix* kernel =
      new FloatMatrix(round(radius_ * 2.0) + 1, round(radius_ * 2.0) + 1);

  for (int j = 0; j < kernel->height(); j++) {
    for (int i = 0; i < kernel->width(); i++) {
      int x = i - kernel->width() / 2;
      int y = j - kernel->height() / 2;

      float intensity = 0.0;
      switch (dir_) {
        case MBLUR_DIR_N_S:
          intensity = (x == 0) ? 1 : 0;
          break;
        case MBLUR_DIR_E_W:
          intensity = (y == 0) ? 1 : 0;
          break;
        case MBLUR_DIR_NE_SW:
          intensity = (y == x) ? 1 : 0;
          break;
        case MBLUR_DIR_NW_SE:
          intensity = (y == -x) ? 1 : 0;
          break;
        default:
          break;
      }
      kernel->set_value(i, j, intensity);
    }
  }
  kernel->Normalize();

  return kernel;
}

bool ConvolutionFilterMotionBlur::convolve_alpha() const { return true; }

ConvolutionFilterMotionBlur::MBlurDir ConvolutionFilterMotionBlur::direction() {
  return dir_;
}

void ConvolutionFilterMotionBlur::set_direction(MBlurDir dir) { dir_ = dir; }

float ConvolutionFilterMotionBlur::radius() { return radius_; }

void ConvolutionFilterMotionBlur::set_radius(float r) {
  radius_ = r;
  if (radius_ < 1.0) {
    radius_ = 1.0;
  }
}

}  // namespace image_tools
