#ifndef _STACK_H_
#define _STACK_H_

#include "vector.hpp"

namespace petty_stl
{

// not thread safe version
template<typename T, class Container = petty_stl::vector<T>>
class stack
{
public:
	explicit stack(const Container& container = Container()): _container(container)
	{}

	// basic opertion
	bool empty() const
	{
		return _container.empty();
	}

	size_t size() const
	{
		return _container.size();
	}

	T& top()
	{
		return _container.back();
	}

	void push(const T& val)
	{
		_container.push_back(val);
	}

	void pop()
	{
		_container.pop_back();
	}

	void swap(stack& other)
	{
		std::swap(_container, other._container);
	}

public:
	// operator
	template<typename T, class Container>
	friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs._container == rhs._container;
	}

	template<typename T, class Container>
	friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs._container != rhs._container;
	}

	template<typename T, class Container>
	void swap(stack<T, Container>& x, stack<T, Container>& y)
	{
		x.swap(y);
	}

private:
	Container _container;
};

}

#endif