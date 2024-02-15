/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:28:18 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:13 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_there_value(char *s, t_env *env)
{
	char	*key;

	while (env)
	{
		key = env->key;
		if (ft_strcmp(key, s) == 0)
		{
			if (env->value != NULL)
				return (1);
		}
		env = env->next;
	}
	return (0);
}
