#include <Arcanum/Formats/Dat/DatLoader.hpp>
#include <Arcanum/Managers/ResourceManager.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Arcanum;

int main()
{
	std::vector<char> buffer;
	std::vector<char> result;

	DatList            datList;
	DatReader          datReader;
	DatLoader          datLoader(datReader);
	DatManager         datManager(buffer, result, datList);
	Pollux::FileLoader fileLoader(buffer);
	FileManager        fileManager(fileLoader);
	PathManager        pathManager("", "data/", "Arcanum/");
	ResourceManager    resourceManager(pathManager, datManager, fileManager);

	datLoader.Load("TestFiles/arcanum4.dat", datList);

	const std::vector<char>& data = resourceManager.GetFile("art/item/", "P_tesla_gun.ART");

	POLLUX_TEST(data.size() == 6195);

	return 0;
}