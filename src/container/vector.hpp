#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "../utility/allocator.hpp"
#include "../iterator/iterator.hpp"
#include "../algorithm/algorithm.hpp"

namespace petty_stl
{

template<typename T>
class vector
{
public:
	typedef T* iterator;
public:
	// constructor and destructor related
    vector(): _first(NULL), _last(NULL), _terminate(NULL)
	{}
	
	explicit vector(size_t n)
	{
		allocate_and_fill(n, T());
	}

	vector(size_t n, const T &val)
	{
		allocate_and_fill(n, val);
	}

	vector(std::initializer_list<T> vals)
		: vector(vals.begin(), vals.end())
	{
	}

	template<class InputIterator>
	vector(InputIterator first, InputIterator last)
	{
		allocate_and_copy(first, last);
	}

	vector(const vector &other)
	{
		allocate_and_copy(other._first, other._last);
	}

    // rvalue copy constructor enabled only above C++11
	vector(vector &&other)
	{
		_first = other._first;
		_last = other._last;
		_terminate = other._terminate;

		other._first = NULL;
		other._last = NULL;
		other._terminate = NULL;
	}

	vector &operator=(const vector &other)
	{
		if (this != &other)
			allocate_and_copy(other._first, other._last);
		
		return *this;
	}

	// rvalue asign constructor enabled only above C++11
    vector &operator=(vector &&other)
    {
        if (this != &other)
        {
			// free first
			destroy_all();

            _first = other._first;
            _last = other._last;
            _terminate = other._terminate;

            other._first = NULL;
            other._last = NULL;
            other._terminate = NULL;
        }

        return *this;
    }

	~vector()
	{
		destroy_all();
	}

	// compare related
	bool operator==(const vector &other) const
	{
		if (size() != other.size())
			return false;

		T *p1 = _first;
		T *p2 = other._first;
		while (p1 != _last && p2 != other._last)
		{
			if (*p1 != *p2)
				return false;

			++p1;
			++p2;
		}

		return true;
	}

	bool operator!=(const vector &other) const
	{
		return !(*this == other);
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
		if (n < size())
		{
			petty_stl::allocator::destroy(_first + n, _last);
			_last = _first + n;
		}
		else if (n > size() && n <= capacity())
		{
			size_t insert_len = n - size();
			_last = std::uninitialized_fill_n(_last, insert_len, val);
		}
		else if (n > capacity())
		{
			// copy to another space
			size_t insert_len = n - size();
			T *new_start = petty_stl::allocator::allocate(new_capacity(insert_len));
			T *new_end = std::uninitialized_copy(begin(), end(), new_start);
			new_end = std::uninitialized_fill_n(new_end, insert_len, val);

			destroy_all();
			_first = new_start;
			_last = new_end;
			_terminate = _first + n;
		}
	}

	void reserve(size_t n)
	{
		if (n <= capacity())
			return;

		T *new_first = petty_stl::allocator<T>::allocate(n);
		T *new_last = std::uninitialized_copy(begin(), end(), new_first);
		destroy_all();

		_first = new_first;
		_last = new_last;
		_terminate = _last + n;
	}

	void shrink_to_fit()
	{
		T *p = (T *)petty_stl::allocator::allocate(size());
		_last = std::uninitialized_copy(_first, _last, p);
		petty_stl::allocator::deallocate(_first, capacity());
		_first = p;
		_terminate = _last;
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
		petty_stl::allocator::destroy(_first, _last);
		_last = _first;
	}

	void swap(vector &other)
	{
		if (this != &other)
		{
			std::swap(_first, other._first);
			std::swap(_last, other._last);
			std::swap(_terminate, other._terminate);
		}
	}

	void push_back(const T &val)
	{
		insert(end(), val);
	}

	void pop_back()
	{
		--_last;
		petty_stl::allocator<T>::destroy(_last);
	}

	// pointer as iterator
	T *insert(T *position, const T &val)
	{
		size_t offset = position - begin();
		insert(position, 1, val);
		return begin() + offset;
	}
	
