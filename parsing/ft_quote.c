/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:48 by abensgui          #+#    #+#             */
/*   Updated: 2022/06/16 15:20:24 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_qoute(char *str, int *i)
{
	char	*tmp;
	int		c;

	c = 0;
	tmp = ft_strdup("");
	while (str[*i] && c < 2)
	{
		if (str[*i] == '\'')
			c++;
		else
			tmp = ft_strjoin(tmp, str[*i]);
		(*i)++;
	}
	return (tmp);
}
