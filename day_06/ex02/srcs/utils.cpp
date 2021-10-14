#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>

enum	Classes
{
	CLASS_A,
	CLASS_B,
	CLASS_C
};

Base	*generate(void)
{
	unsigned int	seed;
	int				coin;

	seed = time(0);
	srand(seed);
	coin = rand() % 3;

	std::cout << "[Generator]: ";
	switch (coin)
	{
		case CLASS_A:
		{
			std::cout << "Generated class A" << std::endl;
			return (new A());
		}
		case CLASS_B:
		{
			std::cout << "Generated class B" << std::endl;
			return (new B());
		}
		case CLASS_C:
		{
			std::cout << "Generated class C" << std::endl;
			return (new C());
		}
	}
	return (nullptr);
}

void	identify(Base *p)
{
	std::cout << "[Identifier(ptr)]: ";
	A	*a_ptr = dynamic_cast<A *>(p);
	if (a_ptr)
	{
		std::cout << "A" << std::endl;
		return ;
	}

	B	*b_ptr = dynamic_cast<B *>(p);
	if (b_ptr)
	{
		std::cout << "B" << std::endl;
		return ;
	}

	C	*c_ptr = dynamic_cast<C *>(p);
	if (c_ptr)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	std::cout << "[Identifier(rfr)]: ";
	try
	{
		A	&a_ref = dynamic_cast<A &>(p);
		(void)a_ref;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast &e) {}

	try
	{
		B	&b_ref = dynamic_cast<B &>(p);
		(void)b_ref;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast &e) {}

	try
	{
		C	&c_ref = dynamic_cast<C &>(p);
		(void)c_ref;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast &e) {}
}
