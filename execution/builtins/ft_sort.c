/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:18:45 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/05 01:20:40 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_sort(void)
{
	t_env	*key;
	t_env	*value;
	t_env	*temp;
	t_env	*temp2;

	temp = g_global.env_list;
	temp2 = g_global.env_list;
	while (g_global.env_list != NULL)
	{
		if ((g_global.env_list)->next && cmp((g_global.env_list)->key,
				(g_global.env_list)->next->key) > 0)
		{
			key = g_global.env_list->key;
			value = g_global.env_list->value;
			g_global.env_list->key = g_global.env_list->next->key;
			g_global.env_list->value = g_global.env_list->next->value;
			g_global.env_list->next->key = key;
			g_global.env_list->next->value = value;
			g_global.env_list = temp;
		}
		else
			g_global.env_list = g_global.env_list->next;
	}
	g_global.env_list = temp2;
	print_export_list(g_global.env_list);
}
