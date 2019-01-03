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

#include "imagetools/filter_channel.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

FilterChannel::FilterChannel(float r, float g, float b)
    : red_(r), green_(g), blue_(b) {}

FilterChannel::FilterChannel() : red_(1.0), green_(1.0), blue_(1.0) {}

FilterChannel::~FilterChannel() {}

float FilterChannel::red_scale_factor() { return red_; }

void FilterChannel::set_red_scale_factor(float s) { red_ = s; }

float FilterChannel::green_scale_factor() { return green_; }

void FilterChannel::set_green_scale_factor(float s) { green_ = s; }

float FilterChannel::blue_scale_factor() { return blue_; }

void FilterChannel::set_blue_scale_factor(float s) { blue_ = s; }

ColorData FilterChannel::CalculateFilteredPixel(const PixelBuffer &buffer,
                                                 int x, int y) {
  const ColorData &p = buffer.pixel(x, y);
  ColorData output(p.red() * red_, p.green() * green_, p.blue() * blue_,
                   p.alpha());
  return output;
}

} /* namespace image_tools */
