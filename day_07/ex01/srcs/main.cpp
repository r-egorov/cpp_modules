#include "iter.hpp"

int		main(void)
{
	int	int_arr[5] = {42, 21, 256, -1, 0};

	std::cout << "INT ARR" << std::endl;
	iter(int_arr, 5, print);

	float float_arr[4] = {1.05f, 3.14f, 28.3f, -1.1f};
	std::cout << "FLOAT ARR" << std::endl;
	iter(float_arr, 4, print);
}
