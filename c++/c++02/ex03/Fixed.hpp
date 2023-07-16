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

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		
		
		Fixed operator+(const Fixed& other)const;
		Fixed operator-(const Fixed& other)const;
		Fixed operator*(const Fixed& other)const;
		Fixed operator/(const Fixed& other)const;
		
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);


		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static const Fixed& max(Fixed& a, Fixed& b);

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out ,const Fixed& in);

#endif
