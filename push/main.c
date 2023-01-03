# include "push_swap.h"

void ft_free(char **tab)
{
		int i;
		int j;

		i = 0;
		j = 0;
		while (tab[i])
					i++;
		while (j < i)
		{
			free(tab[j]);
			j++;
		}
		free(tab);
}

void free_node(t_node **a)
{
		t_node *temp;
		t_node *hold;
		
		temp = *a;
		while (temp)
		{
				hold = temp;
				temp = temp->next;
				free(hold);
		}
		free(a);
}
void ft_display(t_node **top)
{
		t_node	*temp;

		temp = *top;
		while (temp->next != NULL)
		{
				ft_printf("%d\n", temp->data);
				temp = temp->next;
		}
		while (temp)
		{
				ft_printf("%d\n", temp->data);
				temp = temp->prev;
		}
}

int	len_node(t_node **list)
{
	int	i;
	t_node *temp;

	i = 0;
	temp = *list;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

void start(int len ,t_data *data)
{
	t_node **a;

	a = send_to_a(len, data);
	change(a, len_node(a), len_node(a));
//	ft_display(a);
	to_algo(a);
	ft_free(data->all_final);
	free_node(a);
}

int main(int argc,char **argv)
{
		t_data data;
		int x;

		x = 0;
		if (argc == 1)
				return 0;	
		data.final = join(argc,argv);
		data.final_trim = ft_strtrim(data.final, " ");
		free(data.final);
		if (ft_check_arg(data.final_trim) == 0)
		{
				ft_putstr_fd("Error\n", 2);
				return 0;
		}
		data.all_final = ft_split(data.final_trim, ' ');
		free(data.final_trim);
		while(data.all_final[x])
				x++;
		if (to_dob(data.all_final) == 0)
		{
				ft_putstr_fd("Error\n", 2);
				return 0;
		}
		start(x,&data);

		return 0;
}

