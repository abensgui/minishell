/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overwrite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:16:35 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 01:40:59 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_overwrite(char *data, char *value)
{
	char	*key;
	t_env	*tmp;
	char	*t;

	tmp = g_global.env_list;
	while (g_global.env_list)
	{
		key = (g_global.env_list)->key;
		if (ft_strcmp(data, key) == 0)
		{
			t = (g_global.env_list)->value;
			(g_global.env_list)->value = value;
			free(t);
			break ;
		}
		g_global.env_list = (g_global.env_list)->next;
	}
	g_global.env_list = tmp;
	free(data);
	return ;
}
