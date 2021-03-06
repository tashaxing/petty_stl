#include <iostream>
#include "algorithm/algorithm.hpp"
#include "container/vector.hpp"
#include "container/stack.hpp"
#include "container/list.hpp"
#include <stack>

int main(int argc, char* argv[])
{	
	std::cout << "welcome" << std::endl;

	// ---- test vector ---- //
	//petty_stl::vector<int> vec;
	//vec.reserve(15);
	//std::cout << vec.size() << std::endl;
	//std::cout << vec.capacity() << std::endl;

	//std::cout << (vec.empty() ? "empty" : "not empty") << std::endl;
	//
	//vec.push_back(2);
	//vec.push_back(3);
	//vec.push_back(4);
	//vec.push_back(7);
	//for (int i = 0; i < vec.size(); i++)
	//	std::cout << vec[i] << ' ';
	//std::cout << std::endl;

	//std::cout << vec.front() << std::endl;
	//std::cout << vec.back() << std::endl;

	//petty_stl::vector<int> vec_copy(vec);
	//for (int i = 0; i < vec_copy.size(); i++)
	//	std::cout << vec_copy[i] << ' ';
	//std::cout << std::endl;

	//vec.pop_back();
	//for (int i = 0; i < vec.size(); i++)
	//	std::cout << vec[i] << ' ';
	//std::cout << std::endl;

	//vec.insert(vec.begin() + 2, 9);
	//vec.insert(vec.end() - 1, 6);
	////for (petty_stl::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	////	*it += 3;
	////std::cout << std::endl;
	//for (petty_stl::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	//	std::cout << *it << ' ';
	//std::cout << std::endl;
	//
	//std::cout << vec.front() << std::endl;
	//std::cout << vec.back() << std::endl;

	//petty_stl::vector<int>::iterator pos = petty_stl::find(vec.begin(), vec.end(), 9);
	//std::cout << "find 9 position: " << pos - vec.begin() << std::endl;

	/*vec.erase(vec.begin() + 1);
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;*/

	//std::cout << (vec.empty() ? "empty" : "not empty") << std::endl;

	//vec.clear();
	//std::cout << (vec.empty() ? "empty" : "not empty") << std::endl;

	// ---- test list ---- //
	petty_stl::list<int> my_list;
    my_list.push_back(1);
    my_list.push_back(7);
    my_list.push_back(3);
	my_list.push_back(5);
	my_list.push_back(5);

	my_list.insert(my_list.begin() + 2, 4);
	//my_list.erase(my_list.end() - 2);

    std::cout << my_list.size() << std::endl;

	my_list.sort();
	my_list.unique();

	std::cout << my_list.front() << std::endl;
	std::cout << my_list.back() << std::endl;

	for (petty_stl::list<int>::iterator it = my_list.begin(); it != my_list.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	// ---- test queue ---- //

	// ---- test stack ---- //
	/*petty_stl::stack<int> my_stack;
	std::cout << (my_stack.empty() ? "empty" : "not empty") << std::endl;
	std::cout << my_stack.size() << std::endl;

	my_stack.push(11);
	my_stack.push(12);
	my_stack.push(13);
	my_stack.push(14);
	std::cout << my_stack.size() << std::endl;

	my_stack.pop();
	std::cout << (my_stack.empty() ? "empty" : "not empty") << std::endl;
	std::cout << my_stack.size() << std::endl;

	while (!my_stack.empty())
	{
		int top = my_stack.top();
		std::cout << top << ' ';
		my_stack.pop();
	}
	std::cout << std::endl;
	std::cout << (my_stack.empty() ? "empty" : "not empty") << std::endl;
	std::cout << my_stack.size() << std::endl;*/

	getchar();

	return 0;
}
