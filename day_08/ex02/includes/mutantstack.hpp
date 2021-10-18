#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

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

template< typename T >
void	print_mstack(MutantStack<T> mstack, const char *stack_name)
{
	typename MutantStack< T >::iterator	it = mstack.begin();

	std::cout << "===============\n" << stack_name << std::endl;

	for (; it != mstack.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "===============" << std::endl;
}

template< typename T >
void	rprint_mstack(MutantStack<T> mstack, const char *stack_name)
{
	typename MutantStack< T >::reverse_iterator	it = mstack.rbegin();

	std::cout << "===============\n" << stack_name << std::endl;

	for (; it != mstack.rend(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "===============" << std::endl;
}

#endif
