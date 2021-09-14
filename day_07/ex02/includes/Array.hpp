#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array
{
	private:
		T		*arr;
		size_t	_size;
	public:
		Array() : arr(new T[0]()), _size(0) {}
		Array(unsigned int n) : arr(new T[n]()), _size(n) {}

		Array(Array const &obj) : arr(new T[obj.size()]()), _size(obj.size())
		{
			for (size_t i = 0; i < this->_size; i++)
			{
				arr[i] = obj.arr[i];
			}
		}

		virtual ~Array(void)
		{
			delete [] (this->arr);
		}

		Array	&operator = (Array const &obj)
		{
			if (this->arr)
				delete [] (this->arr);
			this->arr = new T[obj.size()]();
			this->_size = obj.size();

			for (size_t i = 0; i < this->_size; i++)
			{
				arr[i] = obj.arr[i];
			}
		}

		T		&operator[] (const int index)
		{
			if ((index < 0) || (index > static_cast<int>(_size)))
				throw OutOfLimitsException();
			return (this->arr[index]);
		}

		size_t	size(void) const
		{
			return (this->_size);
		}

		class OutOfLimitsException : public std::exception
		{
			const char	*what(void) const throw()
			{
				return ("Out of limits");
			}
		};
};

template <typename T>
void	iter(Array<T> &arr, void (*func)(T const &))
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void	print(T const &obj)
{
	std::cout << obj << std::endl;
}

#endif
