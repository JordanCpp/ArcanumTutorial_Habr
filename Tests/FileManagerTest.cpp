#include <Arcanum/Managers/FileManager.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Arcanum;
using namespace Pollux;

const size_t bytesMax = 1024 * 1024 * 4;

int main()
{
	std::pmr::monotonic_buffer_resource bufferResource(new unsigned char[bytesMax], bytesMax);
	std::pmr::vector<unsigned char> buffer(&bufferResource);

	FileLoader  fileLoader(buffer);
	FileManager datManager(fileLoader);

	POLLUX_TEST(datManager.GetFile("TestFiles/arcanum4.dat").size() == 3733777);
	
	return 0;
}
