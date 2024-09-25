#include <Pollux/Common/TestEqual.hpp>
#include <Pollux/LiteCpp/LiteCpp.hpp>

void vector_empty_test()
{
	std::vector<int> vec;

	POLLUX_TEST(vec.size()     == 0);
	POLLUX_TEST(vec.capacity() == 0);
	POLLUX_TEST(vec.data()     == nullptr);
}

int main()
{
	vector_empty_test();

	return 0;
}
