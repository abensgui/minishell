/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:23:22 by hbouladh          #+#    #+#             */
/*   Updated: 2022/07/07 02:05:06 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_minishell(char *str, char **t, int k, t_data *data)
{
	int	c;

	c = 0;
	c = ft_error(str);
	if (c == -1)
		k = ft_strlen(str);
	else
		k = c - 1;
	data = ft_parce(str, k);
	t = ft_heredoc(data);
	if (c == -1)
	{
		ft_execute(data, t);
		c = 3;
		while (c <= 1026)
		{
			close(c);
			c++;
		}
	}
	else
		g_global.exit_status = 258;
	add_history(str);
	free_data(data);
	free_table(t);
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	char	**t;
	t_data	*data;
	int		k;

	k = 0;
	t = NULL;
	str = NULL;
	data = NULL;
	g_global.exit_status = 0;
	(void)av;
	(void)ac;
	command_env(env);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	while (1)
	{
		g_global.sig = 0;
		str = readline("minishell> ");
		if (!str)
			exit(0);
		if (*str)
			ft_minishell(str, t, k, data);
		free(str);
	}
}
