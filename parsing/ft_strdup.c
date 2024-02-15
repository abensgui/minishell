/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:58 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/06 23:29:23 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;
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
		while (src[i])
		{
			p[i] = src[i];
			i++;
		}
	}
	p[i] = '\0';
	return (p);
}
