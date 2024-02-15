/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:09:54 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 00:37:26 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_skeep(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	value;

	sign = 1;
	value = 0;
	i = ft_skeep(str, &sign);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			value = (value * 10) + (str[i] - '0');
			if (value > 9223372036854775808ULL && sign == -1)
				return (-1);
			if (value > 9223372036854775807 && sign == 1)
				return (-1);
			i++;
		}
		else
			break ;
	}
	g_global.exit_status = (value * sign);
	return (1);
}
