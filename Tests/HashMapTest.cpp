#include <Pollux/Containers/HashMap.hpp>
#include <Pollux/Allocators/LinearAllocator.hpp>
#include <Pollux/Common/TestEqual.hpp>

using namespace Pollux;

int main()
{
	const char key[] = "limpopo!";

	LinearAllocator alloc(LinearAllocator::Mb * 1);

	HashMap<int> map(&alloc, 1024);

	POLLUX_TEST(map.Get(key) == NULL);

	map.Set(key, 42);

	POLLUX_TEST(map.Get(key) != NULL);

	return 0;
}
