#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <class T>
class Array
{
	private:
		T* array;
		unsigned int Size;
	public:
		Array(void):Size(0), array(new T[0])
		{
			std::cout << "Constructor For Default Called" << 
					std::endl; 
		}

		Array(unsigned int n): array(new T[n]), Size(n)
		{
			std::cout << "Constructor Called" << std::endl;
		}

		Array(const Array &init)
		{
			this->Size = init.Size;
			this->array = new T[init.Size];
			for (unsigned int i = 0; i < init.Size; i++)
				this->array[i] = init.array[i];
		}

		~Array(void)
		{
			delete [] this->array;
			std::cout << "Destructor called" << std::endl;
		}
		
		void	GetArray(void)
		{
			for (unsigned int i = 0 ; i < Size; i++)
				std::cout << this->array[i] << std::endl;
		}

		Array &operator=(const Array &init)
		{
			if (this != &init)
			{
				this->~Array();
				this->Size = init.Size;
				this->array = new T[init.Size];
				for (unsigned int i = 0; i < init.Size; i++)
					this->array[i] = init.array[i];
			}
			return (*this);
		}

		T& 	operator[](unsigned int index)
		{
			if (index >= this->Size)
				throw OutOfRange();
			return this->array[index];
		}

		class OutOfRange : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Out of Range\n");
				}
		};
};

#endif
