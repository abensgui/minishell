/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:34:45 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 00:02:53 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_start_key_unset(char *s)
{
	if ((s[0] >= 65 && s[0] <= 90)
		|| (s[0] >= 97 && s[0] <= 122)
		|| s[0] == 95)
		return (1);
	return (0);
}

static int	check_all_key_unset(char *s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if ((s[i] >= 65 && s[i] <= 90)
			|| (s[i] >= 97 && s[i] <= 122)
			|| s[i] == 95
			|| (s[i] >= 48 && s[i] <= 57))
			i++;
		else
			return (0);
	}
	return (1);
}

static void	free_node(t_env *temp)
{
	free(temp->key);
	free(temp->value);
	free(temp);
}

void	ft_lstdelone(char *key)
{
	t_env	*temp;
	t_env	*current;

	if (ft_strcmp((g_global.env_list)->key, key) == 0)
	{
		temp = g_global.env_list;
		g_global.env_list = (g_global.env_list)->next;
		free_node(temp);
	}
	else
	{
		current = g_global.env_list;
		while (current->next != NULL)
		{
			if (ft_strcmp(current->next->key, key) == 0)
			{
				temp = current->next;
				current->next = current->next->next;
				free_node(temp);
				break ;
			}
			else
				current = current->next;
		}
	}
}

void	command_unset(t_data *data)
{
	int	i;

	i = 1;
	if (g_global.env_list != NULL && data->cmd[1])
	{
		while (data->cmd[i])
		{
			if (check_start_key_unset(data->cmd[i])
				&& check_all_key_unset(data->cmd[i]))
			{
				ft_lstdelone(data->cmd[i]);
				i++;
			}
			else
			{
				write(2, "unset: ", 8);
				write(2, data->cmd[i], ft_strlen(data->cmd[i]));
				write(2, " :not a valid identifier\n", 26);
				i++;
				g_global.exit_status = 1;
			}
		}
	}
}
