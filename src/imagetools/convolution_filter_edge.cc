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

#include "imagetools/convolution_filter_edge.h"

#include <cmath>

namespace image_tools {

ConvolutionFilterEdge::ConvolutionFilterEdge() {}

ConvolutionFilterEdge::~ConvolutionFilterEdge() {}

FloatMatrix* ConvolutionFilterEdge::CreateKernel() {
  FloatMatrix* kernel = new FloatMatrix(3, 3);
  kernel->Scale(-1.0);
  kernel->set_value(1, 1, 8.0);
  return kernel;
}

bool ConvolutionFilterEdge::convolve_alpha() const { return false; }

}  // namespace image_tools
