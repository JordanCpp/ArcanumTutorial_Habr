#include <Arcanum/Managers/PathManager.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Arcanum;

int main()
{
	PathManager pathManager("C:/Games/", "data/", "Arcanum/");

	POLLUX_TEST(pathManager.GetFileFromDir("art/item/", "P_tesla_gun.ART") == "C:/Games/data/art/item/P_tesla_gun.ART");
	POLLUX_TEST(pathManager.GetFileFromDat("art/item/", "P_tesla_gun.ART") == "art/item/P_tesla_gun.ART");
	POLLUX_TEST(pathManager.GetDat("arcanum1.dat")                         == "C:/Games/arcanum1.dat");

	return 0;
}