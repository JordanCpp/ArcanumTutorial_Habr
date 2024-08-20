#include <Pollux/Loaders/FileLoader.hpp>
#include <Pollux/Readers/MemoryReader.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Pollux;

int main()
{
	std::vector<unsigned char> buffer;

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
