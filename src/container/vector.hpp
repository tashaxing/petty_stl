#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "../iterator/iterator.hpp"
#include "../algorithm/algorithm.hpp"

namespace petty_stl
{

template<typename T>
class vector
{
public:
	// constructor and destructor related
	vector(): _first(NULL), _last(NULL), _end(NULL)
	{}
	
	explicit vector(size_t n)
	{
		init_elements(n, T());
	}

	vector(size_t n, const T &value)
	{
		init_elements(n, value);
	}

	vector(const vector &other)
	{

	}

	vector &operator=(const vector &other)
	{
		
		
		return *this;
	}

	vector(vector &&other)
	{

	}

	vector &operator=(vector &&other)
	{
		if (this != other)
		{

		}
	}

	~vector()
	{}

	// compare related
	bool operator==(const vector &other) const
	{
		return true;
	}

	bool operator!=(const vector &other) const
	{
		return true;
	}

	// iterator related (pointer as iterator)
	T *begin()
	{
		return _first;
	}
	
	const T *cbegin() const
	{
		return _first;
	}

	T *end()
	{
		return _last;
	}

	const T *cend() const
	{
		return _last;
	}

	// rbegin
	// rend

	// capacity related
	size_t size() const
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
	T *_first; // the first element pointer
	T *_last; // the first free space pointer
	T *_terminate; // the one past end of the allocated space pointer
	std::allocator<T> _allocator;

private:
	// const variables
	
	
}; 


} // namespace petty_stl

#endif