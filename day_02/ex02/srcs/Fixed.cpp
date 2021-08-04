#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
 * Constructors
*/

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

/*
 * Destructor
*/

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * Operators
*/

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fp_value = obj.getRawBits();
	return (*this);
}

/*
 * Arithmetic operators
*/

Fixed	Fixed::operator+(const Fixed &obj) const
{
	Fixed	res;
	res.setRawBits(this->_fp_value + obj.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &obj) const
{
	Fixed	res;
	res.setRawBits(this->_fp_value - obj.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &obj) const
{
	Fixed	res;
	long	value;

	
	value = (long)this->_fp_value * (long)obj.getRawBits()
		/ (1 << Fixed::fract_bits);
	res.setRawBits(value);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &obj) const
{
	Fixed	res;
	long	value;

	value = (long)this->_fp_value * (1 << Fixed::fract_bits)
		/ (long)obj.getRawBits();
	res.setRawBits(value);
	return (res);
}

/*
 * Increment, decrement operators
*/

Fixed	&Fixed::operator++(void) // Pre-increment
{
	this->_fp_value++;
	return (*this);
}

Fixed	Fixed::operator++(int) // Post-increment
{
	Fixed	tmp = *this;

	++*this;
	return (tmp);
}

Fixed	&Fixed::operator--(void) // Pre-decrement
{
	this->_fp_value--;
	return (*this);
}

Fixed	Fixed::operator--(int) // Post-decrement
{
	Fixed	tmp = *this;

	--*this;
	return (tmp);
}

/*
 * Comparison operators
*/

bool	Fixed::operator>(const Fixed &obj) const
{
	return (this->_fp_value > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed &obj) const
{
	return (this->_fp_value < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed &obj) const
{
	return (this->_fp_value >= obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return (this->_fp_value <= obj.getRawBits());
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return (this->_fp_value == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return (this->_fp_value != obj.getRawBits());
}

/*
 * Setters and getters
*/

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

/*
 * Representation methods
*/

int	Fixed::toInt(void) const
{
	return (this->_fp_value >> Fixed::fract_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fp_value / (float)(1 << Fixed::fract_bits));
}

/*
 * Send to an output stream
*/

std::ostream &	operator<<(std::ostream &o, Fixed const &obj)
{
	o << obj.toFloat();
	return (o);
}

/*
 * min, max methods
*/

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed	const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed	const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}
