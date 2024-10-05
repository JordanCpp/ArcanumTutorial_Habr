#include <Pollux/Containers/HashMap.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Pollux;

const size_t bytesMax = 4096;

int main()
{
	char buffer[bytesMax];

	std::pmr::monotonic_buffer_resource pool(buffer, sizeof(buffer));

	const char key[] = "limpopo!";

	HashMap<int> map(&pool, 128);

	POLLUX_TEST(map.Get(key) == nullptr);

	map.Set(key, 42);

	POLLUX_TEST(map.Get(key) != nullptr);

	return 0;
}
