#ifndef Aracnum_Common_PathNormalizer_hpp
#define Aracnum_Common_PathNormalizer_hpp

#include <string>

namespace Arcanum
{
	class PathNormalizer
	{
	public:
		void Normalize(char* path);
		void Normalize(std::string& path);
	private:
	};
}

#endif
