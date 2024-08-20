#include <Arcanum/Formats/Art/ArtReader.hpp>
#include <Arcanum/Managers/FileManager.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Arcanum;
using namespace Pollux;

int main()
{
	std::vector<unsigned char> buffer;

	FileLoader fileLoader(buffer);
	fileLoader.Reset("TestFiles/data/art/item/P_tesla_gun.ART");
	
	MemoryReader memoryReader;
	memoryReader.Reset(&fileLoader.Content());

	ArtReader artReader;
	artReader.Reset(&memoryReader);

	std::vector<unsigned char> data;

	artReader.Frame(0, data);

	POLLUX_TEST(data.size() == 5011);

	return 0;
}
