/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:14:18 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/06 12:58:33 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT && g_global.sig == 1)
	{
		g_global.exit_status = 131;
		printf("Quit: 3\n");
		g_global.sig = 0;
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	else if (sig == SIGQUIT && (g_global.sig == 0 || g_global.sig == 3))
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT && g_global.sig == 0)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGINT && g_global.sig == 1)
	{
		g_global.exit_status = 130;
		printf("\n");
		g_global.sig = 0;
		rl_replace_line("", 0);
		rl_on_new_line();
		return ;
	}
	else if (sig == SIGINT && g_global.sig == 3)
	{
		printf("\n");
		close(0);
		g_global.sig = 4;
		g_global.exit_status = 1;
	}
}
