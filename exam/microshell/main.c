#include <stdlib.h>
#include <unistd.h>
#include <string.h>



int	add_arg(t_list *cmd, char *arg)
{
	char **tmp;
	int i;

	i = 0;
	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(char *) * (cmd->lenth +  2))))
		return (exit_fatal());
	while (i < cmd->length)
	{
		tmp[i] = cmd->args[i];
		i++;
	}
	if (cmd->length > 0)
		free(cmd->args);
	cmd->args = tmp;
	cmd->arg[i++] = ft_strdup(arg);
	cmd->arg[i] = 0;
	cmd->length++;
	return (EXIT_SUCCESS);
}

int	list_push(t_list **cmds, char *arg)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (exit_fatal());
	new->args = NULL;
	new->length = 0;
	new->type = 0;
	new->previous = NULL:
	new->next = NULL;
	if (*list)
	{
		(*list)->next = new;
		new->previous = *list;
	}
	*list = new;
	return (add_arg(new, arg));
}

int	pars_arg(t_list **cmd, char *arg)
{
	int	is_break;

	is_break = (strcmp(";", arg) == 0);
	if (is_break && !*cmds)
			return (EXIT_SUCCESS);
	else if (!is_break && (!*cmd || (*cmd)->type > 0))
		return (list_push(cmds, arg));
}

int	main(int argc, char **argc)
{
	t_list *cmds;
	int i;
	int ret;

	ret = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (i < argc)
			pars_arg(&cmd, argv[i++]);
}
