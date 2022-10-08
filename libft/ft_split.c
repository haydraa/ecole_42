#include "libft.h"

static int	ft_len_word(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
		    j = 0;
		s++;
	}
	return (i);
}

static char	*get_word(const char *s, int st, int f)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((f - st + 1) * sizeof(char));
	while (st < f)
		word[i++] = s[st++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	int	    i;
	int	    j;
	int		x;
	char	**dest;

	if (!s || !(dest = malloc((ft_len_word(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	x = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && x < 0)
			x = i;
		else if ((s[i] == c || i == ft_strlen(s)) && x >= 0)
		{
			dest[j++] = get_word(s, x, i);
			x = -1;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}
