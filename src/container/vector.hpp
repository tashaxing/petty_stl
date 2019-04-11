#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "../iterator/iterator.hpp"
#include "../algorithm/algorithm.hpp"

namespace petty_stl
{

template<typename T>
class vector
{
//public:
//	// type alias, may not needed
//	using size_type = size_t;
//	using value_type = T;
//	using pointer_type = T *;
//	using reference_type = T &;
//	using iterator_type = T *;

public:
	vector() noexcept
	{}
	
	explicit vector(size_t n)
	{

	}

private:
	// init elements after the container cleared
	void init_elements(size_t n, const T &value)
	{

	}

	/*template<typename InputIterator>
	void init_elements()*/

private:
	// const variables
	
	
}; 


} // namespace petty_stl

#endif