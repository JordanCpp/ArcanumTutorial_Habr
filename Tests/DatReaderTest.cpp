#include <Arcanum/Formats/Dat/DatReader.hpp>
#include <Pollux/Common/TestEqual.hpp>
#include <string.h>

using namespace Arcanum;

int main()
{
	DatReader datReader;

	POLLUX_TEST(datReader.Open("TestFiles/arcanum4.dat"));

	DatItem item;

	size_t count = 0;

	while (datReader.Next(item))
	{
		count++;
	}

	POLLUX_TEST(count == 1037);

	POLLUX_TEST(item.PathSize   == 36);
	POLLUX_TEST(item.Unknown1   == 7850112);
	POLLUX_TEST(item.Type       == 2);
	POLLUX_TEST(item.RealSize   == 89518);
	POLLUX_TEST(item.PackedSize == 79940);
	POLLUX_TEST(item.Offset     == 3599400);

	POLLUX_TEST(strcmp(item.Path, "sound\\StaffOfTeleportation-Cast.wav") == 0);
	POLLUX_TEST(strcmp(item.Archive, "")                                  == 0);

	return 0;
}
