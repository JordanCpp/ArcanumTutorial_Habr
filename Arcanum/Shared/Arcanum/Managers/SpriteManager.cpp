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

#include <Arcanum/Managers/SpriteManager.hpp>

using namespace Arcanum;
using namespace Pollux;

SpriteManager::SpriteManager(std::pmr::memory_resource* resource, Pollux::Canvas& canvas, ResourceManager& resourceManager, ArtReader& artReader, std::vector<unsigned char>& artBuffer, std::vector<unsigned char>& rgbBuffer) :
	_Resource(resource),
	_Canvas(canvas),
	_ResourceManager(resourceManager),
	_ArtReader(artReader),
	_ArtBuffer(artBuffer),
	_RgbBuffer(rgbBuffer),
	_Sprites(_Resource)
{
}

Sprite* SpriteManager::GetSprite(const std::string& dir, const std::string& file)
{
	_Path = dir + file;

	container::iterator i = _Sprites.find(_Path);

	if (i == _Sprites.end())
	{
		MemoryReader* reader = _ResourceManager.GetData(dir, file);

		_ArtReader.Reset(reader);

		Sprite* result = NULL;

		if (_ArtReader.Frames() > 0)
		{
			_ArtReader.Frame(0, _ArtBuffer, _RgbBuffer);

			int w = _ArtReader.Width(0);
			int h = _ArtReader.Height(0);

			Texture* texture = new (_Resource->allocate(sizeof(Texture))) Texture(_Canvas, Point(w, h), 4, &_RgbBuffer[0]);
			Image* image = new (_Resource->allocate(sizeof(Image))) Image(texture, Point(0, 0), Point(0, 0));

			_Images.clear();

			_Images.push_back(image);
			result = new (_Resource->allocate(sizeof(Sprite))) Sprite(_Images);

			_Sprites.emplace(_Path, result);
		}

		return result;
	}
	else
	{
		return i->second;
	}
}
