#include <Pollux/TestEqual.hpp>
#include <Pollux/Common/DirReader.hpp>
#include <vector>
#include <algorithm>

using namespace Pollux;

int main()
{
	DirReader dirReader;

	std::vector<std::string> list;

	if (dirReader.Reset("TestFiles/" + dirReader.All()))
	{
		DirItem dirItem;

		while (dirReader.Next(dirItem))
		{
			list.push_back(dirItem.Path);
		}
	}

	std::vector<std::string>::iterator i = std::find(list.begin(), list.end(), "data");
	POLLUX_TEST(i != list.end());

	std::vector<std::string>::iterator j = std::find(list.begin(), list.end(), "arcanum4.dat");
	POLLUX_TEST(j != list.end());

	return 0;
}
