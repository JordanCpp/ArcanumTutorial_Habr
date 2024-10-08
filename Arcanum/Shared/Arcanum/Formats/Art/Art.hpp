/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef Arcanum_Formats_Art_Art_hpp
#define Arcanum_Formats_Art_Art_hpp

namespace Arcanum
{
	struct ArtColor
	{
		ArtColor();
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
	};

	struct ArtTable
	{
		enum
		{
			Max = 256
		};

		ArtTable();
		ArtColor colors[Max];
	};

	struct ArtHeader
	{
		enum
		{
			PaletteMax = 4
		};

		unsigned int h0[3];
		ArtColor stupid_color[PaletteMax];
		unsigned int frame_num_low;
		unsigned int frame_num;
		ArtColor palette_data1[8];
		ArtColor palette_data2[8];
		ArtColor palette_data3[8];
	};

	struct ArtFrameHeader
	{
		ArtFrameHeader();
		unsigned int width;
		unsigned int height;
		unsigned int size;
		int c_x;
		int c_y;
		int d_x;
		int d_y;
	};
}

#endif
