#ifndef P_I_P_E_X_H
#define P_I_P_E_X_H


#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
typedef struct s_data
{
	pid_t  pip1;
	pid_t	pip2;
	int file1;
	int file2;
	char *cmd1;
	char *cmd2;
	char *path;
	char **path_tab;

} t_data;
#endif
