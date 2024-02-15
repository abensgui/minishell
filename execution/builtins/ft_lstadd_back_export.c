/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:15:09 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/05 01:15:37 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_lstadd_back_export(t_env *new)
{
	t_env	*ptr;

	ptr = g_global.env_list;
	if (!new)
		return ;
	if (!g_global.env_list)
	{
		g_global.env_list = new;
		return ;
	}
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new;
}
