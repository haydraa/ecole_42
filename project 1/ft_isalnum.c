/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:33:11 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/26 16:59:21 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) == 0) || (ft_isdigit(c) == 0))
		return 0;
	return 1;
}
