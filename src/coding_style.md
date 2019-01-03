Coding Style {#coding_style}
===========

When writing this program, coding style and rules are important. There are few rules applied when implementing this program.

1. Conventions for naming Variables
-----------
- When naming variables, try to make name of the variables short and clear to enhance readability.

- When naming variables, try not to start the variables' name with capital letters.

- When naming Class, try to start with uppercase and mix with lowercase.

- When naming functions, try to make name of the functions clearly so that can describe what the functions actually do.

2. Documenting code
-----------

While writing this project, I followed the Google C++ Style Guide for documenting the code.

- When using the '//' comment, make 2 space apart from the code and write the actual comment 1 space after '//'. For example,

~~~~~~~~~~~~~~~{.cc}
std::string input_file_ = argument[1];  // setting input file
~~~~~~~~~~~~~~~

- Orders of #include should be in constant order by following:

  - Header files (file.h)
  - C++ System files
  - Other libraries' .h files
  - Project .h files

- Header files should start with #ifndef and #define and end with #endif. After using #endif, write a '//' comment that shows Header ended. For example,

~~~~~~~~~~~~~~~{.cc}
#ifndef IMAGETOOLS_TOOL_BLUR_H_
#define IMAGETOOLS_TOOL_BLUR_H_
...
#endif  // IMAGETOOLS_TOOL_BLUR_H_
~~~~~~~~~~~~~~~

- When using namespace, clarify where namespace ended. For example,

~~~~~~~~~~~~~~~{.cc}
namespace image_tools {
...
}  // namespace image_tools
~~~~~~~~~~~~~~~

- When commenting about functions used, try writing in .h file.

- When writing a code or comments, max length of characters used in a line should be less than 80.

- Comments should be at the paragraph of code level. For example,

~~~~~~~~~~~~~~~{.cc}
// Radius should be > 1 in order to blur
explicit ConvolutionFilterBlur(float radius);
~~~~~~~~~~~~~~~

- When explaining about functions or some commands, do not just copy what it is. In other words, if the command is obvious that everyone can understand what the commands do without comment, comment is not necessary. Focus more on Why but not How.

- There should not be any blank lines or spaces after the code or comment.

- Use proper Indentations for better readability. For example,

~~~~~~~~~~~~~~~{.cc}
FloatMatrix* ConvolutionFilterBlur::CreateKernel() {
  FloatMatrix* kernel =
      new FloatMatrix(round(radius_ * 2.0) + 1, round(radius_ * 2.0) + 1);

  for (int j = 0; j < kernel->height(); j++) {
    for (int i = 0; i < kernel->width(); i++) {
      int x = i - kernel->width() / 2;
      int y = j - kernel->height() / 2;
      float dist = sqrt(x * x + y * y);
      float intensity = ImageToolsMath::Gaussian(dist, radius_);
      kernel->set_value(i, j, intensity);
    }
  }
  kernel->Normalize();

  return kernel;
}
~~~~~~~~~~~~~~~

There are some more rules for the Google C++ Style Guide. More information can be found at [GoogleStyleGuide]( https://google.github.io/styleguide/cppguide.html#The__define_Guard  "Google_Style_Guide")
