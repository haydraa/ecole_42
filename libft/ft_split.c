# include "libft.h"

int get_word(char const *s, char c)
{
	int i;
	int j;

	
	if (!(s[0]))
		return 0;
	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			j++;
			while (s[i] && s[i] == c)
				i++;
		}
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return j;
}
char *word_calloc(const char *s, int s, int f)
{
	char *dest;
	int i;
	int j;

	j = f - s + 1;
	i = 0;
	dest = ft_calloc(j,sizeof(char));
	while(s < f)
	{
		word[i++] = s[s++];
	}
	word[i] = '\0';
	return word;

}


char **ft_split(char const *s, char c)
{
	int y;
	int x;
	int i;
	char **dest;
	
	if (s == NULL)
		return NULL;
	i = 0;
	y = 0;
	if (s[y] == '\0')
		return NULL;
	dest = (char**)malloc(sizeof(char) * get_word(s,c) + 1);
	if (dest == NULL)
		return NULL;
	while (s[y] && s[y] == c)
		y++;
	while (y <= ft_strlen(s))
	{
		x = 0;
		while (s[y + x] != '\0' && s[y + x] != c)
			x++;
		dest[i] = (char*)malloc(sizeof(char)*(x + 1));
		ft_strlcpy(dest[i],(s+y),x+1);
		i++;
		y = y + x;
		y++;
	}
	dest[i] = NULL;
	return (dest);
}
