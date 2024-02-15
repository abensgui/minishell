/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_without_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:26:42 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 02:41:05 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	print_err(t_data *data, int i)
{
	write(2, "export: ", 9);
	write(2, data->cmd[i], ft_strlen(data->cmd[i]));
	write(2, " :not a valid identifier\n", 26);
}

static void	add_new_env(char *key, char *value)
{
	t_env	*node;

	node = ft_lstnew_export(key, value);
	ft_lstadd_back_export(node);
}

void	key_without_plus(char *key, char *value, t_data *data, int i)
{
	if (check_start_key(key) && check_all_key(key))
	{
		if (is_not_in_env(key))
			add_new_env(key, value);
		else
			ft_overwrite(key, value);
	}
	else
	{
		print_err(data, i);
		g_global.exit_status = 1;
	}
}
