/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:00:02 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/06 23:29:23 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char *s1, char c)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!s1)
		s = malloc(2 * sizeof(char));
	else
	{
		s = malloc((ft_strlen(s1) + 2) * sizeof(char));
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
	}
	s[i] = c;
	i++;
	free(s1);
	s1 = NULL;
	s[i] = '\0';
	return (s);
}
