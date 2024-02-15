/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:47:03 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/05 22:03:47 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	one_process(int fd0, int fd1, t_data *data)
{
	if (g_global.fd[0][1] != -1)
		dup2(g_global.fd[0][1], 0);
	if (g_global.fd[0][2] != -1)
		dup2(g_global.fd[0][2], 1);
	if (ft_builtins(data))
	{
		dup2(fd0, 0);
		dup2(fd1, 1);
		return (1);
	}
	return (0);
}

static void	ft_store_fds(int i, int **fd)
{
	int	j;

	j = 0;
	while (j < i)
	{
		fd[j] = malloc(sizeof(int) * 2);
		g_global.fd[j] = malloc(sizeof(int) * 3);
		g_global.fd[j][0] = -1;
		g_global.fd[j][1] = -1;
		g_global.fd[j][2] = -1;
		fd[j][0] = -1;
		fd[j][1] = -1;
		j++;
	}
}

static void	free_fds(int i, int **fd, int fd0, int fd1)
{
	int	j;

	j = 0;
	dup2(fd0, 0);
	dup2(fd1, 1);
	while (j < i)
	{
		free(fd[j]);
		free(g_global.fd[j]);
		j++;
	}
	free(fd);
	free(g_global.fd);
}

void	ft_execute(t_data *data, char **t)
{
	int	i;
	int	**fd;
	int	fd0;
	int	fd1;

	fd0 = dup(0);
	fd1 = dup(1);
	i = ft_lstsize(data);
	fd = (int **)malloc (sizeof(int *) * i);
	g_global.fd = (int **)malloc (sizeof(int *) * i);
	ft_store_fds(i, fd);
	if (ft_redirections(data, t) == 1)
	{
		if (i == 1)
		{
			if (one_process(fd0, fd1, data) == 1)
			{
				free_fds(i, fd, fd0, fd1);
				return ;
			}
		}
		ft_pipes(data, fd, i);
	}
	free_fds(i, fd, fd0, fd1);
}
