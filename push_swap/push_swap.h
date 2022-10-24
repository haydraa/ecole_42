
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft.h"

typedef struct s_list
{
		void			*data;
		struct s_list	*next;
}						t_list;

void	ft_creat_stack(int  value);
int		check_arg(char *data);

#endif
