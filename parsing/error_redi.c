/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:08 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/04 19:56:15 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	error_redi_in(char *str, int *i)
{
	int	c;

	c = (*i)++;
	if (str[*i] == '<')
		(*i)++;
	while (str[*i])
	{
		if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
		{
			write(2, "Error redi\n", 11);
			return (c);
		}
		else if (str[*i] != ' ')
			return (-1);
		(*i)++;
	}
	write(2, "Error redi\n", 11);
	return (c);
}

int	error_redi_ou(char *str, int *i)
{
	int	c;

	c = (*i)++;
	if (str[*i] == '>')
		(*i)++;
	while (str[*i])
	{
		if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
		{
			write(2, "Error redi\n", 11);
			return (c);
		}
		else if (str[*i] != ' ')
			return (-1);
		(*i)++;
	}
	write(2, "Error redi\n", 11);
	return (c);
}
