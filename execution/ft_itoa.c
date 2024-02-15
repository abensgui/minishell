/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:05:26 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/03 17:06:15 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	len_int(int i)
{
	int	count;

	count = 0;
	if (i <= 0)
		count++;
	while (i != 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char	*ft_checknumber(char *res, int n, int i)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		num = n * -1;
		res[0] = '-';
	}
	else
		num = n;
	while (num > 9)
	{
		res[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	res [i] = num + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				i;
	int				len;

	len = len_int(n);
	i = len - 1;
	res = (char *) malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res [len] = '\0';
	return (ft_checknumber(res, n, i));
}
