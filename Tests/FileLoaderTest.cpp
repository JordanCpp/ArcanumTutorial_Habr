#include <Pollux/Loaders/FileLoader.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Pollux;

const size_t bytesMax = 1024 * 1024 * 4;

int main()
{
	std::pmr::monotonic_buffer_resource bufferResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::vector<unsigned char> buffer(&bufferResource);

	FileLoader fileLoader(buffer);

	POLLUX_TEST(fileLoader.Reset("TestFiles/arcanum4.dat") == true);
	POLLUX_TEST(fileLoader.Content().size()                == 3733777);
	POLLUX_TEST(fileLoader.Content().capacity()            == 5242880);

	return 0;
}
