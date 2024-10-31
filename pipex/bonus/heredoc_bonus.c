/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:38:59 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/29 09:47:40 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

static int	cleanup_and_exit(char *text, int error_code)
{
	if (text)
		free(text);
	write(1, "\n", 1);
	return (error_code);
}

static int	read_eof(int *pipe_id, char *limiter)
{
	char	*text;

	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		text = get_next_line(STDIN_FILENO);
		if (!text)
			return (cleanup_and_exit(NULL, -1));
		if (!ft_strcmp(limiter, text))
			break ;
		if (ft_strlen(text) == 0)
			return (cleanup_and_exit(text, -1));
		if (!ft_strchr(text, '\n') && !ft_strncmp(text, limiter, ft_strlen(text)
				- 1))
			return (cleanup_and_exit(text, -1));
		ft_putstr_fd(text, pipe_id[1]);
		free(text);
	}
	return (cleanup_and_exit(text, 0));
}

static void	handle_child_process(t_data *data, t_pipe_info *p)
{
	char	*limiter;

	limiter = ft_strjoin(data->argv[2], "\n");
	if (!limiter)
		
		ft_close(1, data, "Memory Allocation Error");
	close(p->pipe_id[0]);
	if (read_eof(p->pipe_id, limiter) == -1)
	{
		free(limiter);
		close(p->pipe_id[1]);
		ft_close(1, data, "Error reading EOF");
	}
	free(limiter);
	close(p->pipe_id[1]);
	clear_all(&data->command);
	exit(0);
}

static void	handle_parent_process(t_data *data, t_process_info *process,
		t_pipe_info *p)
{
	close(p->pipe_id[1]);
	process->wait = waitpid(process->pid, &process->w_status, 0);
	if (process->wait < 0)
		ft_close(1, data, "Wait error");
	p->prev_fd = p->pipe_id[0];
}

void	here_doc(t_data *data, t_process_info *process, t_pipe_info *p)
{
	if (pipe(p->pipe_id) == -1)
		ft_close(1, data, "Pipe Error");
	process->pid = fork();
	if (process->pid == -1)
		ft_close(1, data, "Fork Error");
	if (process->pid == 0)
		handle_child_process(data, p);
	else
		handle_parent_process(data, process, p);
}
