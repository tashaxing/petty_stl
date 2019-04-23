#include <iostream>
#include "container/vector.hpp"
#include "container/list.hpp"

int main(int argc, char *argv[])
{
	std::cout << "welcome" << std::endl;

	petty_stl::vector<int> vec;
	vec.reserve(15);
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(7);
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;

	vec.pop_back();
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;

	vec.insert(vec.begin() + 2, 9);
	//for (petty_stl::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	//	*it += 3;
	//std::cout << std::endl;
	for (petty_stl::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	
	std::cout << *vec.begin() << std::endl;
	std::cout << *vec.end() << std::endl;

	/*vec.erase(vec.begin() + 1);
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;*/

	getchar();

	return 0;
}