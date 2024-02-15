/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:35 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/06 23:29:24 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

char	*ft_join(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s1)
		k = ft_strlen(s1);
	if (s2)
		k += ft_strlen(s2);
	s = malloc((k + 1) * sizeof(char));
	if (!s)
		return (NULL);
	k = 0;
	if (s1)
		while (s1[i])
			s[i++] = s1[k++];
	k = 0;
	if (s2)
		while (s2[k])
			s[i++] = s2[k++];
	free(s1);
	free(s2);
	s[i] = '\0';
	return (s);
}
