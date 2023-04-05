/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:50:24 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 13:54:12 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int c);
int		ft_isascii(int c);
int		ft_strlen(const char *str);
int		ft_isprint(int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *str, int value, size_t size);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_bzero(void *s, size_t i);
int		ft_toupper(int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_tolower(int c);
char	*ft_strdup(const char *src);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t i);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *format, ...);
int		ft_strlen(const char *str);
int		ft_base(unsigned int nbr, const char *base);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr1(unsigned int n);
int		ft_putnbr(int nb);
int		ft_pointeur(unsigned long long p);
int		ft_strcmp(const char *s1, const char *s2);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));

#endif
