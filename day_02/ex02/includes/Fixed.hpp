#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int			_fp_value;
		static const int	fract_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed(const int value);
		Fixed(const float value);

		~Fixed(void);
		
		Fixed	&operator=(const Fixed &obj);

		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;

		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
		static	Fixed &min(Fixed &lhs, Fixed &rhs);
		static	Fixed &max(Fixed &lhs, Fixed &rhs);
		const static	Fixed &min(const Fixed &lhs, const Fixed &rhs);
		const static	Fixed &max(const Fixed &lhs, const Fixed &rhs);
};

std::ostream &	operator<<(std::ostream &o, Fixed const &obj);

#endif
