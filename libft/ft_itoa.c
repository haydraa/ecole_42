# include "libft.h"

int len(long int nb)
{
	int i;

	i = 0;

	if (nb <= 0)
	{
		i = 1;
	}
	while (nb != 0)
	{
		i++;
		nb =nb / 10;
	}
	return i;
}
char *ft_itoa(int n)
{
	int d;
	char *dest;
	long int  nb;


	nb  = n;	
	d = len(nb);
	dest = malloc((d +1) * sizeof(char));
	if (dest == NULL)
		return NULL;
	dest[d--] = '\0';
	if (nb == 0)
	{
		dest[0] = 48;
		return (dest);
	}
	if (nb < 0)
	{
		dest[0] = '-';
		nb = nb * -1; 
	}
	while (nb > 0)
	{
		dest[d--] = 48 + (nb % 10);
		nb = nb / 10;
	}	
	return dest;
}
