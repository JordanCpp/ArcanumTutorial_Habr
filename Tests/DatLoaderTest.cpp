#include <Arcanum/Formats/Dat/DatLoader.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Arcanum;

int main()
{
	DatList        datList;
	DatReader      datReader;
	ExtFileManager extFileManager;
	PathNormalizer pathNormalizer;
	DatLoader      datLoader(datReader, extFileManager, pathNormalizer);

	POLLUX_TEST(datLoader.Load("TestFiles/arcanum4.dat", datList) == true);
	POLLUX_TEST(datList.Count()                                   == 1037);

	DatItem* item = datList.Get("dlg/01040Ristezze.dlg");

	POLLUX_TEST(item             != NULL);
	POLLUX_TEST(item->PathSize   == 22);
	POLLUX_TEST(item->Unknown1   == 7803936);
	POLLUX_TEST(item->Type       == 2);
	POLLUX_TEST(item->RealSize   == 46606);
	POLLUX_TEST(item->PackedSize == 12771);
	POLLUX_TEST(item->Offset     == 1212430);

	return 0;
}
