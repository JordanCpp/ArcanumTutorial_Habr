#include <Arcanum/Formats/Dat/DatLoader.hpp>
#include <Arcanum/Managers/DatManager.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Arcanum;

const size_t bytesMax = 1024 * 1024 * 4;

int main()
{
	std::pmr::monotonic_buffer_resource bufferResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::monotonic_buffer_resource resultResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::monotonic_buffer_resource datListResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::vector<unsigned char> buffer(&bufferResource);
	std::pmr::vector<unsigned char> result(&resultResource);

	DatList        datList(&datListResource);
	DatReader      datReader;
	ExtFileManager extFileManager;
	PathNormalizer pathNormalizer;
	DatLoader      datLoader(datReader, extFileManager, pathNormalizer);
	DatManager     datManager(buffer, result, datList);

	POLLUX_TEST(datLoader.Load("TestFiles/arcanum4.dat", datList) == true);
	
	const std::pmr::vector<unsigned char>& data = datManager.GetFile("art/item/g_helmet.ART");

	POLLUX_TEST(data.size() == 1508);

	return 0;
}
