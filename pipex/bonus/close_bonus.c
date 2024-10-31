/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:18:04 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/28 17:44:26 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

void	error(char *msg, int exit_val)
{
	ft_putstr_fd(msg, 2);
	exit(exit_val);
}

void	error_execve(t_data *data, t_cmd *command)
{
	if (access(command->path, F_OK))
	{
		ft_putstr_fd(command->args[0], 2);
		ft_putstr_fd(": Command not found\n", STDERR_FILENO);
		clear_all(&data->command);
		exit(127);
	}
	clear_all(&data->command);
	exit(EXIT_FAILURE);
}

void	ft_close(int exit_code, t_data *data, char *msg)
{
	if (data->pipe_info.pipe_id[0] != -1)
		close(data->pipe_info.pipe_id[0]);
	if (data->pipe_info.pipe_id[1] != -1)
		close(data->pipe_info.pipe_id[1]);
	if (data->command)
		clear_all(&data->command);
	if (exit_code == 127)
	{
		ft_putstr_fd("'': Command not found\n", 2);
		exit(127);
	}
	if (exit_code == 1)
	{
		perror(msg);
		exit(1);
	}
}

void	clear_all(t_cmd **command)
{
	t_cmd	*tmp;

	while (command && *command)
	{
		tmp = (*command)->next;
		if ((*command)->in_fd != -1 && (*command)->in_fd != WRITE)
			close((*command)->in_fd);
		if ((*command)->out_fd != -1 && (*command)->out_fd != WRITE)
			close((*command)->out_fd);
		if ((*command)->path)
			free((*command)->path);
		if ((*command)->args)
			free_split((*command)->args);
		free(*command);
		*command = tmp;
	}
}
