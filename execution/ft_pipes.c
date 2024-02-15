/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:34:53 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 13:51:06 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_close_fd(int **fd, int j, int fd1, int fd2)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (fd1 != fd[i][0])
			close(fd[i][0]);
		if (fd2 != fd[i][1])
			close(fd[i][1]);
		i++;
	}
}

static int	child(int **fd, t_data *data, int j, int i)
{
	int	pid;

	pid = fork();
	g_global.sig = 1;
	if (pid < 0)
		perror(NULL);
	if (pid == 0)
	{
		if (i > 1)
		{
			if (j >= 1 && g_global.fd[j][1] != -1)
				fd[j - 1][0] = g_global.fd[j][1];
			if (g_global.fd[j][2] != -1)
				fd[j][1] = g_global.fd[j][2];
			ft_childs(fd, j, i);
		}
		if (ft_builtins(data))
			exit(g_global.exit_status);
		ft_execve(data);
	}
	return (pid);
}

static void	exit_status_childs(int i, int *pid, int status)
{
	int	j;

	j = 0;
	while (j < i)
	{
		waitpid(pid[j], &status, 0);
		if (WIFEXITED(status))
			g_global.exit_status = WEXITSTATUS(status);
		j++;
	}
	free(pid);
}

void	ft_pipes(t_data *data, int **fd, int i)
{
	int	j;
	int	*pid;
	int	status;

	pid = 0;
	j = 0;
	status = 0;
	pid = malloc(sizeof(int) * i);
	while (j < i)
	{
		if (j < i - 1)
			pipe(fd[j]);
		if (data->cmd)
			pid[j] = child(fd, data, j, i);
		j++;
		data = data->next;
	}
	ft_close_fd(fd, i, -1, -1);
	exit_status_childs(i, pid, status);
}
