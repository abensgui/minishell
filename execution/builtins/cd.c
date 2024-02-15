/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:04:59 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/06 23:50:53 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	add_old_pwd(char *old_pwd)
{
	char	*key;
	char	*old_value;
	int		c;
	t_env	*tmp;

	c = 0;
	tmp = g_global.env_list;
	while (g_global.env_list)
	{
		key = (g_global.env_list)->key;
		if (ft_strcmp("OLDPWD", key) == 0)
		{
			c = 1;
			old_value = (g_global.env_list)->value;
			(g_global.env_list)->value = old_pwd;
			free(old_value);
			break ;
		}
		g_global.env_list = (g_global.env_list)->next;
	}
	g_global.env_list = tmp;
	if (c == 0)
		free(old_pwd);
	return ;
}

static void	add_pwd(char *pwd)
{
	char	*key;
	char	*old_value;
	int		c;
	t_env	*tmp;

	c = 0;
	tmp = g_global.env_list;
	while (g_global.env_list)
	{
		key = (g_global.env_list)->key;
		if (ft_strcmp("PWD", key) == 0)
		{
			c = 1;
			old_value = (g_global.env_list)->value;
			(g_global.env_list)->value = pwd;
			free(old_value);
			break ;
		}
		g_global.env_list = (g_global.env_list)->next;
	}
	g_global.env_list = tmp;
	if (c == 0)
		free(pwd);
	return ;
}

int	command_cd(char *path)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	add_old_pwd(buf);
	if (path)
	{
		if (ft_strcmp(path, "~") == 0)
			chdir(ft_getenv(ft_strdup("HOME")));
		else if (chdir(path) == -1)
		{
			g_global.exit_status = 1;
			return (-1);
		}
	}
	else
		chdir(ft_getenv(ft_strdup("HOME")));
	buf = getcwd(NULL, 0);
	add_pwd(buf);
	return (0);
}
