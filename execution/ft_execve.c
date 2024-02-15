/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:44:27 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/06 23:29:23 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	access_without_path(t_data *data)
{
	if (access(data->cmd[0], F_OK | X_OK) == 0
		&& strchr(data->cmd[0], '/'))
		return (0);
	return (-1);
}

static char	**env_char(t_env *env)
{
	char	**env_lst;	
	t_env	*tmp;
	int		i;
	char	*s;
	char	*t;

	env_lst = malloc(sizeof(char *) * (ft_lstsize_env(env) + 1));
	env_lst[ft_lstsize_env(env)] = NULL;
	tmp = env;
	i = 0;
	while (tmp)
	{
		s = ft_join(ft_strdup(tmp->key), ft_strdup("="));
		t = ft_join(s, ft_strdup(tmp->value));
		env_lst[i] = t;
		i++;
		tmp = tmp->next;
	}
	return (env_lst);
}

static void	ft_exec(char **st, t_data *data)
{
	int		j;
	char	*path;

	j = 0;
	while (st[j])
	{
		path = ft_strjoin(st[j], '/');
		if (access(ft_join(strdup(path),
					strdup(data->cmd[0])), F_OK | X_OK) == 0)
			break ;
		j++;
	}
	g_global.exit_status = 0;
	if (execve(ft_join(strdup(path),
				strdup(data->cmd[0])), data->cmd,
			env_char(g_global.env_list)) == -1)
	{
		write(2, data->cmd[0], ft_strlen(data->cmd[0]));
		write(2, " : command not found\n", 22);
		exit(127);
	}
}

static int	exec_without_path(char **st, char *temp, t_data *data)
{
	while (g_global.env_list)
	{
		if (g_global.env_list->key
			&& ft_strcmp(g_global.env_list->key, "PATH") == 0)
			break ;
		g_global.env_list = g_global.env_list->next;
	}
	if (g_global.env_list && g_global.env_list->value)
	{
		temp = ft_strchr(g_global.env_list->value, '/');
		if (temp)
			st = ft_split(temp, ':');
		ft_exec(st, data);
		free_table(st);
		free(temp);
	}
	else
	{
		write(2, data->cmd[0], ft_strlen(data->cmd[0]));
		write(2, " : command not found\n", 22);
		return (127);
	}
	return (0);
}

void	ft_execve(t_data *data)
{
	char	**st;
	char	*temp;

	st = NULL;
	temp = NULL;
	if (!data->cmd)
		return ;
	if (access_without_path(data) != 0)
	{
		if (exec_without_path(st, temp, data) == 127)
			exit(127);
	}
	else
	{
		if (execve(data->cmd[0], data->cmd, env_char(g_global.env_list)) == -1)
		{
			write(2, data->cmd[0], ft_strlen(data->cmd[0]));
			write(2, " : command not found\n", 22);
			exit(127);
		}
	}
}
