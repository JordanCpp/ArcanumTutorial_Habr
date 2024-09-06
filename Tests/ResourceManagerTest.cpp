#include <Arcanum/Formats/Dat/DatLoader.hpp>
#include <Arcanum/Managers/ResourceManager.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Arcanum;
using namespace Pollux;

const size_t bytesMax = 1024 * 1024 * 4;

int main()
{
	std::pmr::monotonic_buffer_resource bufferResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::monotonic_buffer_resource resultResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::vector<unsigned char> buffer(&bufferResource);
	std::pmr::vector<unsigned char> result(&resultResource);

	DatList         datList;
	DatReader       datReader;
	ExtFileManager  extFileManager;
	PathNormalizer  pathNormalizer;
	DatLoader       datLoader(datReader, extFileManager, pathNormalizer);
	DatManager      datManager(buffer, result, datList);
	FileLoader      fileLoader(buffer);
	FileManager     fileManager(fileLoader);
	PathManager     pathManager("", "data/", "modules/", "Arcanum/");
	ResourceManager resourceManager(pathManager, datManager, fileManager);

	datLoader.Load("TestFiles/arcanum4.dat", datList);

	MemoryReader* data = resourceManager.GetData("art/item/", "P_tesla_gun.ART");

	POLLUX_TEST(data                   != NULL);
	POLLUX_TEST(data->Buffer()         != NULL);
	POLLUX_TEST(data->Buffer()->size() == 6195);

	return 0;
}