/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:29:00 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/06 23:29:23 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parc_her(char *str, char c)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	tmp = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{	
			i++;
			tmp1 = ft_strdup("$");
			while (str[i] && ft_isalpha(str[i]))
				tmp1 = ft_strjoin(tmp1, str[i++]);
			if (c == '2')
				tmp = ft_join(tmp, ft_expand(tmp1, 1));
			else
				tmp = ft_join(tmp, tmp1);
		}
		else
			tmp = ft_strjoin(tmp, str[i++]);
	}
	return (tmp);
}

static int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (-1);
	write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
	free(s);
	return (1);
}

static void	sig_heredoc(int f)
{
	if (g_global.sig == 4)
	{
		dup2(f, 0);
		g_global.sig = 0;
	}
}

static void	heredoc_and_file(char **limiter, int fd)
{
	int		i;
	int		v;
	char	*str;
	int		f;

	f = dup(0);
	i = 0;
	v = 0;
	g_global.sig = 3;
	while (limiter[v])
		v++;
	while (limiter[i] && g_global.sig != 4)
	{
		str = readline("> ");
		if (str && i == v - 1)
		{
			if (ft_strcmp(str, &limiter[i][1]) != 0)
				ft_putstr_fd(parc_her(str, limiter[i][0]), fd);
		}
		if (!str || (str && ft_strcmp(str, &limiter[i][1]) == 0))
			i++;
		free(str);
	}
	sig_heredoc(f);
}

char	**ft_heredoc(t_data *data)
{
	int		fd;
	int		i;
	char	*file;
	char	*num;
	char	**t;

	i = 1;
	fd = -1;
	t = NULL;
	while (data)
	{
		if (data->lim)
		{
			file = strdup("/tmp/heredoc");
			num = ft_itoa(i);
			t = ft_resize(t, ft_join(file, num));
			fd = open (t[i - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
			heredoc_and_file(data->lim, fd);
		}
		else
			t = ft_resize(t, ft_strdup(" "));
		data = data->next;
		i++;
	}
	return (t);
}
