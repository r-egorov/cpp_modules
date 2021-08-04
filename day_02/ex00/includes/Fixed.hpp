#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int			_fp_value;
		static const int	fract_bits = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif
