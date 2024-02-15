/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:33:37 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/05 04:48:59 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	command_pwd(void)
{
	char	*buf;
	t_env	*tmp;
	char	buffer[PATH_MAX];

	tmp = g_global.env_list;
	buf = getcwd(buffer, PATH_MAX);
	if (buf == NULL)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->key, "PWD") == 0)
			{
				printf("%s\n", (char *)tmp->value);
				break ;
			}
			tmp = tmp->next;
		}
	}
	else
		printf("%s\n", buffer);
}
