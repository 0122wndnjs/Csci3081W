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

#ifndef IMAGETOOLS_FILTER_THRESHOLD_H_
#define IMAGETOOLS_FILTER_THRESHOLD_H_

#include <string>
#include "imagetools/color_data.h"
#include "imagetools/filter.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

/** @brief A threshold filter that converts each pixel of the image to pure
 black
 or white.  First, each pixel is converted to a grayscale value, then the result
 is compared to the cutoff value.  If greater than the cutoff, then the pixel
 is set to white, and if less it is set to black. */
class FilterThreshold : public Filter {
 public:
  explicit FilterThreshold(float cutoff_value);
  FilterThreshold();

  virtual ~FilterThreshold();

  float cutoff_value();
  void set_cutoff_value(float value);

  /** Cacluating each pixel by converting each pixel to a gray scale value and
  comparing with cutoff value. */
  ColorData CalculateFilteredPixel(const PixelBuffer &buffer, int x,
                                   int y) override;

  static const std::string name() { return "Threshold"; }

 private:
  float threshold_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_THRESHOLD_H_
