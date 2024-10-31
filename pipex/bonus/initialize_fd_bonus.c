/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:42:27 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/26 16:03:25 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

void	close_fd(t_data *data, int in, int out)
{
	if (out < 0)
	{
		if (in > 0)
			close(in);
		return (ft_close(1, data, data->argv[data->argc - 1]));
	}
	if (in < 0)
	{
		if (out > 0)
			close(out);
		return (ft_close(1, data, data->argv[1]));
	}
	close(in);
	close(out);
}

void	initialize_file_descriptors(t_data *data, t_cmd *head, t_cmd *cmd)
{
	int	in;
	int	out;

	data->here_doc = false;
	if (ft_strcmp("here_doc", data->argv[1]) != CMP_OK)
	{
		in = open(data->argv[1], O_RDONLY);
		out = open(data->argv[data->argc - 1], O_CREAT | O_RDWR | O_TRUNC,
				0644);
		close_fd(data, in, out);
		head->in_fd = READ;
	}
	else
	{
		data->here_doc = true;
		out = open(data->argv[data->argc - 1], O_CREAT | O_RDWR | O_APPEND,
				0644);
		if (out > 0)
			close(out);
	}
	cmd->out_fd = WRITE;
}
