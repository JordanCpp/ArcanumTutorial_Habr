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

#ifndef litecpp_unordered_map_hpp
#define litecpp_unordered_map_hpp

#include <litecpp/string.hpp>

namespace std
{
	namespace pmr
	{
		template<typename K, typename T>
		class list_node
		{
		public:
			list_node(memory_resource* resource) :
				next(nullptr),
				prev(nullptr),
				first(resource)
			{
			}

			list_node*        next;
			list_node*        prev;
			std::pmr::string  first;
			T                 second;
		};

		template<typename K, typename T>
		class list
		{
		public:
			list() :
				head(nullptr),
				tail(nullptr)
			{
			}

			void append(list_node<K, T>* node)
			{
				node->next = nullptr;
				node->prev = tail;

				if (tail)
				{
					tail->next = node;
				}

				tail = node;

				if (head == nullptr) 
				{
					head = node;
				}
			}

			list_node<K, T>* head;
			list_node<K, T>* tail;
		};

		template <typename K, typename T>
		class unordered_map
		{
		private:
			size_t           _count;
			size_t           _bucket_count;
			list<K, T>*      _table;
			memory_resource* _resource;

		public:
			typedef list_node<K, T>* iterator;

			unordered_map(size_t bucket_count, memory_resource* resource) :
				_count(0),
				_bucket_count(bucket_count),
				_resource(resource)
			{
				size_t list_size      = sizeof(list<K, T>);
				size_t allocated_size = list_size * _bucket_count;
				void* allocated_ptr   = _resource->allocate(allocated_size);

				_table = new (allocated_ptr) list<K, T>[_bucket_count];
			}

			~unordered_map()
			{
			}

			size_t HashLy(const char* str)
			{
				unsigned int hash = 0;

				for (; *str; str++)
					hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;

				return hash;
			}

			void emplace(const K& key, const T& value)
			{
				iterator i = find(key);

				if (i == end())
				{
					void* ptr = _resource->allocate(sizeof(list_node<K, T>));

					list_node<K, T>* node = new (ptr) list_node<K, T>(_resource);

					node->first = key.c_str();
					node->second = value;

					size_t index = HashLy(key.c_str()) % _bucket_count;

					_table[index].append(node);

					_count++;
				}
			}
			
			list_node<K, T>* end()
			{
				return nullptr;
			}

			list_node<K, T>* find(const K& key)
			{
				size_t index = HashLy(key.c_str()) % _bucket_count;

				for (list_node<K, T>* i = _table[index].head; i != nullptr; i = i->next)
				{
					if (i->first == key.c_str())
					{
						return i;
					}
				}

				return nullptr;
			}

			size_t size()
			{
				return _count;
			}
		};
	}
}

#endif 
