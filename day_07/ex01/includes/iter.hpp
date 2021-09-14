#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *arr, size_t size, void (*func)(T const &))
{
	for (size_t i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void	print(T const &obj)
{
	std::cout << obj << std::endl;
}

#endif
