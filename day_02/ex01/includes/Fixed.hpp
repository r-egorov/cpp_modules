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
		
		Fixed &operator=(const Fixed &obj);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream &	operator<<(std::ostream &o, Fixed const &obj);

#endif
