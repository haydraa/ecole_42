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
/*void ft_display(t_node **top)
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
}*/

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
void ft_display(t_node **a)
{
	t_node	*temp;
	temp = *a;
	ft_printf("\n");
	while (temp)
	{
		ft_printf("%d ", temp->data);
		temp = temp->next;
	}
}

void get_min_max(int len,t_node **a, t_data *data)
{
		int i;
		t_node *temp;
		int pos1;
		int pos2;
		temp = *a;
		pos1 = find_big(a);
		pos2 = find_small(a,len);
		while (pos1--)
			temp = temp->next;
		data->max = temp->data;
		temp = *a;
		while (pos2--)
			temp = temp->next;
		data->min = temp->data;
}

void start(int len ,t_data *data)
{
	t_node **a;

	a = send_to_a(len, data);
	//change(a, len_node(a), len_node(a));
	get_min_max(len,a,data);
//	ft_printf("\n%d %d\n", data->min,data->max);
	to_algo(a, data);
	//ft_display(a);
	ft_free(data->all_final);
	free_node(a);
}

void display_tab(int len,char **tab)
{
		int i;
		i = 0;
		while (i < len)
		{
			ft_printf("%s ", tab[i]);
			i++;
		}
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
	//	display_tab(x,data.all_final);
		if (to_dob(data.all_final) == 0)
		{
				ft_putstr_fd("Error\n", 2);
				return 0;
		}
		start(x,&data);

		return 0;
}

