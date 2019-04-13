#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <memory>
#include "../iterator/iterator.hpp"
#include "../algorithm/algorithm.hpp"

namespace petty_stl
{

template<typename T>
class vector
{
public:
	// constructor and destructor related
    vector(): _first(NULL), _last(NULL), _terminate(NULL)
	{}
	
	explicit vector(size_t n)
	{
		init_elements(n, T());
	}

	vector(size_t n, const T &value)
	{
		init_elements(n, value);
	}

	template<class InputIterator>
	vector(InputIterator first, InputIterator last)
	{
		// TODO:
	}

	vector(const vector &other)
	{
		copy_elements(other._first, other._last);
	}

    // rvalue constructor enabled only above C++11
//	vector(vector &&other)
//	{
//		_first = other._first;
//		_last = other._last;
//		_terminate = other._terminate;

//		other._first = NULL;
//		other._last = NULL;
//		other._terminate = NULL;
//	}

	vector &operator=(const vector &other)
	{
		if (this != &other)
			copy_elements(other._first, other._last);
		
		return *this;
	}

//    vector &operator=(vector &&other)
//    {
//        if (this != &other)
//        {
//            destroy();

//            _first = other._first;
//            _last = other._last;
//            _terminate = other._terminate;

//            other._first = NULL;
//            other._last = NULL;
//            other._terminate = NULL;
//        }

//        return *this;
//    }

	~vector()
	{
		destroy();
	}

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
		return _last - _first;
	}

	size_t capacity() const
	{
		return _terminate - _first;
	}

	bool empty() const
	{
		return _last == _first;
	}

	void resize(size_t n, T val = T())
	{
		// TODO:
		if (n < size())
		{
			
		}
		else if (n > size() && n <= capacity())
		{

		}
		else if (n > capacity())
		{
			size_t insert_len = n - size();

		}
	}

	void reserve(size_t n)
	{
		if (n <= capacity())
			return;

		T *new_first = _allocator.allocate(n);
		T *new_last = std::uninitialized_copy(begin(), end(), new_first);
		destroy();

		_first = new_first;
		_last = new_last;
		_terminate = _last + n;
	}

	void shrink_to_fit()
	{

	}

	// element access related
	T &operator[](const size_t i)
	{
		return *(begin() + i);
	}

    const T &operator[](const size_t i) const
	{
		return *(cbegin() + i);
	}

	T &front()
	{
		return *(begin());
	}

	T &back()
	{
		return *(end() - 1);
	}

	// modify related
	void clear()
	{

	}

	void swap(vector &other)
	{

	}

	void push_back(const T &val)
	{

	}

	void pop_back()
	{

	}

	// pointer as iterator
	T *insert(T *position, const T &val)
	{
		return NULL;
	}
	
	void insert(T *position, const size_t n, const T &val)
	{
		
	}

	template<class InputIterator>
	void insert(T *position, InputIterator first, InputIterator last)
	{

	}

	T *erase(T *position)
	{
		return erase(position, position + 1);
	}

	T *erase(T *first, T *last)
	{
		size_t tail_len = end() - last;
		size_t remove_len = last - first;

		_last = _last - remove_len;

		return NULL;
	}

private:
	// init elements after the container cleared
	void init_elements(size_t n, const T &value)
	{
		
	}

	template<class InputIterator>
	void copy_elements(InputIterator first, InputIterator last)
	{
		
	}

	void destroy()
	{

	}

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
