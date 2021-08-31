#include "header.hpp"

int		main(void)
{
	Data	*d_ptr = new Data;

	d_ptr->s1 = "First string";
	d_ptr->s2 = "Second string";
	d_ptr->d = 42;

	std::cout
		<< "Data structure:\n"
		<< "addr =\t|" << d_ptr << "|\n"
		<< "s1 =\t|" << d_ptr->s1 << "|\n"
		<< "s2 =\t|" << d_ptr->s2 << "|\n"
		<< "d =\t|" << d_ptr->d << "|"
		<< std::endl;

	uintptr_t	int_ptr;

	int_ptr = serialize(d_ptr);

	std::cout
		<< "Serialized data:\n"
		<< "int_ptr = |" << int_ptr << "|" << std::endl;

	Data	*dd_ptr = deserialize(int_ptr);
	std::cout
		<< "Data structure:\n"
		<< "addr =\t|" << d_ptr << "|\n"
		<< "s1 =\t|" << dd_ptr->s1 << "|\n"
		<< "s2 =\t|" << dd_ptr->s2 << "|\n"
		<< "d =\t|" << dd_ptr->d << "|"
		<< std::endl;

	delete d_ptr;
}
