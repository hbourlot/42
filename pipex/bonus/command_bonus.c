/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:14:40 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/28 17:34:44 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

static int	add_cmd(t_cmd **command, t_cmd *new)
{
	t_cmd	*current;

	if (!command || !new)
		return (1);
	if (!(*command))
	{
		*command = new;
		return (0);
	}
	if (command && new)
	{
		current = NULL;
		current = *command;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (0);
}

static t_cmd	*new_cmd(char *argv[], t_env_info *info, char *envp[], int idx)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->envp = envp;
	new->next = NULL;
	new->path = NULL;
	new->args = NULL;
	new->path = get_path(argv[idx], info);
	new->args = get_args(argv[idx]);
	new->in_fd = -1;
	new->out_fd = -1;
	return (new);
}

void	create_commands(t_data *data)
{
	int		i;
	t_cmd	*cmd;
	t_cmd	*head;

	i = 2;
	if (ft_strcmp("here_doc", data->argv[1]) == 0)
		i = 3;
	head = NULL;
	cmd = NULL;
	while (i < data->argc - 1)
	{
		cmd = new_cmd(data->argv, &data->env_info, data->envp, i);
		if (add_cmd(&head, cmd))
			return (ft_close(1, data, "Malloc failed"));
		if (!cmd->args || !cmd->path)
			return (ft_close(127, data, "'': Command not found\n"));
		i++;
	}
	data->n_cmd = i - 2;
	if (ft_strcmp("here_doc", data->argv[1]) == 0)
		data->n_cmd = i - 3;
	data->command = head;
	initialize_file_descriptors(data, head, cmd);
}
