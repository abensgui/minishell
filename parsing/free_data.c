/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:50:55 by abensgui          #+#    #+#             */
/*   Updated: 2022/07/05 13:19:08 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_data(t_data *data)
{
	t_file	*tmp;
	t_data	*tmp1;

	while (data)
	{
		while (data->file)
		{
			tmp = data->file;
			data->file = data->file->next;
			free(tmp->name);
			free(tmp);
		}
		if (data->cmd)
			free_table(data->cmd);
		if (data->lim)
			free_table(data->lim);
		tmp1 = data;
		data = data->next;
		free(tmp1);
		tmp1 = NULL;
	}
}
