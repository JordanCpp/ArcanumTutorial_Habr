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

#ifndef Pollux_Containers_HashMap_hpp
#define Pollux_Containers_HashMap_hpp

#include <string.h>
#include <Pollux/Allocators/Allocator.hpp>

namespace Pollux
{
    template<typename T>
    class HashMapNode
    {
    public:
        enum
        {
            KeyMax = 128
        };
        HashMapNode() :
            Next(NULL),
            Prev(NULL)
        {
            memset(Key, 0, KeyMax);
        }
        HashMapNode* Next;
        HashMapNode* Prev;
        char Key[KeyMax];
        T Content;
    };

    template<typename T>
    class HashMapList
    {
    public:
        HashMapList() :
            Head(NULL),
            Tail(NULL)
        {
        }

        void Add(HashMapNode<T>* node)
        {
            node->Next = NULL;
            node->Prev = Tail;

            if (Tail)
            {
                Tail->Next = node;
            }

            Tail = node;

            if (Head == NULL) {
                Head = node;
            }
        }

        HashMapNode<T>* Head;
        HashMapNode<T>* Tail;
    };

    template<typename T>
    class HashMap
    {
    public:
        HashMap(Allocator* allocator, size_t capacity) :
            _Allocator(allocator),
            _Capacity(capacity),
            _Table(NULL)
        {
            size_t elementSize   = sizeof(HashMapList<T>);
            size_t allocatedSize = elementSize * _Capacity;
            void* allocatedPtr   = _Allocator->Allocate(allocatedSize);

            _Table = new (allocatedPtr) HashMapList<T>[capacity];
        }

        ~HashMap()
        {
            _Allocator->Deallocate(_Table);
        }

        size_t HashLy(const char* str)
        {
            unsigned int hash = 0;

            for (; *str; str++)
                hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;

            return hash;
        }

        T* Get(const char* key)
        {
            size_t index = HashLy(key) % _Capacity;

            for (HashMapNode<T>* i = _Table[index].Head; i != NULL; i = i->Next)
            {
                if (strcmp(i->Key, key) == 0)
                {
                    return &i->Content;
                }
            }

            return NULL;
        }

        void Set(const char* key, const T& element)
        {
            if (Get(key) == NULL)
            {
                HashMapNode<T>* p = new (_Allocator->Allocate(sizeof(HashMapNode<T>))) HashMapNode<T>;

                strcpy(p->Key, key);
                p->Content = element;

                size_t index = HashLy(key) % _Capacity;

                _Table[index].Add(p);
            }
        }
    private:
        Allocator*      _Allocator;
        size_t          _Capacity;
        HashMapList<T>* _Table;
    };
}

#endif
