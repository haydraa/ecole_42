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

# ifndef LBIFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_strlen(char *str);
int ft_isprint(int c);
void *ft_memset(void *str, int value, unsigned int size);
void *ft_memchr(const void *str, int c, unsigned int n);
void *ft_bzero(void *s, unsigned int i);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_memcmp(const void *str, const void *str2, int n);
void *ft_memcpy(void *dest, void *src, int i);
char *ft_strchr(char *str, int c);
unsigned int ft_strlcpy(char *dest, char *src, int size);


#endif

