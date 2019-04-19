#include <iostream>
#include "container/vector.hpp"
#include "container/list.hpp"

int main(int argc, char *argv[])
{
	std::cout << "welcome" << std::endl;

	petty_stl::vector<int> vec;
	vec.reserve(10);
	//vec.push_back(2);
	//vec.push_back(3);
	//vec.push_back(4);
	//vec.push_back(7);

	//for (int i = 0; i < vec.size(); i++)
	//	std::cout << vec[i] << ' ';
	//std::cout << std::endl;


	return 0;
}