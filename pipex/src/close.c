/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:18:04 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/31 10:30:21 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

void	error(char *msg, int exit_val)
{
	ft_putstr_fd(msg, 2);
	exit(exit_val);
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
	perror(msg);
	exit(exit_code);
}
