/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:45 by abensgui          #+#    #+#             */
/*   Updated: 2022/06/21 14:14:11 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_file	*ft_lstnew(char *content, int token)
{
	t_file	*l;

	l = NULL;
	if (!l)
		return (0);
	l->name = content;
	l->token = token;
	l->next = NULL;
	return (l);
}
