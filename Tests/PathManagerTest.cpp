#include <Arcanum/Managers/PathManager.hpp>
#include <Pollux/TestEqual.hpp>

using namespace Arcanum;

int main()
{
	PathManager pathManager("C:/Games/", "data/", "modules/", "Arcanum");

	POLLUX_TEST(pathManager.GetFileFromDir("art/item/", "P_tesla_gun.ART")       == "C:/Games/data/art/item/P_tesla_gun.ART");
	POLLUX_TEST(pathManager.GetFileFromDat("art/item/", "P_tesla_gun.ART")       == "art/item/P_tesla_gun.ART");
	POLLUX_TEST(pathManager.GetFileFromModuleDir("art/item/", "P_tesla_gun.ART") == "C:/Games/data/modules/Arcanum/art/item/P_tesla_gun.ART");

	POLLUX_TEST(pathManager.GetDat("arcanum1.dat")    == "C:/Games/arcanum1.dat");
	POLLUX_TEST(pathManager.GetModules("arcanum.dat") == "C:/Games/modules/arcanum.dat");
	POLLUX_TEST(pathManager.GetModule()               == "Arcanum");

	return 0;
}