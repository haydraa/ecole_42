/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:48:12 by jghribi           #+#    #+#             */
/*   Updated: 2022/12/20 15:48:14 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*len_args(int argc, char **argv)
{	
	int i;
	char *all;
	int x;
	int j;
	
	j = 0;
	i = 1;
	x = 0;
	if (argc == 1)
		return NULL;
	while (i < argc)
	{	
		x = x + ft_strlen(argv[i]);
		j++;
		i++; 
	}
	all = ft_calloc(sizeof(char), (x + argc));
	return all;
}

void put_in(char *dest, char *src, char space)
{
	int i;
	int len;

	len = ft_strlen((const char*) dest);
	i = 0;
	if (len > 0)
	{
		dest[len] = space;
		len++;
	}
	while (src[i])
	{
		dest[len] = src[i];
		len++;
		i++;
	}
}

char 	*join(int argc, char **argv)
{
	int i;
	char *all_args;
	
	i = 1;
	all_args = len_args(argc,argv);
	while (i <  argc)
	{
		put_in(all_args, argv[i], ' ');
		i++;
	}
	return all_args;
}

