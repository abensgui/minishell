/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:43:10 by abensgui          #+#    #+#             */
/*   Updated: 2022/06/29 16:27:04 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_back_pipe(char *str, int *i, int *c)
{
	*c = (*i)++;
	while (--(*i) >= 0)
	{
		if (str[*i] != ' ' && str[*i] != '|')
		{
			*i = (*c) + 1;
			return (-1);
		}
	}
	write(2, "Error pipe\n", 11);
	return (*c);
}

int	error_pipe(char *str, int *i)
{
	int	c;

	if (check_back_pipe(str, i, &c) != -1)
		return (c);
	while (str[*i])
	{
		if (str[*i] == '|')
		{
			write(2, "Error pipe\n", 11);
			return (c);
		}
		else if (str[*i] != ' ')
			return (-1);
		(*i)++;
	}
	write(2, "Error pipe\n", 11);
	return (c);
}
