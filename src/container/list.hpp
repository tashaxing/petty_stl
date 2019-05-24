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

		bool operator==(const link_node& other)
		{
			return value == other.value && pre == other.pre && next == other.next;
		}

		T value;
        link_node* pre;
        link_node* next;
	};

public:
	struct iterator
	{
	public:
		iterator(): _ptr(NULL)
		{}

		iterator(link_node* ptr) : _ptr(ptr)
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

		// shift right
		iterator operator+(int n)
		{
			for (int i = 0; i < n; i++)
				++*this;
			return *this;
		}

		// shift left
		iterator operator-(int n)
		{
			for (int i = 0; i < n; i++)
				--*this;
			return *this;
		}

		bool operator==(const iterator& other) const
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const iterator& other) const
		{
			return _ptr != other._ptr;
		}

		link_node* _ptr;
	};

public:
	// constructor and destructor related
	list()
	{
		_head = create_node(); // empty dummy node
		_tail = _head;
	}

	list(size_t n, const T& val = T())
	{
		_head = create_node(); // empty dummy node
		_tail = head;
		while (n--)
			push_back(val);
	}

	template <class InputIterator>
	list(InputIterator first, InputIterator last)
	{
		_head = create_node(); // empty dummy node
		_tail = head;
		for (InputIterator iter = first; iter != last; ++iter)
			push_back(*iter);
	}

	list(const list& other)
	{
		_head = create_node(); // empty dummy node
		_tail = head;
		for (link_node* p = other._head; p != other._tail; p = p->next)
			push_back(p->value);
	}

//	list(list&& other)
//	{
//		swap(other);
//	}

	list& operator=(const list& other)
	{
		if (this != &other)
			list(other).swap(*this);
		return *this;
	}

//	list& operator=(const list&& other)
//	{


