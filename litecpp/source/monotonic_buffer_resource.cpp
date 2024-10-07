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

#include <litecpp/defines.hpp>
#include <litecpp/monotonic_buffer_resource.hpp>
#include <assert.h>

using namespace std;
using namespace pmr;

monotonic_buffer_resource::monotonic_buffer_resource(void* buffer, size_t buffer_size) :
	_capacity(buffer_size),
	_position(0),
	_content((unsigned char*)buffer),
	_upstream(nullptr)
{
}

monotonic_buffer_resource::monotonic_buffer_resource(size_t initial_size, memory_resource* upstream) :
	_capacity(initial_size),
	_position(0),
	_content(nullptr),
	_upstream(upstream)
{
	_content = (unsigned char*)_upstream->allocate(_capacity);
}

monotonic_buffer_resource::~monotonic_buffer_resource()
{
	release();
}

void* monotonic_buffer_resource::allocate(size_t bytes)
{
	assert(bytes > 0);
	assert(_position + bytes <= _capacity);

	void* result = _content + _position;

	_position += bytes;

	return result;
}

void monotonic_buffer_resource::deallocate(void* p, size_t bytes)
{
	assert(p != nullptr);
	assert(bytes > 0);
}

void monotonic_buffer_resource::release()
{
	_position = 0;
}
