#include <Arcanum/Formats/Dat/DatLoader.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Arcanum;

int main()
{
	const size_t bufferMax = 1024 * 100;

	std::vector<char> buffer(bufferMax);
	std::pmr::monotonic_buffer_resource pool(&buffer[0], buffer.size());

	DatList        datList(&pool);
	DatReader      datReader;
	ExtFileManager extFileManager;
	PathNormalizer pathNormalizer;
	DatLoader      datLoader(datReader, extFileManager, pathNormalizer);

	POLLUX_TEST(datLoader.Load("TestFiles/arcanum4.dat", datList) == true);
	POLLUX_TEST(datList.Count()                                   == 80);

	DatItem* item = datList.Get("art/item/g_helmet.ART");

	POLLUX_TEST(item             != NULL);
	POLLUX_TEST(item->PathSize   == 22);
	POLLUX_TEST(item->Unknown1   == 7798800);
	POLLUX_TEST(item->Type       == 2);
	POLLUX_TEST(item->RealSize   == 1508);
	POLLUX_TEST(item->PackedSize == 994);
	POLLUX_TEST(item->Offset     == 967676);

	return 0;
}
