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

#include "imagetools/filter_saturate.h"
#include <cmath>
#include "imagetools/color_data.h"
#include "imagetools/image_tools_math.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

FilterSaturate::FilterSaturate(float scale) : scale_(scale) {}

FilterSaturate::FilterSaturate() : scale_(1.0) {}

FilterSaturate::~FilterSaturate() {}

float FilterSaturate::scale_factor() { return scale_; }

void FilterSaturate::set_scale_factor(float s) { scale_ = s; }

ColorData FilterSaturate::CalculateFilteredPixel(const PixelBuffer &buffer,
                                                 int x, int y) {
  ColorData c = buffer.pixel(x, y);
  float lum = c.Luminance();
  ColorData gray(lum, lum, lum);

  ColorData output = ImageToolsMath::Lerp(gray, c, scale_);
  return output;
}

}  // namespace image_tools
