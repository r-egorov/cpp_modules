#include "Span.hpp"
#include <iostream>

int	main(void)
{
	Span	sp(5);

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::NotAbleToSpan &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	sp.addNumber(-5);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (Span::NotAbleToSpan &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	sp.addNumber(10);
	sp.addNumber(600);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	sp.addNumber(35);
	sp.addNumber(-2344);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span	sp_copy(sp);
	try
	{
		sp_copy.addNumber(56);
	}
	catch (Span::FullException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << sp_copy.shortestSpan() << std::endl;
	std::cout << sp_copy.longestSpan() << std::endl;

	Span	range_test(10);

	try
	{
		range_test.addNumber(1, 1000);
	}
	catch (Span::NotEnoughSpace &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		range_test.addNumber(10, 1);
	}
	catch (Span::NotValidRange &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	range_test.addNumber(1, 10);

	std::cout << range_test.shortestSpan() << std::endl;
	std::cout << range_test.longestSpan() << std::endl;

	Span	huge(10000);

	huge.addNumber(-5000, 5000);

	std::cout << huge.shortestSpan() << std::endl;
	std::cout << huge.longestSpan() << std::endl;

	return (0);
}
