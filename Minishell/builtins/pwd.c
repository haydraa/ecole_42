
#include "../minishell.h"

/* handle_pwd function outputs the current working directory
 *
 * @data: structure that holds shell data
 */
void handle_pwd(t_data *data)
{
	// output the content of pwd field in data structure
	ft_putstr(data->pwd);
	ft_putstr("\n");

	// set global status to indicate success
	//g_status = 0;
}
