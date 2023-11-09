#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2

typedef struct s_list
{
	char **args;
	int len;
	int pipes[2];
	int type;
	struct s_list *prev;
	struct s_list *next;
}	t_list;

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int show_error(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	return (1);
}

int exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(1);
	return (1);
}

void	*exit_fatal_ptr(void)
{
	exit_fatal();
	exit(1);
	return (NULL);
}

int list_rewind(t_list **list)
{
	while (*list && (*list)->prev)
		*list = (*list)->prev;
	return (0);
}

int list_clear(t_list **cmds)
{
	t_list *tmp;
	int i;
	list_rewind(cmds);
	while (*cmds)
	{
		tmp = (*cmds)->next;
		i = 0;
		while (i < (*cmds)->len)
			free((*cmds)->args[i++]);
		free((*cmds)->args);
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
	return (0);
}

char *ft_strdup(char *str)
{
	char *copy;
	int i = 0;

	if (!(copy = (char*)malloc(sizeof(*copy) * (ft_strlen(str)+ 1))))
		return (exit_fatal_ptr());
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int	add_arg(t_list *cmd, char *arg)
{
	char **tmp = NULL;
	int i = 0;

	if (!(tmp = (char**)malloc(sizeof(*tmp)*(cmd->len + 2))))
		return (exit_fatal());
	while (i < cmd->len)
	{
		tmp[i] = cmd->args[i];
		i++;
	}
	if (cmd->len > 0)
		free(cmd->args);
	cmd->args = tmp;
	cmd->args[i++] = ft_strdup(arg);
	cmd->args[i] = NULL;
	cmd->len++;
	return (0);
}

int	list_push(t_list **cmds, char *arg)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (exit_fatal());
	new->args = NULL;
	new->len = 0;
	new->type = TYPE_END;
	new->prev = NULL;
	new->next = NULL;
	if (*cmds)
	{
		(*cmds)->next = new;
		new->prev = *cmds;
	}
	*cmds = new;
	return (add_arg(new, arg));
	
}	

int parse_arg(t_list **cmds , char *arg)
{
	int is_break = (strcmp(";", arg) == 0);
	
	if (is_break && !*cmds)
		return (0);
	else if (!is_break && (!*cmds ||(*cmds)->type > TYPE_END))
		return (list_push(cmds, arg));
	else if (strcmp("|", arg) == 0)
		(*cmds)->type = TYPE_PIPE;
	else if (is_break)
		(*cmds)->type = TYPE_BREAK;
	else
		return (add_arg(*cmds, arg));
	return (0);
}

int exec_cmd(t_list *cmd, char **env)
{
	pid_t pid;
	int ret = 1;
	int status;
	int pipe_open = 0;

	if (cmd->type == TYPE_PIPE 
		|| (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return (exit_fatal());
	}
	pid = fork();
	if (pid < 0)
		return (exit_fatal());
	else if (pid == 0) 
	{
		if (cmd->type==TYPE_PIPE && dup2(cmd->pipes[1], 0)<0)
			return (exit_fatal());
		if (cmd->prev && cmd->prev->type == TYPE_PIPE
			&& dup2(cmd->prev->pipes[0], 1)< 0)
			return (exit_fatal());
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipes[1]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipes[0]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->pipes[0]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int	exec_cmds(t_list **cmds, char **env)
{
	t_list *crt;
	int ret = 0;

	list_rewind(cmds);
	while (*cmds)
	{
		crt = *cmds;
		if (strcmp("cd", crt->args[0]) == 0)
		{
			ret = 0;
			if (crt->len < 2)
				ret= show_error("error: cd: bad arguments\n");
			else if (chdir(crt->args[1]))
			{
				ret = show_error("error: cd: cannot char directory to ");
				show_error(crt->args[1]);
				show_error("\n");
			}
		}
		else 
			ret = exec_cmd(crt, env);
		if (!(*cmds)->next)
			break ;
		*cmds = (*cmds)->next;
	}
	return (ret);	
}

int main(int argc, char **argv, char **env)
{
	int ret = 0;
	int i = 1;
	t_list *cmds;

	cmds = (t_list*)malloc(sizeof(*cmds));
	cmds->args = NULL;
	cmds->type = 0;
	cmds->len = 0;
	cmds->prev = NULL;
	cmds->next = NULL;

	while (i < argc)
		parse_arg(&cmds, argv[i++]);
	if (cmds)
		ret = exec_cmds(&cmds, env);
	list_clear(&cmds);
	return (ret);
}
