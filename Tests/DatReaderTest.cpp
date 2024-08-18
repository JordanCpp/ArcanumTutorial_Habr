#include <Arcanum/Formats/Dat/DatReader.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Arcanum;

int main()
{
	DatReader datReader;

	POLLUX_TEST(datReader.Open("TestFiles/arcanum4.dat"));

	return 0;
}
