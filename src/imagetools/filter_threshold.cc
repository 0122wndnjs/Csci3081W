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

#include "imagetools/filter_threshold.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

FilterThreshold::FilterThreshold(float cutoff_value)
                                                  : threshold_(cutoff_value) {}

FilterThreshold::FilterThreshold() : threshold_(0.5) {}

FilterThreshold::~FilterThreshold() {}

float FilterThreshold::cutoff_value() { return threshold_; }

void FilterThreshold::set_cutoff_value(float value) { threshold_ = value; }

ColorData FilterThreshold::CalculateFilteredPixel(const PixelBuffer &buffer,
                                                  int x, int y) {
  ColorData c = buffer.pixel(x, y);
  float avg = (c.red() + c.green() + c.blue()) / 3.0f;
  if (c.alpha() < 1.0) {
    ColorData c_bg = buffer.background_color();
    float avg_bg = (c_bg.red() + c_bg.green() + c_bg.blue()) / 3.0f;
    avg = avg * c.alpha() + avg_bg * (1.0 - c.alpha());
  }
  if (avg < threshold_) {
    return ColorData(0.0f, 0.0f, 0.0f);
  } else {
    return ColorData(1.0f, 1.0f, 1.0f);
  }
}
}  // namespace image_tools
