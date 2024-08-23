#include <Arcanum/Managers/FileManager.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Arcanum;
using namespace Pollux;

int main()
{
	std::vector<unsigned char> buffer;

	FileLoader  fileLoader(buffer);
	FileManager datManager(fileLoader);

	POLLUX_TEST(datManager.GetFile("TestFiles/arcanum4.dat").size() == 3733777);
	
	return 0;
}
