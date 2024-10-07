#include <Pollux/Loaders/FileLoader.hpp>
#include <Pollux/Readers/MemoryReader.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Pollux;

const size_t bytesMax = 1024 * 1024 * 4;

int main()
{
	std::pmr::monotonic_buffer_resource bufferResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::vector<unsigned char> buffer(&bufferResource);

	FileLoader fileLoader(buffer);
	fileLoader.Reset("TestFiles/data/art/item/P_tesla_gun.ART");
	
	MemoryReader memoryReader;
	memoryReader.Reset(&fileLoader.Content());

	POLLUX_TEST(memoryReader.Buffer()         == &fileLoader.Content());
	POLLUX_TEST(memoryReader.Buffer()->size() == 6195);

	for (size_t i = 0; i < memoryReader.Buffer()->size(); i++)
	{
		char ch = 0;

		memoryReader.Read(&ch, 1);
	}

	return 0;
}
