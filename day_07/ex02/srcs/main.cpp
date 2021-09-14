#include <string>
#include <iostream>
#include "Array.hpp"

int		main(void)
{
	Array<int>	empty;

	std::cout << "empty.size() = " << empty.size() << std::endl;

	Array<int>	int_arr(5);

	for (size_t i = 0; i < int_arr.size(); i++)
	{
		int_arr[i] = i;
	}

	std::cout << "int_arr.size() = " << int_arr.size() << std::endl;

	std::cout << "Print int_arr" << std::endl;
	iter(int_arr, print);

	Array<int>	copy_arr(int_arr);

	std::cout << "Print copy_arr" << std::endl;
	iter(copy_arr, print);

	copy_arr[2] = 42;
	copy_arr[4] = 21;

	int_arr[0] = 228;
	int_arr[3] = 25;

	std::cout << "Print copy_arr after editing" << std::endl;
	iter(copy_arr, print);

	std::cout << "Print int_arr after editing" << std::endl;
	iter(int_arr, print);


	for (size_t i = 0; i < int_arr.size(); i++)
	{
		int_arr[i] = i;
	}

	Array<int>	assign_arr = int_arr;

	std::cout << "Print assign_arr" << std::endl;
	iter(assign_arr, print);

	assign_arr[2] = 42;
	assign_arr[4] = 21;

	int_arr[0] = 228;
	int_arr[3] = 25;

	std::cout << "Print assign_arr after editing" << std::endl;
	iter(assign_arr, print);

	std::cout << "Print int_arr after editing" << std::endl;
	iter(int_arr, print);

	Array<std::string>	str_arr(3);

	str_arr[0] = "convinient";
	str_arr[1] = "templates";
	str_arr[2] = "in C++";

	std::cout << "Print str_arr" << std::endl;
	iter(str_arr, print);
}
