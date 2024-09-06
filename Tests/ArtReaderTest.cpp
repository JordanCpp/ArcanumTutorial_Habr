#include <Arcanum/Formats/Art/ArtReader.hpp>
#include <Arcanum/Managers/FileManager.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Arcanum;
using namespace Pollux;

const size_t bytesMax = 1024 * 1024 * 4;

int main()
{
	std::pmr::monotonic_buffer_resource bufferResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::vector<unsigned char> buffer(&bufferResource);

	FileLoader fileLoader(buffer);
	fileLoader.Reset("TestFiles/data/art/scenery/engine.ART");
	
	MemoryReader memoryReader;
	memoryReader.Reset(&fileLoader.Content());

	ArtReader artReader;
	artReader.Reset(&memoryReader);

	POLLUX_TEST(artReader.Frames() == 10);

	std::vector<unsigned char> artBuffer;
	std::vector<unsigned char> rgbBuffer;

	artReader.Frame(0, artBuffer, rgbBuffer);
	POLLUX_TEST(artBuffer.size() == 35651);
	POLLUX_TEST(rgbBuffer.size() == 223344);

	return 0;
}
