#include <Arcanum/Formats/Dat/DatList.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Arcanum;

int main()
{
	const std::string path    = "dialog/game.txt";
	const std::string archive = "arcanum.dat";

	DatItem item;

	item.PathSize   = 1;
	item.Unknown1   = 2;
	item.Type       = 3;
	item.RealSize   = 4;
	item.PackedSize = 5;
	item.Offset     = 6;

	strcpy(item.Path, path.c_str());

	DatList list;

	list.Add(path, item, archive);

	DatItem* p = list.Get(path);

	POLLUX_TEST(p             != NULL);
	POLLUX_TEST(p->PathSize   == 1);
	POLLUX_TEST(p->Unknown1   == 2);
	POLLUX_TEST(p->Type       == 3);
	POLLUX_TEST(p->RealSize   == 4);
	POLLUX_TEST(p->PackedSize == 5);
	POLLUX_TEST(p->Offset     == 6);

	return 0;
}
