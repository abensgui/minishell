/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:59:21 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/07 14:00:49 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_expand(char *str, int *i, char **tmp)
{
	int	k;

	k = 0;
	if (str[*i] && str[*i] == '$' && (ft_isalpha(str[(*i) + 1])
			|| str[(*i) + 1] == '_'))
	{
		(*i)++;
		k = *i;
		while (str[*i])
		{
			if (!ft_isalpha(str[*i + 1]) && str[(*i) + 1] != '_'
				&& !ft_isdigit(str[(*i) + 1]))
				break ;
			(*i)++;
		}
		*tmp = ft_join(*tmp,
				ft_strdup(ft_getenv(ft_substr(str, k, (*i) - k + 1))));
	}
	else if (str[*i] == '$' && str[(*i) + 1] == '?')
	{
		*tmp = ft_join(*tmp, ft_itoa(g_global.exit_status));
		(*i)++;
	}
	else if (str[*i] && str[*i] != '$')
		*tmp = ft_strjoin(*tmp, str[*i]);
}

static char	*free_tmp(char *tmp)
{
	free(tmp);
	return (NULL);
}

char	*ft_expand(char *str, int c)
{
	char	*tmp;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (ft_strcmp(str, "$") == 0 && c == 1)
		return (str);
	tmp = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$' && ft_isdigit(str[i + 1]))
			i += 2;
		check_expand(str, &i, &tmp);
		if (str[i])
			i++;
	}
	free(str);
	if (!*tmp)
		return (free_tmp(tmp));
	return (tmp);
}
