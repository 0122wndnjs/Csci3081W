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

#ifndef IMAGETOOLS_FILTER_SATURATE_H_
#define IMAGETOOLS_FILTER_SATURATE_H_

#include <string>
#include "imagetools/color_data.h"
#include "imagetools/filter.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

/** @brief Adjusts the saturation or colorfulness of an image. A scale factor of
 1.0 will have no effect.  A scale factor of greater than 1.0 will "turn up" the
 saturation of the image, making it more colorful, and a factor less than 1.0
 will "turn down" the saturation.  A value of 0.0 will convert the image to
 grayscale. */
class FilterSaturate : public Filter {
 public:
  explicit FilterSaturate(float scale);
  FilterSaturate();

  virtual ~FilterSaturate();

  float scale_factor();
  void set_scale_factor(float s);

  /** Calculating the pixel by the scale of grey. */
  ColorData CalculateFilteredPixel(const PixelBuffer &buffer, int x,
                                           int y) override;

  static const std::string name() { return "Saturate"; }

 private:
  /// (0 = grayscale, 1 = original color, 2 = twice the saturation of the
  /// original)
  float scale_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_SATURATE_H_
