/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:15 by abensgui          #+#    #+#             */
/*   Updated: 2022/06/20 18:39:29 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_dqoute(char *str, int *i)
{
	char	*tmp;
	int		c;

	c = 0;
	tmp = ft_strdup("");
	while (str[*i] && c < 2)
	{
		if (str[*i] == '\"')
			c++;
		else
			tmp = ft_strjoin(tmp, str[*i]);
		(*i)++;
	}
	return (tmp);
}
