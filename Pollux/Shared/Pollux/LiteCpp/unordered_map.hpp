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

#ifndef Pollux_LiteCpp_unordered_map_hpp
#define Pollux_LiteCpp_unordered_map_hpp

#include <Pollux/LiteCpp/memory_resource.hpp>
#include <Pollux/Common/Assert.hpp>

#define table_max  4096

namespace std
{
	namespace pmr
	{
		template <typename K, typename T>
		class list_node_iterator
		{
		public:
		private:
		};

		template<typename K, typename T>
		class list_node
		{
		public:
			list_node() :
				next(NULL),
				prev(NULL)
			{
			}

			list_node* next;
			list_node* prev;
			K          first;
			T          second;
		};

		template<typename K, typename T>
		class list
		{
		public:
			list() :
				head(NULL),
				tail(NULL)
			{
			}

			void append(list_node<K, T>* node)
			{
				node->next = NULL;
				node->prev = tail;

				if (tail)
				{
					tail->next = node;
				}

				tail = node;

				if (head == NULL) {
					head = node;
				}
			}

			list_node<K, T>* head;
			list_node<K, T>* tail;
		};

		template <typename K, typename T>
		class unordered_map
		{
		public:
			unordered_map(memory_resource* source) :
				_memory(source)
			{
				size_t list_size      = sizeof(list<K, T>);
				size_t allocated_size = list_size * table_max;
				void* allocated_ptr   = _memory->allocate(allocated_size);

				_table = new (allocated_ptr) list<K, T>[table_max];
			}

			~unordered_map()
			{
			}

			void emplace(const K& key, const T& value)
			{
				list_node<K, T>* node = new (_memory->allocate(sizeof(list_node<K, T>))) list_node<K, T>;

				node->first  = key;
				node->second = value;

				_table[0].append(node);
			}
			
			typedef list_node<K, T>* iterator;

			list_node<K, T>* end()
			{
				return NULL;
			}

			list_node<K, T>* find(const K& key)
			{
				for (list_node<K, T>* i = _table[0].head; i != NULL; i = i->next)
				{
					if (i->first == key)
					{
						return i;
					}
				}

				return NULL;
			}
		private:
			list<K, T>*      _table;
			memory_resource* _memory;
		};
	}
}

#endif 
