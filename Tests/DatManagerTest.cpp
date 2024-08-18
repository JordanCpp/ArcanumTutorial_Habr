#include <Arcanum/Formats/Dat/DatLoader.hpp>
#include <Arcanum/Managers/DatManager.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Arcanum;

int main()
{
	std::vector<char> buffer;
	std::vector<char> result;

	DatList    datList;
	DatReader  datReader;
	DatLoader  datLoader(datReader);
	DatManager datManager(buffer, result, datList);

	POLLUX_TEST(datLoader.Load("TestFiles/arcanum4.dat", datList) == true);
	
	const std::vector<char>& data = datManager.GetFile("dlg/01040Ristezze.dlg");

	POLLUX_TEST(data.size() == 46606);

	return 0;
}
