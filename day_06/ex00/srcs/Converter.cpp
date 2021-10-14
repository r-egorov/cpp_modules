#include "Converter.hpp"

Converter::Converter(void) {}

Converter::~Converter(void) {}

Converter::Converter(Converter const &obj)
{
	Converter const	*p;
	p = &obj;
}

Converter		&Converter::operator = (Converter const &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

const char		*Converter::WrongSignException::what(void) const throw()
{
	return ("Wrong sign placement");
}

const char		*Converter::WrongDotException::what(void) const throw()
{
	return ("Wrong dot placement");
}

const char		*Converter::MoreThanOneDotException::what(void) const throw()
{
	return ("More than one dot in the literal");
}

const char		*Converter::WrongLiteralException::what(void) const throw()
{
	return ("Invalid symbols in the literal");
}

void			Converter::parse(const char *to_be_parsed)
{
	std::string		s(to_be_parsed);

	if (s == "inf" || s == "+inf" || s == "inff" || s == "+inff")
		this->infPos = true;
	else if (s == "-inf" || s == "-inff")
		this->infNeg = true;
	else if (s == "nan" || s == "nanf")
		this->nan = true;
	else
	{
		std::string::iterator	it;
		it = s.begin();

	   	// Checking for invalid symbols

		while (it != s.end())
		{
			if (!(*it > '0' && *it < '9') && (*it != 'f')
					&& (*it != '-') && (*it != '+') && (*it != '.'))
				throw WrongLiteralException();
			it++;
		}

		// Checking for double '+' or '-'

		if ((s.find('-') != std::string::npos && s.rfind('-') != 0)
				|| (s.find('+') != std::string::npos && s.rfind('+') != 0))
			throw WrongSignException();

		std::string::size_type	dot = s.find('.');

		if (dot == 0 || dot == s.length() - 1)
		{
			throw WrongDotException();
		}
		if (dot != 0)
		{
			if (s.rfind('.') != dot)
			{
				throw MoreThanOneDotException();
			}
		}
	}
}

void			Converter::toChar(void)
{
	std::cout << "char: ";
	if ((this->infPos || this->infNeg || this->nan)
		|| (this->dvalue < 0 || this->dvalue > 127))
	{
		std::cout << "impossible" << std::endl;
	}
	else if (this->dvalue < 32 || this->dvalue == 127)
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		char	c = static_cast<char>(this->dvalue);
		std::cout << "\'" << c << "\'" << std::endl;
	}
}

void			Converter::toInt(void)
{
	std::cout << "int: ";

	long		lValue = static_cast<long>(this->dvalue);

	if ((this->infPos || this->infNeg || this->nan)
		|| (lValue < std::numeric_limits<int>::min()
			|| lValue > std::numeric_limits<int>::max()))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		int		iValue = static_cast<int>(this->dvalue);
		std::cout << iValue << std::endl;
	}
}

void			Converter::toFloat(void)
{
	std::cout  << "float: ";

	if (this->infPos)
	{
		std::cout << "inf";
	}
	else if (this->infNeg)
	{
		std::cout << "-inf";
	}
	else if (this->nan)
	{
		std::cout << "nan";
	}
	else
	{
		float	fValue = static_cast<float>(this->dvalue);
		std::cout << std::fixed << std::setprecision(1) << fValue;
	}
	std::cout << "f" << std::endl;
}

void			Converter::toDouble(void)
{
	std::cout  << "double: " << std::fixed << std::setprecision(1) << this->dvalue << std::endl;
}

void			Converter::convert(const char *s)
{
	try
	{
		this->parse(s);
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		return ;
	}

	try
	{
		this->dvalue = std::atof(s);
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "ERROR: Invalid argument" << std::endl;
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "ERROR: Argument out of range" << std::endl;
		return ;
	}

	this->toChar();
	this->toInt();
	this->toFloat();
	this->toDouble();
}
