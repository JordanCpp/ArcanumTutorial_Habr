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

#include <Pollux/Loaders/FileLoader.hpp>
#include <fstream>
#include <cassert>

using namespace Pollux;

FileLoader::FileLoader(std::pmr::vector<unsigned char>& buffer) :
	_Buffer(buffer)
{
}

bool FileLoader::Reset(const std::string& path)
{
	std::ifstream file(path.c_str(), std::ios::in | std::ios::binary);

	if (!file.is_open() || file.bad())
	{
		return false;
	}

	file.seekg(0, std::ios::end);
	std::streampos fileSize = (size_t)file.tellg();
	file.seekg(0, std::ios::beg);

	_Buffer.resize((size_t)fileSize);

	file.read((char*)&_Buffer[0], fileSize);

	return true;
}

const std::pmr::vector<unsigned char>& FileLoader::Content()
{
	return _Buffer;
}
