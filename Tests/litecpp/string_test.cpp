#include <Pollux/Common/TestEqual.hpp>
#include <litecpp/litecpp.hpp>

std::vector<char> buffer(1024 * 16);
std::pmr::monotonic_buffer_resource pool(buffer.data(), buffer.capacity());

void string_constructor_chars_test()
{
	std::pmr::string str("hello world!", &pool);
	POLLUX_TEST(str.capacity()                      >= 13);
	POLLUX_TEST(str.size()                          >= 12);
	POLLUX_TEST(strcmp(str.c_str(), "hello world!") == 0);

	str.push_back('G');
	POLLUX_TEST(str.capacity()                       >= 13);
	POLLUX_TEST(str.size()                           >= 12);
	POLLUX_TEST(strcmp(str.c_str(), "hello world!G") == 0);
}

void string_assign_chars_test()
{
	std::pmr::string str = "hello world!";
	POLLUX_TEST(str.capacity()                      >= 13);
	POLLUX_TEST(str.size()                          >= 12);
	POLLUX_TEST(strcmp(str.c_str(), "hello world!") == 0);

	str = "lolipop!";
	POLLUX_TEST(str.capacity()                  >= 13);
	POLLUX_TEST(str.size()                      >= 8);
	POLLUX_TEST(strcmp(str.c_str(), "lolipop!") == 0);
}

void string_assign_string_test()
{
	std::pmr::string str1 = "hello";

	std::pmr::string str2 = str1;
	POLLUX_TEST(str2.capacity()               >= 6);
	POLLUX_TEST(str2.size()                   >= 5);
	POLLUX_TEST(strcmp(str2.c_str(), "hello") == 0);
}

void string_push_back_test()
{
	std::pmr::string str;

	str.push_back('h');
	POLLUX_TEST(str.capacity()           >= 3);
	POLLUX_TEST(str.size()               == 1);
	POLLUX_TEST(strcmp(str.c_str(), "h") == 0);

	str.push_back('e');
	POLLUX_TEST(str.capacity()            >= 3);
	POLLUX_TEST(str.size()                == 2);
	POLLUX_TEST(strcmp(str.c_str(), "he") == 0);

	str.push_back('l');
	POLLUX_TEST(str.capacity()             >= 7);
	POLLUX_TEST(str.size()                 == 3);
	POLLUX_TEST(strcmp(str.c_str(), "hel") == 0);

	str.push_back('l');
	POLLUX_TEST(str.capacity()              >= 7);
	POLLUX_TEST(str.size()                  == 4);
	POLLUX_TEST(strcmp(str.c_str(), "hell") == 0);

	str.push_back('o');
	POLLUX_TEST(str.capacity()               >= 7);
	POLLUX_TEST(str.size()                   == 5);
	POLLUX_TEST(strcmp(str.c_str(), "hello") == 0);
}

void string_plus_assign_test()
{
	std::pmr::string str1 = "hello";
	std::pmr::string str2 = " world!";

	str1 += str2;

	POLLUX_TEST(strcmp(str1.c_str(), "hello world!") == 0);
}

int main()
{
	string_constructor_chars_test();
	string_assign_chars_test();
	string_assign_string_test();
	string_push_back_test();
	string_plus_assign_test();

	return 0;
}
