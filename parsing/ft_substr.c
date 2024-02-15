/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:00:06 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/06 23:29:23 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_alloc(int len, int sa, char *s)
{
	int	ls;
	int	x;

	ls = ft_strlen(s);
	if (len > ls)
		x = ls - sa;
	else
		x = len;
	if (x < 0)
		return (0);
	return (x);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;
	size_t	ls;

	if (s)
	{
		ls = ft_strlen(s);
		ss = malloc((ft_alloc(len, start, s) + 1) * sizeof(char));
		if (!ss)
			return (NULL);
		i = 0;
		while (s[i] && i < len && start < ls && i < ls - start)
		{
			ss[i] = s[i + start];
			i++;
		}
		ss[i] = '\0';
		return (ss);
	}
	return (0);
}
