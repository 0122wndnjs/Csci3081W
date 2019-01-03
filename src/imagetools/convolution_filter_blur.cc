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
#include <cmath>


#include "imagetools/convolution_filter_blur.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterBlur::ConvolutionFilterBlur(float radius) : radius_(radius) {}

ConvolutionFilterBlur::ConvolutionFilterBlur() : radius_(5.0) {}

ConvolutionFilterBlur::~ConvolutionFilterBlur() {}

FloatMatrix* ConvolutionFilterBlur::CreateKernel() {
  FloatMatrix* kernel =
      new FloatMatrix(round(radius_ * 2.0) + 1, round(radius_ * 2.0) + 1);

  for (int j = 0; j < kernel->height(); j++) {
    for (int i = 0; i < kernel->width(); i++) {
      int x = i - kernel->width() / 2;
      int y = j - kernel->height() / 2;
      float dist = sqrt(x * x + y * y);
      float intensity = ImageToolsMath::Gaussian(dist, radius_);
      kernel->set_value(i, j, intensity);
    }
  }
  kernel->Normalize();

  return kernel;
}

bool ConvolutionFilterBlur::convolve_alpha() const { return true; }

float ConvolutionFilterBlur::radius() { return radius_; }

void ConvolutionFilterBlur::set_radius(float r) {
  radius_ = r;
  if (radius_ < 1.0) {
    radius_ = 1.0;
  }
}

}  // namespace image_tools
