/**
Copyright (c) 2018 Joowon Kim, University of Minnesota.
	...
*/

#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_

#include "mia/image_editor_commands.h"
#include "imagetools/image_editor.h"
#include "imagetools/color_data.h"

namespace image_tools {
/** @brief CommandLineProcessor class is for utilizing the command line mode
for the Mia application. This is designed to operate simply by using commands
on the terminal. */
class CommandLineProcessor {
 public:
  CommandLineProcessor();
  virtual ~CommandLineProcessor();

  /** This function detects the .png image file and if it is correct input,
  than apply the filter with certain amount that user gives. Also, when some
  inputs are wrong or user type -h, it prints out the help message. */
  void ProcessCommandLine(int argc, char* argv[]);

  /** This function is to print out the help message when user types the wrong
  input or type the -h command on the terminal.  */
  void PrintHelpMessage();

 private:
  ImageEditorCommands* image_editor_command_;
  ImageEditor* image_editor_;
};
}  // namespace image_tools

#endif  // MIA_COMMAND_LINE_PROCESSOR_H_
