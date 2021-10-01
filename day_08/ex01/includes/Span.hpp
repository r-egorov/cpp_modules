#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int		capacity;
		std::vector<int>	nums;
		bool			sorted;
		int			*shortest;
		int			*longest;

		void	sort(void);
		bool	canSpan(void);

	public:
		Span(void);
		Span(unsigned int capacity);
		Span(Span const &obj);
		virtual ~Span(void);

		Span	&operator=(Span const &obj);

		void	addNumber(int num);
		int	shortestSpan(void);
		int	longestSpan(void);

		template<class Iterator>
		void	addNumber(Iterator begin, Iterator end)
		{
			unsigned int	freeSpace;

			freeSpace = this->capacity
				- static_cast<unsigned int>(this->nums.size());

			if (end < begin)
				throw NotValidRange();
			if (freeSpace < static_cast<unsigned int>(end - begin))
				throw NotEnoughSpace();
			else
			{
				for ( ; begin != end; begin++)
				{
					this->addNumber(begin);
				}
			}
		}

		class FullException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class NotAbleToSpan : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		
		class NotEnoughSpace : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class NotValidRange : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif
