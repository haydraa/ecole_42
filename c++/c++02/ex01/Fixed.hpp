#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private :
		int	value;
		static const int fractional_bit = 8;

	public :
		Fixed(void);
		Fixed(const int intger);
		Fixed(const float Float);
		Fixed(const Fixed& init);
		~Fixed(void);

		Fixed& operator=(const Fixed& init2);		
		
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out ,const Fixed& in);

#endif