//		return *this;
//	}

	~list()
	{
		link_node* p = _head;
		/*while (p != _tail)
		{
			link_node* s = p;
			p = p->next;

			petty_stl::allocator<link_node>::destroy(s);
			petty_stl::allocator<link_node>::deallocate(s);
		}*/

		// FIXME: free the dummy node
		petty_stl::allocator<link_node>::destroy(p);
		petty_stl::allocator<link_node>::deallocate(p);
	}

	// compare related
	bool empty() const
	{
		return _head == _tail;
	}

	size_t size() const
	{
		size_t len = 0;
		for (link_node* p = _head; p != _tail; p = p->next)
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
		link_node* node_ptr = create_node(val);
		_head->pre = node_ptr;
		node_ptr->next = _head;
		_head = node_ptr;
	}

	void pop_front()
	{
		link_node* node_ptr = _head;
		_head = node_ptr->next;
		_head->pre = NULL;
		delete_node(node_ptr);
	}

	void push_back(const T& val)
	{
		// smart way to insert, also ok for empty list
		link_node* node_ptr = create_node();
		_tail->value = val;
		_tail->next = node_ptr;
		node_ptr->pre = _tail;
		_tail = node_ptr;
	}

	void pop_back()
	{
		link_node* node_ptr = _tail->pre;
		node_ptr->next = NULL;
		delete_node(_tail);
		_tail = node_ptr;
	}

	iterator begin()
	{
		return iterator(_head);
	}

	iterator end()
	{
		return iterator(_tail);
	}

	const iterator cbegin() const
	{
		return iterator(_head);
	}

	const iterator cend() const
	{
		return iterator(_tail);
	}

	// TODO: rbegin, rend

	iterator insert(iterator position, const T& val)
	{
		if (position == begin())
		{
			push_front(val);
			return begin();
		}
		else if (position == end())
		{
			iterator iter = position;
			push_back(val);
			return iter;
		}

		link_node* node_ptr = create_node(val);
		link_node* pre_node_ptr = position._ptr->pre;
		node_ptr->next = position._ptr;
		node_ptr->pre = pre_node_ptr;
		pre_node_ptr->next = node_ptr;
		position._ptr->pre = node_ptr;

		return iterator(node_ptr);
	}

	void insert(iterator position, size_t n, const T& val)
	{
		while (n > 0)
		{
			position = insert(position, val);
			--n;
		}
	}

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last)
	{
		--last; // shift to the last enable element
		while (last != first)
		{
			position = insert(position, *last);
			--last;
		}
		insert(position, *last);
	}

	iterator erase(iterator position)
	{
		if (position == begin())
		{
			pop_front();
			return begin();
		}
		else
		{
			link_node* pre_node_ptr = position._ptr->pre;
			pre_node_ptr->next = position._ptr->next;
			pre_node_ptr->next->pre = pre_node_ptr;
			delete_node(position._ptr);
			return iterator(pre_node_ptr->next);
		}
	}

	iterator erase(iterator first, iterator last)
	{
		// make sure first != last
		iterator ret;
		for (iterator iter = first; iter != last; ++iter)
		{
			iterator temp_iter = iter;
			ret = erase(temp_iter);
		}

		return ret;
	}

	void swap(list& other)
	{
		// use std swap to do detail operation
		std::swap(_head, other._head);
		std::swap(_tail, other._tail);
	}

    void clear()
	{
		erase(begin(), end());
	}

	void splice(iterator position, list& other)
	{
		insert(position, other.begin(), other.end());
		other._head = other._tail; // FIXME: for what?
	}

	void splice(iterator position, list& other, iterator iter)
	{
		iterator next_iter = iter;
		++next_iter;
		splice(position, other, iter, next_iter);
	}

	void splice(iterator position, list& other, iterator first, iterator last)
	{
		if (first == last)
			return;

		link_node* tail_node = last._ptr->pre;

		// cut off the other list
		if (other.begin() == first)
		{
			other._head = last._ptr;
			other._head->pre = NULL;
		}
		else
		{
			first._ptr->pre->next = last._ptr;
			last._ptr->pre = first._ptr->pre;
		}

		// do the list insert
		if (position == begin())
		{
			first._ptr->pre = NULL;
			tail_node->next = _head;
			_head->pre = tail_node;
			_head = first._ptr;
		}
		else
		{
			position._ptr->pre->next = first._ptr;
			first._ptr->pre = position._ptr->pre;
			tail_node->next = position._ptr;
			position._ptr->pre = tail_node;
		}
	}

	// list specific algorithm
	void unique()
	{
		link_node* p = _head;
		while (p != _tail)
		{
			link_node* next_node_ptr = p->next;
			if (p->value == next_node_ptr->value)
			{
				if (next_node_ptr == _tail)
				{
					p->next = NULL;
					_tail = p;
				}
				else
				{
					p->next = next_node_ptr->next;
					next_node_ptr->next->pre = p;
				}
				delete_node(next_node_ptr);
			}
			else
				p = next_node_ptr;
		}
	}

	void merge(list& other)
	{
		iterator iter1 = begin();
		iterator iter2 = other.begin();
		while (iter1 != end() && iter2 != other.end())
		{
			if (*iter1 <= *iter2)
				++iter1
			else
			{
				iterator iter = iter2;
				++iter2;
				splice(iter1, other, iter);
			}
		}
		
		if (iter1 == end())
			splice(iter1, other, iter2, end());
	}

	template<class Compare>
	void merge(list& other, Compare comp)
	{
		iterator iter1 = begin();
		iterator iter2 = other.begin();
		while (iter1 != end() && iter2 != other.end())
		{
			if (comp(*iter1, *iter2))
				++iter1
			else
			{
				iterator iter = iter2;
				++iter2;
				splice(iter1, other, iter);
			}
		}

		if (iter1 == end())
			splice(iter1, other, iter2, end());
	}

	void sort()
	{
		// skip size is 0 or 1
		if (empty() || _head->next == _tail)
			return;

		// here use insert sort
		list tmp;
		iterator q = begin();
		while (!empty())
		{
			iterator p = tmp.begin();
			while (p != tmp.end() && *p < *q)
				p++;
			tmp.splice(p, *this, q);
			q = begin();
		}

		// assign tmp to list
		swap(tmp);
	}

	template<class Compare>
	void sort(Compare comp)
	{
		if (empty() || _head->next == _tail)
			return;

		// skip size is 0 or 1
		if (empty() || _head->next == _tail)
			return;

		// here use insert sort
		list tmp;
		iterator q = begin();
		while (!empty())
		{
			iterator p = tmp.begin();
			while (p != tmp.end() && comp(*p, *q))
				p++;
			tmp.splice(p, q);
			q = begin();
		}

		// assign tmp to list
		swap(tmp);
	}

	void reverse()
	{
		if (empty() || _head->next == _tail)
			return;

		link_node* cur_node = _head;
		_head = _tail->pre;
		_head->pre = NULL;

		// insert from the tail as new list
		do
		{
			link_node* next_node = cur_node->next;
			cur_node->next = _head->next;
			_head->next->pre = cur_node;
			_head->next = cur_node;
			cur_node->pre = _head;
			cur_node = next_node;
		} while (cur_node != _head)
	}

public:
	template<typename T>
	friend void swap(list<T>& l1, list<T>& l2)
	{
		std::swap(l1._head, l2._head);
		std::swap(l1._tail, l2._tail);
	}

	template<typename T>
	friend bool operator==(const list<T>& l1, const list<T>& l2)
	{
		link_node* node1 = l1._head;
		link_node* node2 = l2._tail;
		for (; node1 != l1._tail && node2 != l2._tail; node1 = node1->next, node2 = node2->next)
		{
			if (node1->value != node2->value)
				break;
		}

		if (node1 == l1._tail && node2 == l2._tail)
			return true;

		return false;
	}

	template<typename T>
	friend bool operator!=(const list<T>& l1, const list<T>& l2)
	{
		return !(l1 == l2);
	}


private:
	link_node* create_node(const T& val = T())
	{
		// create a node with element value
		link_node* node_ptr = petty_stl::allocator<link_node>::allocate();
		petty_stl::allocator<link_node>::construct(node_ptr, link_node(val));
		return node_ptr;
	}

	void delete_node(link_node* p)
	{
		p->pre = NULL;
		p->next = NULL;
		petty_stl::allocator<link_node>::destroy(p);
		petty_stl::allocator<link_node>::deallocate(p);
	}

private:
    link_node* _head;
	link_node* _tail; // dummy tail node
};

} // namespace petty_stl

#endif
