Getting Started with MIA {#mia}
===========

MIA, Medical Image Analysis program looks quite similar with FlashPhoto program. The big difference with Flashphoto program is that they have two modes: Graphical mode and Command Line mode.

1. Graphical Mode
-----------

![Brain CT Scan](../Image/brain_images.png "Brain")

Graphical mode is opening png image to the canvas. When the MIA program is open, you can find out that the program looks similar with the FlashPhoto program but has less tools and filters. By simply clicking open at the control panel, the image can be loaded on the canvas. Now, the canvas is filled and resized with the actual size of image. When the image is loaded, you can select any tools or filters that you want to apply on the image. If all tools/filters that you want to apply is done, you can save the new image by simply clicking the save button on the control panel.

2. Command Line Mode
-----------

Command Line mode is a faster way of applying filters to the image. You do not even nede to open the MIA program but you can simply type some commands on terminal and they will automatically apply filters and save.

The format of the command is:

> ./mia [input file] -[name of filter] [strength] [output file]

For example,

> ./mia input_file.png -blur 4 output_file.png

This example command will open the input file, apply the blur filter with the strength of 4 and save the filtered image as output_file.png. So opening the program is not needed and by simply tpying this command, MIA program can be utilized.

###Original Image###

![brain_mia](../Image/brain_ct.png "Brain")

###Output Image###

![output](../Image/output_file.png "output")

The list of filter names and how to apply filters can be seen by using the following commands on the terminal.

> ./mia -h

![help](../Image/help_message.png "help")
