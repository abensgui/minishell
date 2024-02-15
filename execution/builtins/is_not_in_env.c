/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_in_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:22:35 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 02:27:45 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_not_in_env(char *s)
{
	char	*key;
	t_env	*temp;

	temp = g_global.env_list;
	while (temp)
	{
		key = temp->key;
		if (ft_strcmp(s, key) == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}
