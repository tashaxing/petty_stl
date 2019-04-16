#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include <stdlib.h>

namespace petty_stl
{

template<typename T>
class allocator
{
public:
	static T *allocate();
	static T *allocate(size_t n);
	static void deallocate(T *ptr);
	static void deallocate(T *ptr, size_t n); // n bytes
	static void construct(T *ptr);
	static void construct(T *ptr, const T &val);
	static void destroy(T *ptr);
	static void destroy(T *first, T *last);
};

template<typename T>
T *allocator<T>::allocate()
{	
	return static_cast<T *>(malloc(sizeof(T)));
}

template<typename T>
T *allocator<T>::allocate(size_t n)
{
	if (n == 0)
		return NULL;

	return static_cast<T *>(malloc(sizeof(T) * n));
}

template<typename T>
void allocator<T>::deallocate(T *ptr)
{
	free(static_cast<void *>(ptr));
}

template<typename T>
void allocator<T>::deallocate(T *ptr, size_t n)
{
	// FIXME: should use memory pool to recycle and free n bytes
	free(static_cast<void *>(ptr));
}

template<typename T>
void allocator<T>::construct(T *ptr)
{
	new(ptr)T();
}

template<typename T>
void allocator<T>::construct(T *ptr, const T &val)
{
	new(ptr)T(value);
}

template<typename T>
void allocator<T>::destroy(T *ptr)
{
	// call T destructor
	ptr->~T();
}

template<typename T>
void allocator<T>::destroy(T *first, T *last)
{
	for (; first != last; ++first)
		first->~T();
}


} // namespace petty_stl

#endif