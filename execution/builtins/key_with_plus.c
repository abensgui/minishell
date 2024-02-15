/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_with_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:26:33 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 02:51:09 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	key_with_plus_in_env(char *key, char *value)
{
	char	*tmp_value;

	if (is_there_value(key, g_global.env_list))
	{
		tmp_value = return_value(key);
		value = ft_strjoin_env(tmp_value, value);
		ft_overwrite(key, value);
	}
	else
		ft_overwrite(key, value);
}

static int	check_all_with_plus(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 65 && s[i] <= 90)
			|| (s[i] >= 97 && s[i] <= 122)
			|| s[i] == 95
			|| (s[i] >= 48 && s[i] <= 57))
			i++;
		else if (s[i] == '+' && s[i + 1] == '\0')
			return (1);
		else
			return (0);
	}
	return (1);
}

void	key_with_plus(char *key, char *value, t_data *data, int i)
{
	t_env	*node;

	if (check_start_key(key) && check_all_with_plus(key))
	{
		free(key);
		key = sndup(data->cmd[i],
				(ft_strlen(data->cmd[i]) - ft_strlen(value) - 2));
		if (is_not_in_env(key))
		{
			node = ft_lstnew_export(key, value);
			ft_lstadd_back_export(node);
		}
		else
			key_with_plus_in_env(key, value);
	}
	else
	{
		write(2, "export: ", 9);
		write(2, data->cmd[i], ft_strlen(data->cmd[i]));
		write(2, " :not a valid identifier\n", 26);
		g_global.exit_status = 1;
		free(key);
		free(value);
	}
}
