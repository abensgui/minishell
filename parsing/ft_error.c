/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:18 by abensgui          #+#    #+#             */
/*   Updated: 2022/06/29 16:29:46 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_error(char *str)
{
	int	v;
	int	i;

	v = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			v = error_quote(str, &i);
		else if (str[i] == '\"')
			v = error_dquote(str, &i);
		else if (str[i] == '<')
			v = error_redi_in(str, &i);
		else if (str[i] == '>')
			v = error_redi_ou(str, &i);
		else if (str[i] == '|')
			v = error_pipe(str, &i);
		else if (str[i])
			i++;
		if (v != -1)
			return (v);
	}
	return (-1);
}
