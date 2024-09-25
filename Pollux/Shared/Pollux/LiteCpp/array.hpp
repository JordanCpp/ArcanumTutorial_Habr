/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef Pollux_LiteCpp_array_hpp
#define Pollux_LiteCpp_array_hpp

#include <Pollux/Common/Assert.hpp>

namespace std
{
	template <typename T, size_t N>
	class array
	{
	public:
		typedef T           value_type;
		typedef value_type* pointer;
		typedef value_type& reference;

		struct iterator 
		{
		private:
			pointer _current;
		public:
			iterator(pointer ptr_ = 0) : _current(ptr_) {}
			reference operator*() { return *_current; }
			pointer operator->() { return _current; }
			pointer operator++() { return ++_current; }
			pointer operator++(T) { return _current++; }
			pointer operator--() { return --_current; }
			bool operator==(const iterator& other) const { return _current == other._current; }
			bool operator!=(const iterator& other) const { return !(*this == other); }
		};

		size_t size() const { return N; }
		iterator begin() { return _content; }
		iterator end() { return _content + N; }
	private:
		T _content[N];
	};
}

#endif 
