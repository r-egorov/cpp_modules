#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _fp_value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) : _fp_value(obj.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fp_value(value << Fixed::fract_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) 
	: _fp_value(std::roundf(value * (1 << Fixed::fract_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
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

int	Fixed::toInt(void) const
{
	return (this->_fp_value >> Fixed::fract_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fp_value / (float)(1 << Fixed::fract_bits));
}

std::ostream &	operator<<(std::ostream &o, Fixed const &obj)
{
	o << obj.toFloat();
	return (o);
}
