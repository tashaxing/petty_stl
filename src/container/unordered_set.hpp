#ifndef _UNORDERED_SET_H_
#define _UNORDERED_SET_H_

namespace petty_stl
{

template<typename T>
class unordered_set
{

public:
	explicit unordered_set(size_t n)
	{

	}

	template<class InputIterator>
	unordered_set(InputIterator first, InputIterator last)
	{

	}

	unordered_set(const unordered_set& other)
	{

	}

	unordered_set& operator=(const unordered_set& other)
	{

	}

	size_t size() const
	{
		// TODO:
		return 0;
	}

	bool empty() const
	{
		// TODO:
		return false;
	}

	iterator begin()
	{
		
	}
	
	iterator end()
	{

	}

	iterator find(const T& key)
	{

	}

	size_t count(const T& key)
	{

	}

	template<class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{

	}

	iterator erase(iterator position)
	{

	}

	size_t erase(const T& key)
	{

	}

public:
	//friend void swap()
};

}

#endif