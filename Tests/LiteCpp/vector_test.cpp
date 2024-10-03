#include <Pollux/Common/TestEqual.hpp>
#include <litecpp/litecpp.hpp>

std::vector<char> buffer(1024 * 16);
std::pmr::monotonic_buffer_resource pool(buffer.data(), buffer.capacity());

void vector_empty_test()
{
	std::pmr::vector<std::pmr::string> vec(&pool);

	POLLUX_TEST(vec.capacity() == 0);
	POLLUX_TEST(vec.size()     == 0);
	POLLUX_TEST(vec.data()     == nullptr);
}

void vector_reserve_test()
{
	std::pmr::vector<std::pmr::string> vec(&pool);

	vec.reserve(10);

	POLLUX_TEST(vec.capacity() >= 10);
	POLLUX_TEST(vec.size()     == 0);
	POLLUX_TEST(vec.data()     != nullptr);

	vec.push_back("01");
	POLLUX_TEST(vec.capacity() >= 10);
	POLLUX_TEST(vec.size()     == 1);
	POLLUX_TEST(vec.data()     != nullptr);

	vec.push_back("02");
	POLLUX_TEST(vec.capacity() >= 10);
	POLLUX_TEST(vec.size()     == 2);
	POLLUX_TEST(vec.data()     != nullptr);

	vec.push_back("03");
	POLLUX_TEST(vec.capacity() >= 10);
	POLLUX_TEST(vec.size()     == 3);
	POLLUX_TEST(vec.data()     != nullptr);
}

int main()
{
	vector_empty_test();
	vector_reserve_test();

	return 0;
}
