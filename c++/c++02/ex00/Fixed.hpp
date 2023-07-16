#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class	Fixed
{
	private :
		int	value;
		static const int fractional_bit = 8;

	public :
		Fixed(void);
		Fixed(const Fixed& init);
		~Fixed(void);
		Fixed& operator=(const Fixed& init2);		
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
