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
#include "imagetools/convolution_filter_sharpen.h"

#include "imagetools/image_tools_math.h"


namespace image_tools {

ConvolutionFilterSharpen::ConvolutionFilterSharpen(float radius)
    : radius_(radius) {}

ConvolutionFilterSharpen::ConvolutionFilterSharpen() : radius_(5.0) {}

ConvolutionFilterSharpen::~ConvolutionFilterSharpen() {}

FloatMatrix* ConvolutionFilterSharpen::CreateKernel() {
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

  // Negate all the values
  kernel->Scale(-1.0);

  // Add two to the middle
  float middle_value = kernel->value(kernel->width() / 2, kernel->height() / 2);
  kernel->set_value(kernel->width() / 2, kernel->height() / 2,
                    middle_value + 2.0);

  return kernel;
}

bool ConvolutionFilterSharpen::convolve_alpha() const { return true; }

float ConvolutionFilterSharpen::radius() { return radius_; }

void ConvolutionFilterSharpen::set_radius(float r) { radius_ = r; }

}  // namespace image_tools
