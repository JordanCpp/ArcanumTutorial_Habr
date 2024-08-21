#include <Arcanum/Formats/Dat/DatLoader.hpp>
#include <Arcanum/Managers/ResourceManager.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Arcanum;
using namespace Pollux;

int main()
{
	std::vector<unsigned char> buffer;
	std::vector<unsigned char> result;

	DatList            datList;
	DatReader          datReader;
	DatLoader          datLoader(datReader);
	DatManager         datManager(buffer, result, datList);
	Pollux::FileLoader fileLoader(buffer);
	FileManager        fileManager(fileLoader);
	PathManager        pathManager("", "data/", "modules/", "Arcanum/");
	ResourceManager    resourceManager(pathManager, datManager, fileManager);

	datLoader.Load("TestFiles/arcanum4.dat", datList);

	MemoryReader* data = resourceManager.GetData("art/item/", "P_tesla_gun.ART");

	POLLUX_TEST(data                   != NULL);
	POLLUX_TEST(data->Buffer()         != NULL);
	POLLUX_TEST(data->Buffer()->size() == 6195);

	return 0;
}