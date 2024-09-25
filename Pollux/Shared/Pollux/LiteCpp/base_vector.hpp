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

#ifndef Pollux_LiteCpp_base_vector_hpp
#define Pollux_LiteCpp_base_vector_hpp

#include <Pollux/LiteCpp/memory_resource.hpp>
#include <Pollux/Common/Assert.hpp>

namespace std
{
	namespace pmr
	{
		template <typename T>
		class vector
		{
		public:
			vector(memory_resource* source) :
				_capacity(0),
				_position(0),
				_content(NULL),
				_memory(source)
			{
			}

			vector() :
				_capacity(0),
				_position(0),
				_content(NULL),
				_memory(NULL)
			{
			}

			T* allocate(size_t count)
			{
				if (_memory)
				{
					void* ptr = _memory->allocate(count * sizeof(T));

					return new (ptr) T[count];
				}
				else
				{
					return new T[count];
				}
			}

			void deallocate(T* ptr)
			{
				if (_content != NULL)
				{
					if (_memory)
					{
						_memory->deallocate(_content, _capacity * sizeof(T));
					}
					else
					{
						delete[] _content;
					}
				}
			}

			~vector()
			{
				deallocate(_content);
			}

			size_t capacity() const
			{
				return _capacity;
			}

			size_t size() const
			{
				return _position;
			}

			const T* data() const
			{
				return _content;
			}

			T* data()
			{
				return _content;
			}

			void reserve(size_t count)
			{
				if (count > _capacity)
				{
					T* p = allocate(count);

					for (size_t i = 0; i < _position; i++)
					{
						p[i] = _content[i];
					}

					if (_content != NULL)
					{
						_memory->deallocate(_content, _capacity * sizeof(T));
					}

					_content  = p;
					_capacity = count;
				}
			}

			void resize(size_t count)
			{
				if (_capacity < count)
				{
					reserve(count);
				}

				_position = count;
			}

			void clear()
			{
				_position = 0;
			}

			void push_back(const T& element)
			{
				if (_capacity == 0)
				{
					reserve(2);
				}
				else if (_position + 1 >= _capacity)
				{
					reserve(_capacity * 2);
				}

				_content[_position] = element;

				_position++;
			}

			const T& at(size_t index) const
			{
				POLLUX_ASSERT(index <= _position);

				return _content[index];
			}

			const T& operator[] (size_t index) const
			{ 
				POLLUX_ASSERT(index <= _position);

				return _content[index];
			}

			T& operator[] (size_t index)
			{
				POLLUX_ASSERT(index <= _position);

				return _content[index];
			}

		private:
			size_t           _capacity;
			size_t           _position;
			T*               _content;
			memory_resource* _memory;
		};
	}
}

#endif 
