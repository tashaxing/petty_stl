#ifndef _LIST_H_
#define _LIST_H_

#include <memory>

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
		iterator()
		{

		}

		T& operator*() const
		{
			return _ptr->value;
		}

		T* operator->() const
		{
			return &(operator*());
		}

		iterator operator--(size_t)
		{
			return NULL;
		}

	protected:
		link_node* _ptr;
	};

public:
	// constructor and destructor related
	list()
	{

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
		// TODO:
		return 0; 
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

private:
	void empty_init()
	{

	}

	link_node* create_node(const T& val)
	{
		// create a node with element value

	}

private:
    link_node* _head;
	link_node* _tail;
};

} // namespace petty_stl

#endif
