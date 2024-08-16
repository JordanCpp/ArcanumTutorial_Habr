#include <Arcanum/Formats/Dat/DatReader.hpp>
#include <cassert>
#include <iostream>

using namespace Arcanum;

int main(int argc, char* argv[])
{
	DatReader datReader;

	std::string arg = argv[1];
	std::string name = "/arcanum1.dat";
	
	assert(datReader.Reset(arg + name));

	return 0;
}