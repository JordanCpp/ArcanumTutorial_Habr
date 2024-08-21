#include <Pollux/TestEqual.hpp>
#include <Pollux/Common/DirReader.hpp>

using namespace Pollux;

int main()
{
	DirReader dirReader;

	if (dirReader.Reset("TestFiles/" + dirReader.All()))
	{
		DirItem dirItem;

		while (dirReader.Next(dirItem))
		{
		}
	}

	return 0;
}
