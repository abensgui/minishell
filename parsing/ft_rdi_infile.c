/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdi_infile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:51 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/04 20:03:15 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_file	*ft_redi(char *str, int *i, int token)
{
	t_file	*tmp;

	tmp = malloc(sizeof(t_file));
	tmp->name = NULL;
	while (str[*i] == ' ')
		(*i)++;
	while (str[*i] && (str[*i] < 9 || str[*i] > 13) && str[*i] != 32
		&& str[*i] != '<' && str[*i] != '>' && str[*i] != '|')
	{
		if (str[*i] == '\"')
			tmp->name = ft_join(tmp->name, ft_expand(ft_dqoute(str, i), 1));
		else if (str[*i] == '\'')
			tmp->name = ft_join(tmp->name, ft_qoute(str, i));
		else
			tmp->name = ft_join(tmp->name, ft_expand(cat_str(str, i), 0));
	}
	tmp->token = token;
	tmp->next = NULL;
	return (tmp);
}
