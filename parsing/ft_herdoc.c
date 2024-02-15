/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:24 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/04 20:01:20 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_file	*ft_herdoc(char *str, int *i, int token)
{
	t_file	*tmp;

	tmp = malloc(sizeof(t_file));
	tmp->name = NULL;
	tmp->token = token;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] && (str[*i] < 9 || str[*i] > 13)
		&& str[*i] != 32 && str[*i] != '<'
		&& str[*i] != '>' && str[*i] != '|')
	{
		if (str[*i] == '\"' || str[*i] == '\'')
			tmp->token = 6;
		if (str[*i] == '\"')
			tmp->name = ft_join(tmp->name, ft_dqoute(str, i));
		else if (str[*i] == '\'')
			tmp->name = ft_join(tmp->name, ft_qoute(str, i));
		else if (str[*i] == '$' && (str[(*i) + 1] == '\''
				|| str[(*i) + 1] == '\"'))
				(*i)++;
		else
			tmp->name = ft_strjoin(tmp->name, str[(*i)++]);
	}
	tmp->next = NULL;
	return (tmp);
}
