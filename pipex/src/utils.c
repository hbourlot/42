/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:22:30 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/26 20:19:25 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

int	open_fd(char *file, t_cmd *cmd)
{
	if (cmd->in_fd == READ)
	{
		cmd->in_fd = open(file, O_RDONLY);
		if (cmd->in_fd < 0)
			return (-1);
	}
	if (cmd->out_fd == WRITE)
	{
		cmd->out_fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (cmd->out_fd < 0)
		{
			close(cmd->in_fd);
			return (-1);
		}
	}
	return (0);
}

static void	duplicate_fd(int fd1, int fd2)
{
	if (fd1 != -1)
	{
		dup2(fd1, fd2);
		close(fd1);
	}
}

int	do_dup2(t_data *data, t_cmd *command)
{
	int	status;

	status = 0;
	if (data->pipe_info.prev_fd != -1)
		duplicate_fd(data->pipe_info.prev_fd, STDIN_FILENO);
	if (command->in_fd == READ)
	{
		status = open_fd(data->argv[1], command);
		duplicate_fd(command->in_fd, STDIN_FILENO);
	}
	if (command->out_fd == WRITE)
	{
		status = open_fd(data->argv[data->argc - 1], command);
		duplicate_fd(command->out_fd, STDOUT_FILENO);
	}
	else
		dup2(data->pipe_info.pipe_id[1], STDOUT_FILENO);
	close(data->pipe_info.pipe_id[1]);
	close(data->pipe_info.pipe_id[0]);
	return (status);
}
