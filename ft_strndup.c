/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:49:04 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/06 23:49:59 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*sndup(char *src, size_t n)
{
	char	*p;
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	if (src)
		c = ft_strlen(src);
	p = malloc((c + 1) * sizeof(char));
	if (!p)
		return (0);
	if (src)
	{
		while (src[i] && i < n)
		{
			p[i] = src[i];
			i++;
		}
	}
	p[i] = '\0';
	return (p);
}
