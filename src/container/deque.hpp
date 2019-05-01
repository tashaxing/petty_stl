#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "../utility/allocator.hpp"
#include "../iterator/iterator.hpp"

namespace petty_stl
{

template<typename T>
class deque
{
public:
	deque()
	{}

	explicit deque(size_t n, const T& val = T())
	{}

	template<class InputIterator>
	deque(InputIterator first, InputIterator last)
	{}


};

}

#endif // !_DEQUE_H_
