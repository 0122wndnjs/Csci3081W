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

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_H_

#include "imagetools/filter.h"
#include "imagetools/float_matrix.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

/** @brief The base class for filters that use convolution.  These filters
 convolve a kernel with the image by first making a tmp copy of the image
 buffer.
 Then, they loop through each pixel of this copy, centering the kernel on that
 pixel and computing a new color by looking at the original colors of not just
 the current pixel but also its neighbors.  The output is written back to the
 original pixel buffer. */
class ConvolutionFilter : public Filter {
 public:
  ConvolutionFilter();
  virtual ~ConvolutionFilter();

  /** ConvolutionFilters cannot be calculated "in place".  They require
   creating a temporary copy of the input buffer so that they can look up the
   colors of the original pixel values even after some have been modified. */
  bool can_calculate_in_place() const override { return false; }

  /** For ConvolutionFilters, this method is used to call the CreateKernel()
   factory method before the process of looping through each pixel of the
   image is started. */
  void SetupFilter() override;

  /** For ConvolutionFilters, this function performs the convolution with
   the kernel centered at (x,y) and returns the resulting color.
   @param[in] buffer The buffer to filter
   @param[in] x X position of the pixel to filter
   @param[in] y Y position of the pixel to filter
   @return The filtered version of the color at pixel (x,y)
   */
  ColorData CalculateFilteredPixel(const PixelBuffer &buffer, int x,
                                   int y) override;

  /** For ConvolutionFilters, this method is used to delete the kernel created
   by SetupFilter(). */
  void CleanupFilter() override;

  /** Factory method: This method defers the job of creating the proper
   convolution kernel to subclasses.  The convolution algorithm is the same
   for all convolution filters, but the specific kernel used changes. */
  virtual FloatMatrix *CreateKernel() = 0;

  /** For some filters it makes sense to convolve R,G,B and A.  For others
   it only makes sense to convolve R,G,B.  In this case, alpha remains
   unchanged. The default implementation returns false. */
  virtual bool convolve_alpha() const;

 private:
  /* Copy assignment/construction is disallowed */
  ConvolutionFilter(const ConvolutionFilter &rhs) = delete;
  ConvolutionFilter &operator=(const ConvolutionFilter &rhs) = delete;

  FloatMatrix *kernel_;
};

} /* namespace image_tools */

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_H_
