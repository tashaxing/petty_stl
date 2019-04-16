#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

namespace petty_stl
{
	// max
	template<typename T>
	const T &max(const T &a, const T &b)
	{
		return a > b ? a : b;
	}

	template<typename T>
	const T &min(const T &a, const T &b)
	{
		return a < b ? a : b;
	}

	// min
	template<typename T, class Compare>
	const T &max(const T &a, const T &b, Compare comp)
	{
		return comp(a, b) ? a : b;
	}

	template<typename T, class Compare>
	const T &min(const T &a, const T &b, Compare comp)
	{
		return !comp(a, b) ? a : b;
	}

	// find
	template<class InputIterator, typename T>
	InputIterator find(InputIterator first, InputIterator last, const T &val)
	{
		while (first != last)
		{
			if (*first == val)
				break;
			++first;
		}

		return first;
	}

	template<class InputIterator, class UnaryPredicate>
	InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		while (first != last)
		{
			if (pred(*first)) 
				return first;
			++first;
		}
		return last;
	}

	template<class InputIterator, class UnaryPredicate>
	InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		while (first != last)
		{
			if (!pred(*first))
				return first;
			++first;
		}
		return last;
	}

	// sort

} // namespace petty_stl

#endif