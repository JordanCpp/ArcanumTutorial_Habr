#include <Pollux/Loaders/FileLoader.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Pollux;

int main()
{
	std::vector<char> buffer(1024 * 1024 * 5);

	FileLoader fileLoader(buffer);

	POLLUX_TEST(fileLoader.Reset("TestFiles/arcanum4.dat") == true);
	POLLUX_TEST(fileLoader.Content().size()                == 3733777);
	POLLUX_TEST(fileLoader.Content().capacity()            == 5242880);

	return 0;
}
