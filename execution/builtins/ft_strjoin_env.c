/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:33:04 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 02:00:03 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static size_t	ft_len(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_s;

	len_s1 = 0;
	len_s2 = 0;
	len_s = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	len_s = len_s1 + len_s2;
	return (len_s);
}

static void	ft_insert(char *p, const char *s1, const char *s2)
{	
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (s1[j])
	{
		p[j] = s1[j];
		j++;
	}
	while (s2[k])
	{
		p[j] = s2[k];
		j++;
		k++;
	}
}

char	*ft_strjoin_env(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_len(s1, s2);
	p = (char *)malloc (i + 1);
	if (!p)
		return (NULL);
	ft_insert(p, s1, s2);
	p[i] = '\0';
	free((char *)s2);
	return (p);
}
