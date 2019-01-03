Design Documents  {#design_document}
===========

1. Overview
-----------

The structure of the program is quite simple and easy to understand. First, there are 2 main programs, FlashPhoto and MIA. Both programs use tools and filters but MIA has fewer tools and filters than FlashPhoto. This is because MIA is for medical imaging purpose and only needs some tools and filters that fits on the purpose. As can be seen below, FlashPhotoApp and MiaApp is operated by GraphicsApp that control all graphics.  


![Overall UML](/home/kimx4342/csci3081W/3081_F18/repo-kimx4342/PROJ/web/Image/Overall.png "overall")

2. Image Tools
-----------

###Filters###

There are 8 filters implemented. 4 filters are basic filter that uses filter file and other 4 filters are more complex filters that uses the convolution filter file. Convolution filter also utilize the regular filter file.


![Filter UML](../Image/classimage__tools_1_1Filter__inherit__graph.png "filters")


###Tools###

There are 8 tools(brushes) implemented. All 8 tools are applied by using tool file. The relationship diagram is shown below. As can be seen, all 8 tools are at the same level and utilized bt the image_tools::Tool. Also, the Tool class get the mask_, paint_color_ and buffer_ information from the FloatMatrix, ColorData and PixelBuffer respectively.

![Tools UML](../Image/classimage__tools_1_1Tool__inherit__graph.png "Tools")

![Tools UML2](../Image/classimage__tools_1_1Tool__coll__graph.png "Tools2")
