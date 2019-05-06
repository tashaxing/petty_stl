#ifndef _LIST_H_
#define _LIST_H_

#include "../utility/allocator.hpp"

namespace petty_stl
{

template<typename T>
class list
{
private:
	struct link_node
	{
	public:
        explicit link_node(const T& val) : value(val), pre(NULL), next(NULL)
		{}

//		link_node(const T& val, link_node* pre, link_node*&& next)
//			: value(value), _pre(pre), _next(std::move(next))
//		{}

//		link_node(const T&& value, link_node* pre, link_node*&& next)
//			: _value(std::move(value)), _pre(pre), _next(std::move(next))
//		{}

		// customize default constructors
//		link_node(link_node&&) = default;
//		link_node& operator=(link_node&&) = default;

		T value;
		T* pre;
		T* next;

	private:
		// disable some constructors
		link_node(const link_node&);
		link_node& operator=(const link_node&);	
	};

public:
	struct iterator
	{
	public:
		iterator(): _ptr(NULL)
		{}

		T& operator*() const
		{
			return _ptr->value;
		}

		T* operator->() const
		{
			return &(operator*());
		}

		// ++ prefix
		iterator& operator++()
		{
			// shift to next link node
			_ptr = _ptr->next;
			return *this;
		}

		// ++ suffix
		iterator operator++(int)
		{
			iterator tmp = *this;
			++*this;
			return tmp;
		}

		// -- prefix
		iterator& operator--()
		{
			_ptr = _ptr->pre;
			return *this;
		}

		// -- suffix
		iterator operator--(int)
		{
			iterator tmp = *this;
			--*this;
			return tmp;
		}

		bool operator==(const iterator& other) const
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const iterator& other) const
		{
			return _ptr != other._ptr;
		}

	protected:
		iterator(link_node* ptr): _ptr(ptr)
		{}

		link_node* _ptr;
	};

public:
	// constructor and destructor related
	list()
	{
		_head.
	}

	explicit list(size_t n, const T& val = T())
	{}

	template <class InputIterator>
	list(InputIterator first, InputIterator last)
	{

	}

	list(const list& other)
	{}

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

	~list()
	{
		clear();

	}

	// compare related
	bool emtpy() const
	{
		return _head == _tail;
	}

	size_t size() const
	{
		size_t len = 0;
		for (link_node* p = _head; p != _tail; ++p)
			++len;

		return len; 
	}

	// operation
	T& front()
	{
		return _head->value;
	}

	T& back()
	{
		return _tail->pre->value;
	}

	void push_front(const T& val)
	{

	}

	void pop_front()
	{

	}

	void push_back(const T& val)
	{

	}

	void pop_back()
	{

	}

	link_node* begin()
	{
		return NULL;
	}

	link_node* end()
	{
		return NULL;
	}

	const link_node* cbegin() const
	{
		return NULL;
	}

	const link_node* cend() const
	{
		return NULL;
	}

	// rbegin, rend

	link_node* insert(link_node* position, const T& val)
	{
		return NULL;
	}

	void insert(link_node* position, size_t n, const T& val)
	{

	}

	template <class InputIterator>
	void insert(link_node* position, InputIterator first, InputIterator last)
	{

	}

	link_node* erase(link_node* position)
	{
		return NULL;
	}

	link_node* erase(link_node* first, link_node* last)
	{

	}

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

	void splice(link_node* position, list& other)
	{

	}

	void splice(link_node* position, list& other, link_node* i)
	{

	}

	void splice(link_node* position, list& other, link_node* first, link_node* last)
	{

	}

	// list specific algorithm
	void unique()
	{

	}

	void merge(list& other)
	{

	}

	template<class Compare>
	void merge(list& other, Compare comp)
	{

	}

	void sort()
	{

	}

	template<class Compare>
	void sort(Compare comp)
	{

	}

	void reverse()
	{

	}

public:
	template<typename T>
	friend void swap(list<T>& l1, list<T>& l2)
	{

	}

	template<typename T>
	friend bool operator==(const list<T>& l1, const list<T>& l2)
	{
		return true;
	}

	template<typename T>
	friend bool operator!=(const list<T>& l1, const list<T>& l2)
	{
		return true;
	}


private:
	void empty_init()
	{

	}

	link_node* create_node(const T& val = T())
	{
		// create a node with element value
		
	}

private:
    link_node* _head; // dummy head node
	link_node* _tail; // dummy tail node
};

} // namespace petty_stl

#endif
