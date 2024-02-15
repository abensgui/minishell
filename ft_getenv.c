/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:22:29 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/06 16:10:33 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *s)
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
		{
			free(s);
			return (value);
		}
		temp = temp->next;
	}
	free(s);
	return (NULL);
}
