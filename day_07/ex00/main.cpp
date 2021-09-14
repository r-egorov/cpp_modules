#include "templates.hpp"
#include <iostream>
#include <string>

int		main(void)
{
	{
		int		a = 42;
		int		b = 21;
	
	
		std::cout << "a = " << a << ", b = " << b << std::endl;
		swap(a, b);
		std::cout << "[AFTER SWAP]\n"
			<< "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	
		std::string	s1 = "one";
		std::string	s2 = "two";
		std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
		swap(s1, s2);
		std::cout << "[AFTER SWAP]\n"
			<< "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	}
	{
		int a = 2;
		int b = 3;
	
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}
