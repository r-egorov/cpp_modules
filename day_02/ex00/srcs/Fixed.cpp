#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fp_value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) : _fp_value(obj.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fp_value = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}
