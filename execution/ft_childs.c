/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:38:14 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/05 21:21:38 by hbouladh         ###   ########.fr       */
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

void	ft_childs(int **fd, int j, int i)
{
	if (j == 0)
	{
		ft_close_fd(fd, i, g_global.fd[j][1], fd[j][1]);
		dup2(fd[j][1], 1);
		if (g_global.fd[j][1] != -1)
			dup2(g_global.fd[j][1], 0);
		ft_close_fd(fd, i, -1, -1);
	}
	else if (j == i - 1)
	{
		ft_close_fd(fd, i, fd[j - 1][0], g_global.fd[j][2]);
		dup2(fd[j - 1][0], 0);
		if (g_global.fd[j][2] != -1)
			dup2(g_global.fd[j][2], 1);
		ft_close_fd(fd, i, -1, -1);
	}
	else
	{
		ft_close_fd(fd, i, fd[j - 1][0], fd[j][1]);
		dup2(fd[j - 1][0], 0);
		dup2(fd[j][1], 1);
		ft_close_fd(fd, i, -1, -1);
	}
	ft_close_fd(fd, i, -1, -1);
}
