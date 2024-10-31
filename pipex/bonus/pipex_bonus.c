/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:18:17 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/28 17:40:12 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

static void	child_process(t_data *data, t_cmd *command)
{
	if (do_dup2(data, command))
	{
		clear_all(&data->command);
		exit(EXIT_FAILURE);
	}
	execve(command->path, command->args, command->envp);
	error_execve(data, command);
}

static void	parent_process(t_cmd *command, t_pipe_info *p)
{
	if (command->next)
		close(p->pipe_id[1]);
	if (p->prev_fd != -1)
		close(p->prev_fd);
	if (command->next)
		p->prev_fd = p->pipe_id[0];
}

static void	execute_commands(t_data *data, t_process_info *process)
{
	t_pipe_info	*p;
	t_cmd		*cmd;

	p = &data->pipe_info;
	cmd = data->command;
	if (ft_strcmp("here_doc", data->argv[1]) == 0)
		here_doc(data, process, p);
	while (cmd)
	{
		if (cmd->next && pipe(p->pipe_id) == -1)
			return (ft_close(1, data, "Pipe Error"));
		process->pid = fork();
		if (process->pid < 0)
			return (ft_close(1, data, "PID Error"));
		else if (process->pid == 0)
			child_process(data, cmd);
		else
		{
			parent_process(cmd, p);
			cmd = cmd->next;
		}
	}
}

int	pipex(t_data *data)
{
	int				i;
	int				status;
	pid_t			prev_pid;
	t_process_info	*process;

	process = &data->process_info;
	i = 0;
	prev_pid = 0;
	if (data->argc <= 4)
		error(ERROR_ARGV_B, 1);
	create_commands(data);
	execute_commands(data, process);
	while (i < data->n_cmd)
	{
		process->pid = waitpid(-1, &process->w_status, 0);
		if (WIFEXITED(process->w_status) && process->pid > prev_pid)
			status = WEXITSTATUS(process->w_status);
		prev_pid = process->pid;
		i++;
	}
	clear_all(&data->command);
	return (status);
}
