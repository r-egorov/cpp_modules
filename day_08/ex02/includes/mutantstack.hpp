#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template< typename T >
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack &obj) : std::stack<T>(obj) {}
		virtual ~MutantStack(void) {}

		MutantStack	&operator = (const MutantStack &obj)
		{
			if (this == &obj)
				return (*this);
			std::stack<T>::operator=(obj);
			return(*this);
		}
		
		iterator	begin(void)
		{
			return (std::stack<T>::c.begin());
		}

		iterator	end(void)
		{
			return (std::stack<T>::c.end());
		}

		const_iterator	cbegin(void)
		{
			return (std::stack<T>::c.cbegin());
		}

		const_iterator	cend(void)
		{
			return (std::stack<T>::c.cend());
		}

		reverse_iterator	rbegin(void)
		{
			return (std::stack<T>::c.rbegin());
		}

		reverse_iterator	rend(void)
		{
			return (std::stack<T>::c.rend());
		}

		const_reverse_iterator	crbegin(void)
		{
			return (std::stack<T>::c.crbegin());
		}

		const_iterator	crend(void)
		{
			return (std::stack<T>::c.crend());
		}
};

#endif
