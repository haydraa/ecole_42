/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:13:44 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/26 16:51:09 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
char *ft_strrchr(const char *str, int c);
int ft_isascii(int c);
int ft_strlen(const char *str);
int ft_isprint(int c);
char *ft_strjoin(char *s1, char *s2);
void *ft_memset(void *str, int value, unsigned int size);
void *ft_memchr(const void *str, int c, size_t n);
void *ft_bzero(void *s, unsigned int i);
int ft_toupper(int c);
void *ft_memmove(void *dest ,const void *src, size_t n);
int ft_tolower(int c);
char *ft_strdup(const char *src);
int	ft_memcmp(const void *str1, const void *str2, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t i);
size_t ft_strlcat(char *dest,const char *src, size_t n);
char *ft_strtrim(char const *s1, char const *set);
char *ft_strchr(const char *str, int c);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
int ft_atoi(const char *nptr);
void *ft_calloc(size_t nmemb, size_t size);



#endif

