#include <litecpp/litecpp.hpp>

std::vector<char> buffer(1024 * 16);
std::pmr::monotonic_buffer_resource pool(buffer.data(), buffer.capacity());

void vector_empty_test()
{
	std::pmr::vector<std::pmr::string> vec(&pool);

	LITECPP_TEST(vec.capacity() == 0);
	LITECPP_TEST(vec.size()     == 0);
	LITECPP_TEST(vec.data()     == nullptr);
}

void vector_reserve_test()
{
	std::pmr::vector<std::pmr::string> vec(&pool);

	vec.reserve(10);

	LITECPP_TEST(vec.capacity() >= 10);
	LITECPP_TEST(vec.size()     == 0);
	LITECPP_TEST(vec.data()     != nullptr);

	vec.push_back("01");
	LITECPP_TEST(vec.capacity() >= 10);
	LITECPP_TEST(vec.size()     == 1);
	LITECPP_TEST(vec.data()     != nullptr);

	vec.push_back("02");
	LITECPP_TEST(vec.capacity() >= 10);
	LITECPP_TEST(vec.size()     == 2);
	LITECPP_TEST(vec.data()     != nullptr);

	vec.push_back("03");
	LITECPP_TEST(vec.capacity() >= 10);
	LITECPP_TEST(vec.size()     == 3);
	LITECPP_TEST(vec.data()     != nullptr);
}

int main()
{
	vector_empty_test();
	vector_reserve_test();

	return 0;
}
