#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <stdlib.h>
# include <string>
# include <iostream>
# include <iomanip>
# include <limits>

class Converter
{
	/*
	private:
		char	c;
		int		i;
		float	f;
		double	d;
		*/

	private:
		double	dvalue;
		bool	infPos;
		bool	infNeg;
		bool	nan;
	public:
		Converter(void);
		Converter(Converter const &obj);
		~Converter(void);

		Converter		&operator = (Converter const &obj);

		void			parse(const char *s);
		void			convert(const char *s);
		void			toChar(void);
		void			toInt(void);
		void			toFloat(void);
		void			toDouble(void);

		class WrongSignException : public std::exception
		{
			const char	*what(void) const throw();
		};

		class WrongDotException : public std::exception
		{
			const char	*what(void) const throw();
		};

		class MoreThanOneDotException : public std::exception
		{
			const char	*what(void) const throw();
		};
};
#endif
