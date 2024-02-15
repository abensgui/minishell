/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:07:33 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 00:47:18 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_number(char *s)
{
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] > 32 && s[i])
	{
		if (ft_isdigit(s[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

static void	command_exit_second(t_data *data)
{
	if (ft_atoi(data->cmd[1]) == -1 || ft_number(data->cmd[1]) != 1)
	{
		write(2, "exit\n", 6);
		write(2, "minishel: exit: ", 17);
		write(2, data->cmd[1], strlen(data->cmd[1]));
		write(2, " :numeric argument required\n", 29);
		g_global.exit_status = 255;
		exit(255);
	}
	else
	{
		write(2, "exit\n", 6);
		write(2, "minishel: exit: ", 17);
		write(2, "too many arguments\n", 20);
		g_global.exit_status = 1;
	}
}

static int	ft_commd_size(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}	

static void	print_err(char *s)
{
	write(2, "exit: ", 7);
	write(2, s, strlen(s));
	write(2, " :numeric argument required\n", 29);
}

void	command_exit(t_data *data)
{
	if (!data->cmd[1])
	{
		printf("exit\n");
		exit(g_global.exit_status);
	}
	else
	{
		if ((ft_atoi(data->cmd[1]) == -1 || ft_number(data->cmd[1]) != 1)
			&& !data->cmd[2])
		{
			print_err(data->cmd[1]);
			g_global.exit_status = 255;
			exit(255);
		}
		else if (ft_atoi(data->cmd[1]) != -1
			&& !data->cmd[2] && ft_number(data->cmd[1]) == 1)
		{
			printf("exit\n");
			exit(g_global.exit_status);
		}
		else if (ft_commd_size(data->cmd) > 1)
			command_exit_second(data);
		if (g_global.exit_status == 255)
			exit(255);
	}
}
