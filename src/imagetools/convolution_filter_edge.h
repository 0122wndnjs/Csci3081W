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

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_

#include "imagetools/convolution_filter.h"

namespace image_tools {

/** @brief Implements an edge filter using a 3x3 edge kernel. */
class ConvolutionFilterEdge : public ConvolutionFilter {
 public:
  ConvolutionFilterEdge();
  virtual ~ConvolutionFilterEdge();

  /** Creating kernel by proper kernel value */
  FloatMatrix* CreateKernel() override;

  bool convolve_alpha() const override;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_
