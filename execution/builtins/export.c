/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:31:27 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 02:30:05 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_plus(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=' && s[i - 1] == '+')
			return (1);
		else if (s[i] == '=' && s[i - 1] != '+')
			return (0);
		i++;
	}
	return (0);
}

static void	key_and_value(int i, t_data *data)
{
	char	*key;
	char	*value;

	value = strndup(ft_strchr(data->cmd[i], '='), strlen(data->cmd[i]));
	key = strndup(data->cmd[i], (strlen(data->cmd[i]) - strlen(value) - 1));
	g_global.exit_status = 0;
	if (check_plus(data->cmd[i]) == 0)
		key_without_plus(key, value, data, i);
	else if (check_plus(data->cmd[i]) == 1)
		key_with_plus(key, value, data, i);
}

static void	key_only(t_env *node, int i, t_data *data)
{
	char	*key;

	if (is_not_in_env(data->cmd[i]))
	{
		key = strndup(data->cmd[i], strlen(data->cmd[i]));
		node = ft_lstnew_export(key, NULL);
		ft_lstadd_back_export(node);
	}
}

static void	not_a_valid_identifier(t_data *data, int i)
{
	write(2, "export: ", 9);
	write(2, data->cmd[i], strlen(data->cmd[i]));
	write(2, " :not a valid identifier\n", 26);
	g_global.exit_status = 1;
}

void	command_export(t_data *data)
{
	int		i;
	t_env	*node;

	i = 0;
	node = NULL;
	if (!data->cmd[1])
	{
		ft_sort();
		return ;
	}
	else
	{
		while (data->cmd[++i])
		{
			if (strchr(data->cmd[i], '=') != NULL)
				key_and_value(i, data);
			else if (strchr(data->cmd[i], '=') == NULL
				&& check_start_key(data->cmd[i])
				&& check_all_key(data->cmd[i]))
				key_only(node, i, data);
			else
				not_a_valid_identifier(data, i);
		}
	}
}
