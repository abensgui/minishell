/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:59:52 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/04 19:19:43 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_param(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j++] == '-' && argv[i][j] == 'n')
		{
			while (argv[i][j] == 'n')
				j++;
			if (argv[i][j] != 'n' && argv[i][j])
				return (i);
		}
		else
			return (i);
	}
	return (i);
}

static int	check_first_param(char *param)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (param[i] == '-' && param[i + j] == 'n')
	{
		while (param[i + j] == 'n')
			j++;
		if (param[i + j] != 'n' && param[i + j] != '\0')
			return (0);
		else if (param[i + j] != 'n' && param[i + j] == '\0')
			return (1);
	}
	return (0);
}

void	command_echo(t_data *data)
{
	int	param;

	if (!data->cmd[1])
		printf("\n");
	else
	{
		param = check_param(data->cmd);
		while (data->cmd[param])
		{
			printf("%s", data->cmd[param]);
			if (data->cmd[param + 1])
				printf(" ");
			param++;
		}
		if (check_first_param(data->cmd[1]) != 1)
			printf("\n");
	}
	g_global.exit_status = 0;
}
