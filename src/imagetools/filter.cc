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

#include "imagetools/filter.h"

namespace image_tools {

Filter::Filter() {}

Filter::~Filter() {}

void Filter::ApplyToBuffer(PixelBuffer *buffer) {
  PixelBuffer *source = buffer;
  PixelBuffer *dest = buffer;

  if (!can_calculate_in_place()) {
    // create a temporary source buffer
    source = new PixelBuffer(*buffer);
  }

  SetupFilter();

  for (int i = 0; i < source->width(); i++) {
    for (int j = 0; j < source->height(); j++) {
      ColorData p = CalculateFilteredPixel(*source, i, j);
      p.Clamp();
      dest->set_pixel(i, j, p);
    }
  }

  CleanupFilter();

  if (!can_calculate_in_place()) {
    delete source;
  }
}

bool Filter::can_calculate_in_place() const { return true; }

void Filter::SetupFilter() {}

ColorData Filter::CalculateFilteredPixel(const PixelBuffer &buffer, int x,
                                         int y) {
  return buffer.pixel(x, y);
}

void Filter::CleanupFilter() {}

} /* namespace image_tools */
