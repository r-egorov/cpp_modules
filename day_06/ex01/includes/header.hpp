#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>


typedef struct	s_data
{
	std::string	s1;
	std::string	s2;
	int			d;
}				Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
