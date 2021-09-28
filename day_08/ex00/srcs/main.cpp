#include <easyfind.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	int	arr[10] = {-8, 0, 15, 43, 42, 33, -134, 33, 1223, 9};

	std::vector<int>	vec (arr, arr + sizeof(arr) / sizeof(int));
	std::list<int>		ls (arr, arr + sizeof(arr) / sizeof(int));
	std::deque<int>		deq (arr, arr + sizeof(arr) / sizeof(int));

	std::cout << "vector = ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	std::cout << "list = ";
	for (std::list<int>::iterator it = ls.begin(); it != ls.end(); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	std::cout << "deque = ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	std::cout << "[Testing easyfind]\n" << std::endl;
	std::cout << "easyfind(vec, 33) = " << *easyfind(vec, 33) << std::endl;
	std::cout << "Previous: " << *(--easyfind(vec, 33)) << "\n" << std::endl;
	std::cout << "easyfind(ls, 33) = " << *easyfind(ls, 33) << std::endl;
	std::cout << "Previous: " << *(--easyfind(ls, 33)) << "\n" << std::endl;
	std::cout << "easyfind(deq, 33) = " << *easyfind(deq, 33) << std::endl;
	std::cout << "Previous: " << *(--easyfind(deq, 33)) << "\n" << std::endl;

	std::cout << "easyfind(vec, -8) = " << *easyfind(vec, -8) << std::endl;
	std::cout << "Next: " << *(++easyfind(vec, -8)) << "\n" << std::endl;
	std::cout << "easyfind(ls, -8) = " << *easyfind(ls, -8) << std::endl;
	std::cout << "Next: " << *(++easyfind(ls, -8)) << "\n" << std::endl;
	std::cout << "easyfind(deq, -8) = " << *easyfind(deq, -8) << std::endl;
	std::cout << "Next: " << *(++easyfind(deq, -8)) << "\n" << std::endl;

	std::cout << "easyfind(vec, 9) = " << *easyfind(vec, 9) << std::endl;
	std::cout << "Previous: " << *(--easyfind(vec, 9)) << "\n" << std::endl;
	std::cout << "easyfind(ls, 9) = " << *easyfind(ls, 9) << std::endl;
	std::cout << "Previous: " << *(--easyfind(ls, 9)) << "\n" << std::endl;
	std::cout << "easyfind(deq, 9) = " << *easyfind(deq, 9) << std::endl;
	std::cout << "Previous: " << *(--easyfind(deq, 9)) << "\n" << std::endl;

	std::cout << "[Testing exception]\n" << std::endl;

	try
	{
		std::cout << "easyfind(vec, 12345678);" << std::endl;
		easyfind(vec, 12345678);
	}
	catch (NotFoundException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
