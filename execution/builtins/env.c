/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:05:04 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/06 23:56:47 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*ft_lstnew_ex(void *key, void *value)
{
	t_env	*head;

	head = (t_env *)malloc(sizeof(t_env));
	if (!head)
		return (NULL);
	head -> key = key;
	head -> value = value;
	head -> next = NULL;
	return (head);
}

void	ft_lstadd_back_ex(t_env **lst, t_env *new)
{
	t_env	*ptr;

	ptr = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new;
}

void	command_env(char **env)
{
	int		i;
	t_env	*tmp;
	t_env	*node;
	char	*key;
	char	*value;

	i = 1;
	if (strchr(env[0], '=') != NULL)
	{
		value = sndup(ft_strchr(env[0], '='), ft_strlen(env[0]));
		key = sndup(env[0], (ft_strlen(env[0]) - ft_strlen(value) - 1));
		g_global.env_list = ft_lstnew_ex(key, value);
		tmp = g_global.env_list;
		while (env[i])
		{
			value = sndup(ft_strchr(env[i], '='), ft_strlen(env[i]));
			key = sndup(env[i],
					(ft_strlen(env[i]) - ft_strlen(value) - 1));
			node = ft_lstnew_ex(key, value);
			ft_lstadd_back_ex(&tmp, node);
			i++;
		}
	}
}
