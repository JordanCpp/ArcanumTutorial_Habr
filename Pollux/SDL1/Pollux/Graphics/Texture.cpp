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

#include <litecpp/litecpp.hpp>
#include <Pollux/Graphics/Texture.hpp>
#include <Pollux/Common/Assert.hpp>
#include <Pollux/Defines.hpp>

using namespace Pollux;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
const uint32_t R_MASK = 0xff000000;
const uint32_t G_MASK = 0x00ff0000;
const uint32_t B_MASK = 0x0000ff00;
const uint32_t A_MASK = 0x000000ff;
#else
const uint32_t R_MASK = 0x000000ff;
const uint32_t G_MASK = 0x0000ff00;
const uint32_t B_MASK = 0x00ff0000;
const uint32_t A_MASK = 0xff000000;
#endif

const uint8_t bitSize = 8;

Texture::Texture(Canvas& canvas, const Point& size, unsigned char bpp, unsigned char* pixels) :
    _Texture(nullptr),
    _Size(size)
{
    POLLUX_UNUSED(canvas);

    POLLUX_ASSERT(size.x > 0);
    POLLUX_ASSERT(size.y > 0);
    POLLUX_ASSERT(pixels != nullptr);
    
   _Texture = SDL_CreateRGBSurfaceFrom(pixels, size.x, size.y, bitSize * bpp, size.x * bpp, R_MASK, G_MASK, B_MASK, 0);

   if (!_Texture)
       throw std::runtime_error(SDL_GetError());
}

Texture::Texture(Canvas& canvas, const Point& size, unsigned char bpp, unsigned char* pixels, const Color& key) :
    _Texture(nullptr),
    _Size(size)
{
    POLLUX_UNUSED(canvas);

    POLLUX_ASSERT(size.x > 0);
    POLLUX_ASSERT(size.y > 0);
    POLLUX_ASSERT(pixels != nullptr);

    _Texture = SDL_CreateRGBSurfaceFrom(pixels, size.x, size.y, bitSize * bpp, size.x * bpp, R_MASK, G_MASK, B_MASK, 0);

    if (!_Texture)
    {
        throw std::runtime_error(SDL_GetError());
    }

    int colorKey = SDL_SetColorKey(_Texture, SDL_SRCCOLORKEY, SDL_MapRGB(_Texture->format, key.r, key.g, key.b));

    if (colorKey != 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

Texture::~Texture()
{
    SDL_FreeSurface(_Texture);
}

SDL_Surface* Texture::GetTextureImpl()
{
    return _Texture;
}

const Point& Texture::Size() const
{
	return _Size;
}
