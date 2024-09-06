#include <Pollux/Common/TestEqual.hpp>
#include <Pollux/LiteCpp/LiteCpp.hpp>

const size_t bufferMax = 128;
const size_t countMax  = 16;

void VectorTest()
{
	char buffer[bufferMax];

	std::pmr::monotonic_buffer_resource pool(buffer, sizeof(buffer));

	std::pmr::vector<char> vec(&pool);
	POLLUX_TEST(vec.capacity() == 0);
	POLLUX_TEST(vec.size()     == 0);
	POLLUX_TEST(vec.data()     == NULL);

	vec.reserve(countMax);
	POLLUX_TEST(vec.capacity() == countMax);
	POLLUX_TEST(vec.size()     == 0);
	POLLUX_TEST(vec.data()     != NULL);

	vec.resize(countMax);
	POLLUX_TEST(vec.capacity() == countMax);
	POLLUX_TEST(vec.size()     == countMax);
	POLLUX_TEST(vec.data()     != NULL);

	vec.clear();
	POLLUX_TEST(vec.capacity() == countMax);
	POLLUX_TEST(vec.size()     == 0);
	POLLUX_TEST(vec.data()     != NULL);

	for (size_t i = 0; i < countMax; i++)
	{
		vec.push_back((char)i);

		POLLUX_TEST(vec.capacity() == bufferMax);
		POLLUX_TEST(vec.size()     == i + 1);
		POLLUX_TEST(vec.data()     != NULL);
	}
}

void Test1()
{
	char buffer[bufferMax];

	std::pmr::monotonic_buffer_resource pool(buffer, sizeof(buffer));

	for (size_t i = 0; i < bufferMax; i++)
	{
		void* p = pool.allocate(1);

		POLLUX_TEST(p != NULL);
	}
}

void Test2()
{
	char buffer[bufferMax];

	std::pmr::monotonic_buffer_resource pool(buffer, sizeof(buffer));

	std::pmr::vector<char> vec(&pool);
}

int main()
{
	Test1();
	Test2();
	VectorTest();

	return 0;
}
