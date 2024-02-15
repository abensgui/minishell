/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:58:29 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 02:53:47 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_list(void)
{
	t_env	*tmp;

	tmp = g_global.env_list;
	while (tmp)
	{
		if (tmp->value && tmp->key)
		{
			printf("%s=\"%s\"\n", tmp->key, tmp->value);
		}
		tmp = tmp->next;
	}
}

static void	ft_execute_builtins(t_data *data)
{
	if (ft_strcmp(data->cmd[0], "echo") == 0
		|| ft_strcmp(data->cmd[0], "/bin/echo") == 0)
		command_echo(data);
	else if (ft_strcmp(data->cmd[0], "cd") == 0
		|| ft_strcmp(data->cmd[0], "/usr/bin/cd") == 0)
	{
		if (command_cd(data->cmd[1]) == -1)
		{
			write(2, "minishell: cd: ", 15);
			write(2, data->cmd[1], ft_strlen(data->cmd[1]));
			write(2, " :No such file or directory\n", 28);
		}
	}
	else if (ft_strcmp(data->cmd[0], "pwd") == 0
		|| ft_strcmp(data->cmd[0], "/bin/pwd") == 0)
		command_pwd();
	else if (ft_strcmp(data->cmd[0], "export") == 0)
		command_export(data);
	else if (ft_strcmp(data->cmd[0], "env") == 0
		|| ft_strcmp(data->cmd[0], "/usr/bin/env") == 0)
		print_list();
	else if (ft_strcmp(data->cmd[0], "unset") == 0)
		command_unset(data);
	else if (ft_strcmp(data->cmd[0], "exit") == 0)
		command_exit(data);
}

int	ft_builtins(t_data *data)
{
	if (!data->cmd)
		return (0);
	else
	{
		if (ft_strcmp(data->cmd[0], "echo") == 0
			|| ft_strcmp(data->cmd[0], "/bin/echo") == 0
			|| ft_strcmp(data->cmd[0], "cd") == 0
			|| ft_strcmp(data->cmd[0], "/usr/bin/cd") == 0
			|| ft_strcmp(data->cmd[0], "pwd") == 0
			|| ft_strcmp(data->cmd[0], "/bin/pwd") == 0
			|| ft_strcmp(data->cmd[0], "export") == 0
			|| ft_strcmp(data->cmd[0], "env") == 0
			|| ft_strcmp(data->cmd[0], "/usr/bin/env") == 0
			|| ft_strcmp(data->cmd[0], "unset") == 0
			|| ft_strcmp(data->cmd[0], "exit") == 0)
			ft_execute_builtins(data);
		else
			return (0);
	}
	return (1);
}
