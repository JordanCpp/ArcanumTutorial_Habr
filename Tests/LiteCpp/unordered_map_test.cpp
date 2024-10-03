#include <Pollux/Common/TestEqual.hpp>
#include <litecpp/litecpp.hpp>

const size_t bufferMax = 1024 * 100;

int main()
{
	std::vector<char> buffer(bufferMax);

	std::pmr::monotonic_buffer_resource pool(&buffer[0], buffer.size());
	std::pmr::unordered_map<std::string, int> map(45, &pool);
		
	std::pmr::unordered_map<std::string, int>::iterator i = map.find("hello");
	POLLUX_TEST(i == map.end());

	map.emplace("hello", 42);
	std::pmr::unordered_map<std::string, int>::iterator j = map.find("hello");
	POLLUX_TEST(j         != map.end());
	POLLUX_TEST(j->first  == "hello");
	POLLUX_TEST(j->second == 42);

	return 0;
}
