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

#include <Arcanum/Managers/DatManager.hpp>
#include <stdexcept>
#include <iostream>

using namespace Arcanum;

DatManager::DatManager(std::vector<unsigned char>& buffer, std::vector<unsigned char>& result, DatList& datList) :
	_DatList(datList),
	_Buffer(buffer),
	_Result(result)
{
}

const std::vector<unsigned char>& DatManager::GetFile(const std::string& path)
{
	_Result.clear();

	DatItem* p = _DatList.Get(path);

	if (p != NULL)
	{
		_File.open(p->Archive, std::ios::binary);

		if (_File.is_open())
		{
			_File.seekg(p->Offset, std::ios::beg);

			_Result.resize(p->RealSize);
			_Buffer.resize(p->PackedSize);

			if (p->Type == DatItem::Uncompressed)
			{
				_File.read((char*)&_Result[0], p->RealSize);
			}
			else if (p->Type == DatItem::Compressed)
			{
				_File.read((char*)&_Buffer[0], p->PackedSize);

				if (!_Unpacker.Uncompress((unsigned char*)&_Result[0], p->RealSize, (unsigned char*)&_Buffer[0], p->PackedSize))
				{
					throw std::runtime_error("Can't uncompress file: " + path);
				}
			}

			_File.close();
		}
	}

	return _Result;
}
