#ifndef _ITERATOR_H_
#define _ITERATOR_H_

namespace petty_stl
{

// five kinds of iterators
template<typename T>
struct input_iterator
{};

template<typename T>
struct output_iterator
{};

template<typename T>
struct forward_iterator
{};

template<typename T>
struct bidirectional_iterator
{};

template<typename T>
struct random_access_iterator
{};

template<typename Iterator>
struct iterator_traits
{};

}

#endif