	void insert(T *position, const size_t n, const T &val)
	{
		size_t spare_len = _terminate - _last;
		size_t need_len = n;

		if (spare_len >= need_len)
		{
			T *p = end() - 1;
			// shift the elements to the for n space
			while (p - position >= 0)
			{
				petty_stl::allocator<T>::construct(p + need_len, *p);
				--p;
			}
			// fill in n elements
			std::uninitialized_fill_n(position, n, val);
			_last += need_len;
		}
		else
			reallocate_and_fill(position, n, val);
	}

	//template<class InputIterator>
	void insert(T *position, T* first, T* last)
	{
		size_t spare_len = _terminate - _last;
		size_t need_len = last - first;

		if (spare_len >= need_len)
		{
			// these two scenarios are complex, need a picture to illustrate the logic
			if (_last - position > need_len)
			{
				std::uninitialized_copy(_last - need_len, _last, _last);
				std::copy_backward(position, _last - need_len, _last);
				std::copy(first, last, position);
			}
			else
			{
				// when to use copy or uninitialized_copy?
				T *p = std::uninitialized_copy(first + _last - position, last, _last);
				std::uninitialized_copy(position, _last, p);
				std::copy(first, first + _last - position, position); 
			}
			_last += need_len;
		}
		else
			reallocate_and_copy(position, first, last);
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

		while (remove_len > 0)
		{
			// shift elements 
			T *temp = last - remove_len;
			*temp = *(last++);
			--remove_len;
		}

		return first;
	}

private:
	// init elements after the container cleared
	void allocate_and_fill(size_t n, const T &val)
	{
		_first = petty_stl::allocator::allocate(n);
		std::uninitialized_fill_n(_first, n, val);
		_last = _first + n;
		_terminate = _last; // FIXME: extra space?
	}

	void reallocate_and_fill(T *position, size_t n, const T &val)
	{
		size_t new_capacity_len = new_capacity(n);
		T *new_first = petty_stl::allocator<T>::allocate(new_capacity_len);
		T *new_terminate = new_first + new_capacity_len;

		// copy the former part, insert the middle part, shift the tail part
		T *new_last = std::uninitialized_copy(begin(), position, new_first);
		new_last = std::uninitialized_fill_n(new_last, n, val);
		new_last = std::uninitialized_copy(position, end(), new_last);

		// destroy old vector
		destroy_all();
		_first = new_first;
		_last = new_last;
		_terminate = new_terminate;
	}

	template<class InputIterator>
	void allocate_and_copy(InputIterator first, InputIterator last)
	{
		_first = petty_stl::allocator::allocate(last - first);
		_last = std::uninitialized_copy(_first, last, _last);
		_terminate = _last; // FIXME: extra space?
	}

	template<class InputIterator>
	void reallocate_and_copy(T *position, InputIterator first, InputIterator last)
	{
		size_t new_capacity_len = new_capacity(last - first);
		T *new_first = petty_stl::allocator::allocate(new_capacity_len);
		T *new_terminate = new_first + new_capacity_len;

		// copy the former part, insert the middle part, shift the tail part
		T *new_last = std::uninitialized_copy(begin(), position, new_first);
		new_last = std::uninitialized_copy(first, last, new_last);
		new_last = std::uninitialized_copy(position, end(), new_last);

		// destroy old vector
		destroy_all();
		_first = new_first;
		_last = new_last;
		_terminate = new_terminate;
	}

	void destroy_all()
	{
		if (capacity() != 0)
		{
			// destruct before free space
			petty_stl::allocator<T>::destroy(_first, _last);
			petty_stl::allocator<T>::deallocate(_first, capacity());
		}
	}

	size_t new_capacity(size_t len) const
	{
		// FIXME: expand pace actually is double
		size_t old_capcacity = _terminate - _first;
		size_t new_len = petty_stl::max(old_capcacity, len); // expand step len
		size_t new_capacity = old_capcacity > 0 ? old_capcacity + new_len : len;
		
		return new_capacity;
	}

private:
	T *_first; // the first element pointer
	T *_last; // the first free space pointer
	T *_terminate; // the one past end of the allocated space pointer
}; 


} // namespace petty_stl

#endif
