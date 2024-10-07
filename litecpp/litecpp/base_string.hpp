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

#ifndef litecpp_base_string_hpp
#define litecpp_base_string_hpp

#include <new>
#include <string.h>
#include <assert.h>
#include <litecpp/memory_resource.hpp>

namespace litecpp
{
		template <typename T>
		class base_string
		{
		private:
			size_t                     _capacity;
			size_t                     _position;
			T*                         _content;
			std::pmr::memory_resource* _resource;

		public:
			base_string() :
				_capacity(0),
				_position(0),
				_content(nullptr),
				_resource(nullptr)
			{
			}

			base_string(const T* source) :
				_capacity(0),
				_position(0),
				_content(nullptr),
				_resource(nullptr)
			{
				size_t length = strlen(source);

				resize(length);

				for (size_t i = 0; i < length; i++)
				{
					_content[i] = source[i];
				}
			}

			base_string(std::pmr::memory_resource* resource) :
				_capacity(0),
				_position(0),
				_content(nullptr),
				_resource(resource)
			{
			}

			base_string(const T* source, std::pmr::memory_resource* resource) :
				_capacity(0),
				_position(0),
				_content(nullptr),
				_resource(resource)
			{
				size_t length = strlen(source);

				resize(length);

				for (size_t i = 0; i < length; i++)
				{
					_content[i] = source[i];
				}
			}

			base_string& operator=(const T& source)
			{
				if (&source != this)
				{
					size_t length = strlen(source);

					resize(length);

					for (size_t i = 0; i < length; i++)
					{
						_content[i] = source[i];
					}
				}

				return *this;
			}

			bool operator== (const base_string<T>& source)
			{
				return (strcmp(_content, source.c_str()) == 0);
			}

			base_string& operator=(const T* source)
			{
				size_t length = strlen(source);

				resize(length);

				for (size_t i = 0; i < length; i++)
				{
					_content[i] = source[i];
				}

				return *this;
			}

			base_string<T>& operator+=(const base_string<T>& source)
			{
				for (size_t i = 0; i < source.size(); i++)
				{
					push_back(source[i]);
				}

				return *this;
			}

			base_string<T>& operator=(const base_string<T>& source)
			{
				if (&source != this)
				{
					size_t length = source.size();

					resize(length);

					for (size_t i = 0; i < length; i++)
					{
						_content[i] = source[i];
					}
				}

				return *this;
			}

			size_t capacity() const
			{
				return _capacity;
			}

			size_t size() const
			{
				return _position;
			}

			const T* c_str() const
			{
				return _content;
			}

			T* allocate(size_t count)
			{
				if (_resource)
				{
					void* ptr = _resource->allocate(count * sizeof(T));
				
					return new (ptr) T[count];
				}
				else
				{
					return new T[count];
				}
			}

			void reserve(size_t count)
			{
				size_t total = count + 1;

				if (total > _capacity)
				{
					T* p = allocate(total);

					for (size_t i = 0; i < _position; i++)
					{
						p[i] = _content[i];
					}

					_content  = p;
					_capacity = total;
				}
			}

			void resize(size_t count)
			{
				if (_capacity < count)
				{
					reserve(count);
				}

				_position           = count;
				_content[_position] = '\0';
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
				_content[_position] = '\0';
			}

			const T& at(size_t index) const
			{
				assert(index <= _position);

				return _content[index];
			}

			T& at(size_t index)
			{
				assert(index <= _position);

				return _content[index];
			}

			const T& operator[] (size_t index) const
			{
				assert(index <= _position);

				return _content[index];
			}

			T& operator[] (size_t index)
			{
				assert(index <= _position);

				return _content[index];
			}
		};
}

#endif 
