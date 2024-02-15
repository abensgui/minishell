/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:04 by abensgui          #+#    #+#             */
/*   Updated: 2022/06/17 19:20:57 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	error_quote(char *str, int *i)
{
	int	c;
	int	check;

	c = 0;
	c = (*i)++;
	check = 1;
	while (str[*i])
	{
		if (str[*i] == '\'')
		{
			check = 0;
			(*i)++;
			break ;
		}
		(*i)++;
	}
	if (check == 1)
	{
		write(2, "Error quote\n", 12);
		return (c);
	}
	return (-1);
}

int	error_dquote(char *str, int *i)
{
	int	c;
	int	check;

	c = 0;
	c = (*i)++;
	check = 1;
	while (str[*i])
	{
		if (str[*i] == '\"')
		{
			check = 0;
			(*i)++;
			break ;
		}
		(*i)++;
	}
	if (check == 1)
	{
		write(2, "Error dquote\n", 13);
		return (c);
	}
	return (-1);
}
