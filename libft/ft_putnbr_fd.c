
# include "libft.h"

void ft_putnbr_fd(int n, int fd)
{

	if (n < 0)
	{
		ft_putchar_fd('-',fd);
		n = (long)(n * -1);
	}
	if (n >= 10)
		ft_putnbr_fd((n / 10),fd);
	ft_putchar_fd(((char)(n % 10) + 48),fd);
}
