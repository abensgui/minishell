/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:02:26 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/04 20:02:52 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	in_null(t_data **data)
{
	(*data)->file = NULL;
	(*data)->cmd = NULL;
	(*data)->lim = NULL;
	(*data)->next = NULL;
}

void	pipe_cmd(t_data **data, char *str, int *i, int k)
{
	if (str[*i] == '|' && k == 0)
	{
		(*data)->next = malloc(sizeof(t_data));
		*data = (*data)->next;
		in_null(data);
		(*i)++;
	}
	else if (str[*i] && k == 0)
		(*data)->cmd = ft_resize((*data)->cmd, ft_cmd1(str, i));
}

t_data	*ft_parce(char *str, int c)
{
	int		i;
	int		k;
	t_data	*data;
	t_data	*head;

	data = malloc(sizeof(t_data));
	in_null(&data);
	head = data;
	i = 0;
	k = 0;
	while (str[i] && i < c)
	{
		while (str[i] && ((str[i] >= 9 && str[i] <= 13)
				|| str[i] == 32) && i < c)
			i++;
		if (i < c)
		{
			k = check_redi(&data, str, &i);
			pipe_cmd(&data, str, &i, k);
		}
	}
	return (head);
}
