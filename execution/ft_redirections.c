/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:39:44 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/06 19:22:20 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

static int	error_open(int i, t_file *tmp)
{
	g_global.fd[i][1] = open (tmp->name, O_RDONLY);
	if (g_global.fd[i][1] == -1)
	{
		write(2, "Error\n", 7);
		g_global.exit_status = 1;
		return (-1);
	}
	return (0);
}

static int	open_outfile(t_file *tmp, int i)
{
	g_global.fd[i][2] = open (tmp->name,
			O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (g_global.fd[i][2] == -1)
	{
		write(2, "permission denied\n", 7);
		g_global.exit_status = 1;
		return (-1);
	}
	return (0);
}

static int	open_others(t_file *tmp, int i, char **t)
{
	if (tmp->token == 4)
	{
		g_global.fd[i][2] = open (tmp->name,
				O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (g_global.fd[i][2] == -1)
		{
			write(2, "permission denied\n", 7);
			g_global.exit_status = 1;
			return (-1);
		}
	}
	else if (tmp->token == 2 || tmp->token == 6)
	{
		g_global.fd[i][1] = open (t[i], O_RDONLY);
		if (g_global.fd[i][1] == -1)
		{
			write(2, "permission denied\n", 7);
			g_global.exit_status = 1;
			return (-1);
		}
	}
	return (0);
}

static int	tokens(t_file *tmp, int i, char **t)
{
	if (tmp->token == 1)
	{
		if (error_open(i, tmp) == -1)
			return (1);
	}
	else if (tmp->token == 3)
	{
		if (open_outfile(tmp, i) == -1)
			return (1);
	}
	else
	{
		if (open_others(tmp, i, t) == -1)
			return (1);
	}
	return (0);
}

int	ft_redirections(t_data *data, char **t)
{
	int		i;
	t_file	*tmp;

	i = 0;
	while (data)
	{
		tmp = data->file;
		while (tmp)
		{
			if (tokens(tmp, i, t) == 1)
				return (1);
			tmp = tmp->next;
		}
		data = data->next;
		i++;
	}
	return (1);
}
