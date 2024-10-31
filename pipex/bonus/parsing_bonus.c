/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:35:26 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/28 09:51:40 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

void	parsing_envp(t_data *data)
{
	int			i;
	t_env_info	*info;

	info = &data->env_info;
	i = 0;
	if (!data->envp || !*data->envp)
	{
		info->has_envp = false;
		return ;
	}
	info->has_envp = true;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == CMP_OK)
		{
			info->has_path = true;
			if (ft_strlen(data->envp[i] + 5) == CMP_OK)
				info->is_path_empty = true;
			else
				info->path = data->envp[i] + 5;
			break ;
		}
		i++;
	}
}

void	init_data(t_data *data, int argc, char *argv[], char *envp[])
{
	data->here_doc = false;
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->pipe_info.prev_fd = -1;
	data->pipe_info.pipe_id[0] = -1;
	data->pipe_info.pipe_id[1] = -1;
	data->process_info.wait = 0;
	data->process_info.w_status = 0;
}

void	init_s_envp(t_data *data)
{
	data->env_info.has_envp = false;
	data->env_info.has_path = false;
	data->env_info.is_path_empty = false;
	data->env_info.path = NULL;
}
