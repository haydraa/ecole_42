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

#endif

