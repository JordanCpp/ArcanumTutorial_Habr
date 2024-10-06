#include <litecpp/litecpp.hpp>

const size_t bufferMax = 1024 * 100;

int main()
{
	std::vector<char> buffer(bufferMax);

	std::pmr::monotonic_buffer_resource pool(&buffer[0], buffer.size());
	std::pmr::unordered_map<std::string, int> map(45, &pool);
		
	std::pmr::unordered_map<std::string, int>::iterator i = map.find("hello");
	LITECPP_TEST(map.size() == 0);
	LITECPP_TEST(i          == map.end());

	map.emplace("hello", 42);
	LITECPP_TEST(map.size() == 1);
	std::pmr::unordered_map<std::string, int>::iterator j = map.find("hello");
	LITECPP_TEST(j         != map.end());
	LITECPP_TEST(j->first  == "hello");
	LITECPP_TEST(j->second == 42);

	map.emplace("hello", 42);
	LITECPP_TEST(map.size() == 1);
	std::pmr::unordered_map<std::string, int>::iterator k = map.find("hello");
	LITECPP_TEST(k         != map.end());
	LITECPP_TEST(k->first  == "hello");
	LITECPP_TEST(k->second == 42);

	map.emplace("hello2", 47);
	LITECPP_TEST(map.size() == 2);
	std::pmr::unordered_map<std::string, int>::iterator g = map.find("hello2");
	LITECPP_TEST(g         != map.end());
	LITECPP_TEST(g->first  == "hello2");
	LITECPP_TEST(g->second == 47);


	return 0;
}
