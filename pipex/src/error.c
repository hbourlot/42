/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:50:03 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:22 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

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

static void	exit_by_fd(t_data *data, const char *msg1, const char *msg2,
		int exit_s)
{
	ft_putstr_fd((char *)msg1, STDERR_FILENO);
	ft_putstr_fd((char *)msg2, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	clear_all(&data->command);
	exit(exit_s);
}

void	check_file_access(t_data *data, const char *file_name, int exit_s)
{
	char	*last_slash;

	if (access(file_name, F_OK) != 0)
	{
		last_slash = strrchr(file_name, '/');
		if (last_slash != NULL)
		{
			*last_slash = '\0';
			if (access(file_name, F_OK) != 0)
				exit_by_fd(data, ERR_DIRECTORY_NOT_FOUND, file_name, exit_s);
			else
				exit_by_fd(data, ERR_FILE_NOT_FOUND, file_name, 1);
			*last_slash = '/';
		}
		else
			exit_by_fd(data, ERR_FILE_NOT_FOUND, file_name, 1);
	}
	if (access(file_name, R_OK) != 0 || access(file_name, W_OK) != 0)
		exit_by_fd(data, ERR_PERMISSION_DENIED, file_name, exit_s);
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
