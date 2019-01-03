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

#include "imagetools/filter_quantize.h"
#include <cmath>
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

FilterQuantize::FilterQuantize(int bins) : bins_(bins) {}

FilterQuantize::FilterQuantize() : bins_(8) {}

FilterQuantize::~FilterQuantize() {}

int FilterQuantize::num_bins() { return bins_; }

void FilterQuantize::set_num_bins(int n) { bins_ = n; }

ColorData FilterQuantize::CalculateFilteredPixel(const PixelBuffer &buffer,
                                                 int x, int y) {
  int steps = bins_ - 1;
  if (steps > 0) {
    ColorData c = buffer.pixel(x, y);
    float red = round(c.red() * steps) / steps;
    float green = round(c.green() * steps) / steps;
    float blue = round(c.blue() * steps) / steps;
    return ColorData(red, green, blue);
  } else {
    return ColorData(0, 0, 0);
  }
}

} /* namespace image_tools */
