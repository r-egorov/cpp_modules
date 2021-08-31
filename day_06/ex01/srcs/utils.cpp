#include "header.hpp"

uintptr_t		serialize(Data *d_ptr)
{
	uintptr_t	ptr;

	ptr = reinterpret_cast<uintptr_t>(d_ptr);
	return (ptr);
}

Data*			deserialize(uintptr_t raw)
{
	Data		*d_ptr;

	d_ptr = reinterpret_cast<Data *>(raw);
	return (d_ptr);
}
