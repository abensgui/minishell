/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:16:39 by abensgui          #+#    #+#             */
/*   Updated: 2022/06/16 15:16:39 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_resize(char **str, char *str1)
{
	char	**s;
	int		i;

	i = 0;
	if (!str1)
		return (str);
	if (!str)
	{	
		s = malloc(2 * sizeof(char *));
		s[0] = str1;
		s[1] = NULL;
	}
	else
	{
		s = malloc((ft_len(str) + 2) * sizeof(char *));
		while (str[i])
		{
			s[i] = str[i];
			i++;
		}
		s[i] = str1;
		s[i + 1] = NULL;
		free(str);
	}
	return (s);
}
