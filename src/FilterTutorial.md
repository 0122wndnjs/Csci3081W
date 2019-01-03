Filters Tutorial {#tutorials}
===========

This tutorial is to show how to add new filters and apply to FlashPhoto.

1. Overview
-----------

In the FlashPhoto program, there are two kinds of filters: normal filters and convolution filters. Normal filters are some of simple filters such as threshold, saturate, channel and quantize. In case of convolution filters, it utilize the filter.cc and using kernel as well. Blur, motion blur, sharpen and edge detect filters are examples of convolution filters. Since convolution filters still use the normal filter, we will discuss the steps for implementing normal filters.

2. Creating Files
-----------

The first task for adding a new filter is to create the new filter files.

> new_filter.cc

> new_filter.h

new_filter.cc and new_filter.h works like a pair and these files should be located in imagetools.

> /PROJ/imagetools

3. Implementing Filters
-----------

All filters are created in similar structure.
The below code describes the structure of the Quantize Filter that is already implemented in this program.

~~~~~~~~~~~~~~~{.cc}
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

}
~~~~~~~~~~~~~~~

Important part is the CaclulateFilteredPixel. It should be implemented by following the proper algorithm and some of the files that are connected with this program.

For the header files, it shows what functions are used in .cc file and it should match with .cc file as well. Also, some private variables can be declared if needed.

~~~~~~~~~~~~~~~{.cc}
#ifndef IMAGETOOLS_FILTER_QUANTIZE_H_
#define IMAGETOOLS_FILTER_QUANTIZE_H_

#include <string>
#include "imagetools/filter.h"

namespace image_tools {

class FilterQuantize : public Filter {
 public:
  explicit FilterQuantize(int bins);
  FilterQuantize();

  virtual ~FilterQuantize();

  int num_bins();
  void set_num_bins(int n);

  ColorData CalculateFilteredPixel(const PixelBuffer &buffer, int x,
                                           int y) override;

  static const std::string name() { return "Quantize"; }

 private:
  int bins_;
};

}

#endif
~~~~~~~~~~~~~~~

4. Applying Filters
-----------

Implementing new_filter.cc and new_filter.h files does not mean the filter can be applied right away. The new filter file has to be connected with the App file so that it can actually applied when the application is running.

In the image_editor.cc file, make a function that can apply the filters that you implemented. For example,

~~~~~~~~~~~~~~~{.cc}
void ImageEditor::ApplyQuantizeFilter(int num_bins) {
  SaveStateForPossibleUndo();
  FilterQuantize newFilterQuantize(num_bins);
  newFilterQuantize.ApplyToBuffer(pixel_buffer());
  (void)num_bins;
}
~~~~~~~~~~~~~~~

After this, by including the new_filter.h files and adding private variables that are needed to apply the filter in image_editor.h file, the filter is ready to be applied on the program.
