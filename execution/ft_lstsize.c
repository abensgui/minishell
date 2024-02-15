/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:06:24 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/03 17:07:15 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstsize(t_data *lst)
{
	int		i;
	t_data	*p;

	p = lst;
	if (!p)
		return (0);
	i = 0;
	while (p)
	{
		i++;
		p = p -> next;
	}
	return (i);
}

int	ft_lstsize_env(t_env *lst)
{
	int		i;
	t_env	*p;

	p = lst;
	if (!p)
		return (0);
	i = 0;
	while (p)
	{
		i++;
		p = p -> next;
	}
	return (i);
}
