#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class		NotFoundException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Value not found");
		}
};

template<typename T>
typename T::iterator	easyfind(T &cont, int value)
{
	typename T::iterator	res;

	if ((res = find(cont.begin(), cont.end(), value)) != cont.end())
		return (res);
	else
		throw NotFoundException();
}

#endif
