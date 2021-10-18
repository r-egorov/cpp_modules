#include "Span.hpp"
#include <iostream>

Span::Span(void) :
	capacity(0), sorted(true), shortest(0), longest(0) {}

Span::Span(unsigned int capacity) :
	capacity(capacity), sorted(true), shortest(0), longest(0) {}

Span::Span(Span const &obj) :
	capacity(obj.capacity), nums(obj.nums), sorted(obj.sorted),
	shortest(0), longest(0)
{
	if (obj.shortest)
		this->shortest = new int(*(obj.shortest));
	if (obj.longest)
		this->longest = new int(*(obj.longest));
}

Span::~Span(void)
{
	if (this->shortest)
		delete this->shortest;
	if (this->longest)
		delete this->longest;
}

Span	&Span::operator = (Span const &obj)
{
	if (this == &obj)
		return (*this);

	this->capacity = obj.capacity;
	this->nums = obj.nums;
	if (obj.shortest)
		this->shortest = new int(*(obj.shortest));
	if (obj.longest)
		this->longest = new int(*(obj.longest));
	return (*this);
}

void	Span::addNumber(int num)
{
	if (static_cast<unsigned int>(this->nums.size()) < this->capacity)
	{
		this->nums.push_back(num);
		this->sorted = false;
	}
	else
	{
		throw FullException();
	}
}

void	Span::sort(void)
{
	std::sort(this->nums.begin(), this->nums.end());
	if (this->shortest)
	{
		delete this->shortest;
		this->shortest = nullptr;
	}
	if (this->longest)
	{
		delete this->longest;
		this->longest = nullptr;
	}
	this->sorted = true;
}

bool 	Span::canSpan(void)
{
	if (this->nums.size() <= 1)
		return (false);

	if (!this->sorted)
		this->sort();

	return (true);
}

int	Span::shortestSpan(void)
{
	int	result;

	if (this->sorted && this->shortest)
		return (*this->shortest);

	if (!this->canSpan())
		throw NotAbleToSpan();

	result = this->nums[1] - this->nums[0];
	for (int i = 1; i < static_cast<int>(this->nums.size()); ++i)
	{
		int	tmp_result;
		tmp_result = this->nums[i] - this->nums[i - 1];
		if (tmp_result < result)
			result = tmp_result;
	}

	if (this->shortest)
		delete this->shortest;
	this->shortest = new int(result);

	return (result);
}

int	Span::longestSpan(void)
{
	int	result;

	if (this->sorted && this->longest)
		return (*this->longest);

	if (!this->canSpan())
		throw NotAbleToSpan();

	result = this->nums[static_cast<int>(this->nums.size()) - 1]
		- this->nums[0];

	if (this->longest)
		delete this->longest;
	this->longest = new int(result);

	return (result);
}

const char	*Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char	*Span::NotAbleToSpan::what() const throw()
{
	return ("There is not enough elements to span");
}

const char	*Span::NotEnoughSpace::what() const throw()
{
	return ("Not enough space in the span");
}

const char	*Span::NotValidRange::what() const throw()
{
	return ("Range is not valid");
}
