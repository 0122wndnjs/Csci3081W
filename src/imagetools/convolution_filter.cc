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
  Daniel Keefe, 2018, UMN
      - revised version of original filter_convolve.h/cc,
      - added factory method
  ...
*/

#include "imagetools/convolution_filter.h"

#include <stdio.h>

#include "imagetools/color_data.h"
#include "imagetools/image_tools_math.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

ConvolutionFilter::ConvolutionFilter() : kernel_(NULL) {}

ConvolutionFilter::~ConvolutionFilter() {
  if (kernel_ != NULL) {
    delete kernel_;
  }
}

void ConvolutionFilter::SetupFilter() { kernel_ = CreateKernel(); }

ColorData ConvolutionFilter::CalculateFilteredPixel(const PixelBuffer &buffer,
                                                    int x, int y) {
  int half_width = kernel_->width() / 2;
  int half_height = kernel_->height() / 2;
  int buffer_width = buffer.width();
  int buffer_height = buffer.height();
  ColorData result(0, 0, 0, 0);

#pragma omp for
  for (int i = 0; i < kernel_->width(); i++) {
    for (int j = 0; j < kernel_->height(); j++) {
      int c_x = x + i - half_width;
      int c_y = y + j - half_height;
      c_y = ImageToolsMath::Clamp(c_y, 0, buffer_height - 1);
      c_x = ImageToolsMath::Clamp(c_x, 0, buffer_width - 1);

      ColorData original = buffer.pixel(c_x, c_y);
      float a = original.alpha();
      ColorData premult = original * a;
      premult.set_alpha(a);

      ColorData weight = premult * kernel_->value(i, j);
      if (!convolve_alpha()) {
        weight.set_alpha(a);
      }
      result = result + weight;
    }
  }

  return result;
}

void ConvolutionFilter::CleanupFilter() {
  delete kernel_;
  kernel_ = NULL;
}

bool ConvolutionFilter::convolve_alpha() const { return false; }

} /* namespace image_tools */
