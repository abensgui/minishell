/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:12 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/06 12:11:57 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*cat_str(char *str, int *i)
{
	char	*tmp;

	tmp = ft_strdup("");
	while (str[*i] && (str[*i] < 9 || str[*i] > 13) && str[*i] != 32
		&& str[*i] != '<' && str[*i] != '>' && str[*i] != '|')
	{
		if (str[*i] == '\"' || str[*i] == '\'')
			break ;
		tmp = ft_strjoin(tmp, str[*i]);
		(*i)++;
	}
	return (tmp);
}

char	*ft_cmd1(char *str, int *i)
{
	char	*tmp;
	char	*t;

	tmp = ft_strdup("");
	while (str[*i] == ' ')
		(*i)++;
	while (str[*i] && (str[*i] < 9 || str[*i] > 13) && str[*i] != 32
		&& str[*i] != '<' && str[*i] != '>' && str[*i] != '|')
	{
		if (str[*i] == '\"')
			tmp = ft_join(tmp, ft_expand(ft_dqoute(str, i), 1));
		else if (str[*i] == '\'')
			tmp = ft_join(tmp, ft_qoute(str, i));
		else
		{
			t = ft_expand(cat_str(str, i), 1);
			if (!t && tmp[0] == '\0')
			{
				free(tmp);
				return (NULL);
			}
			tmp = ft_join(tmp, t);
		}
	}
	return (tmp);
}
