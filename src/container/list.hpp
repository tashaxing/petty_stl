#ifndef _LIST_H_
#define _LIST_H_

#include <memory>

namespace petty_stl
{

template<typename T>
class list
{
public:
	typedef T* iterator;
private:
	struct link_node
	{
        explicit link_node(const T& value) : _value(value), _pre(NULL), _next(NULL)
		{}

//		link_node(const T& value, link_node* pre, link_node*&& next)
//			: _value(value), _pre(pre), _next(std::move(next))
//		{}

//		link_node(const T&& value, link_node* pre, link_node*&& next)
//			: _value(std::move(value)), _pre(pre), _next(std::move(next))
//		{}

		// customize default constructors
//		link_node(link_node&&) = default;
//		link_node& operator=(link_node&&) = default;

		// disable some constructors
		link_node(const link_node& ) = delete;
		link_node& operator=(const link_node&) = delete;

		T _value;
		T* _pre;
		T* _next;
	};

public:
	list()
	{

	}

	explicit list(size_t n)
	{}

	list(size_t n, const T& value)
	{}

	//list(const list& other)
	//{}

//	list(list&& other)
//	{
//		swap(other);
//	}

	list& operator=(const list& other)
	{

		return *this;
	}

//	list& operator=(const list&& other)
//	{


//		return *this;
//	}

    void swap(list& other)
	{
		// use std swap to do detail operation
		std::swap(_head, other._head);
		std::swap(_tail, other._tail);
		std::swap(_size, other._size);
	}

    void clear()
	{
		
	}

private:
    link_node* _head;
	link_node* _tail;
	size_t _size;
};

} // namespace petty_stl

#endif
