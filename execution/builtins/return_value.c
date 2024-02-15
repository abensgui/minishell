/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:30:28 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/05 01:30:42 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*return_value(char *s)
{
	char	*key;
	char	*value;
	t_env	*temp;

	temp = g_global.env_list;
	while (temp)
	{
		key = temp->key;
		value = temp->value;
		if (ft_strcmp(s, key) == 0)
			return (value);
		temp = temp->next;
	}
	return (NULL);
}
