/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:41:53 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/05 11:45:28 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	in_data(t_data **data, char *str, int *i)
{
	t_file	*tmp;

	if (str[++(*i)] && str[*i] == '<')
	{
		(*i)++;
		tmp = ft_herdoc(str, i, 2);
		ft_lstadd_back(&(*data)->file, tmp);
		tmp->name = ft_join(ft_itoa(tmp->token), tmp->name);
		(*data)->lim = ft_resize((*data)->lim, ft_strdup(tmp->name));
	}
	else
		ft_lstadd_back(&(*data)->file, ft_redi(str, i, 1));
}

int	check_redi(t_data **data, char *str, int *i)
{
	int		c;

	c = 0;
	if (str[*i] && str[*i] == '<')
	{
		c = 1;
		in_data(data, str, i);
	}
	else if (str[*i] && str[*i] == '>' )
	{
		c = 1;
		if (str[++(*i)] && str[*i] == '>')
		{
			(*i)++;
			ft_lstadd_back(&(*data)->file, ft_redi(str, i, 4));
		}
		else
			ft_lstadd_back(&(*data)->file, ft_redi(str, i, 3));
	}
	return (c);
}
