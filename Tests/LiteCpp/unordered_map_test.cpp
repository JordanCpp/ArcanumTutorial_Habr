#include <litecpp/litecpp.hpp>

const size_t bufferMax = 1024 * 100;

int main()
{
	std::vector<char> buffer(bufferMax);

	std::pmr::monotonic_buffer_resource pool(&buffer[0], buffer.size());
	std::pmr::unordered_map<std::string, int> map(45, &pool);
		
	std::pmr::unordered_map<std::string, int>::iterator i = map.find("hello");
	LITECPP_TEST(i == map.end());

	map.emplace("hello", 42);
	std::pmr::unordered_map<std::string, int>::iterator j = map.find("hello");
	LITECPP_TEST(j         != map.end());
	LITECPP_TEST(j->first  == "hello");
	LITECPP_TEST(j->second == 42);

	return 0;
}
