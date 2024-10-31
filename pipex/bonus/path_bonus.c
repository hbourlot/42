/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:45:50 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/28 09:51:54 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

char	*find_properly_path(char *cmd, char **all_paths)
{
	int		i;
	char	*total_path;

	i = 0;
	while (all_paths[i])
	{
		total_path = ft_append_and_free(ft_strjoin(all_paths[i], "/"), cmd);
		if (access(total_path, F_OK) == CMP_OK || !all_paths[i + 1])
			return (total_path);
		free(total_path);
		i++;
	}
	return (NULL);
}

char	*find_executable_path(char *path_var, char *cmd)
{
	char		**envp_paths;
	char		*path;
	const char	*default_paths[] = {BIN, SBIN, UBIN, USBIN, ULBIN, ULSBIN,
		NULL};

	if (!path_var || !*path_var)
		return (find_properly_path(cmd, (char **)default_paths));
	envp_paths = ft_split(path_var, ':');
	if (!envp_paths)
		return (NULL);
	path = find_properly_path(cmd, envp_paths);
	free_split(envp_paths);
	return (path);
}

char	*get_path(char *argv, t_env_info *info)
{
	char	**split;
	char	*path;

	if (!argv || !*argv)
		return (NULL);
	if (info->is_path_empty)
		return (ft_strdup(argv));
	if (info->has_path == false)
		return (ft_strdup(argv));
	split = ft_split(argv, ' ');
	if (!split)
		return (NULL);
	if (ft_strchr(split[0], '/'))
		path = ft_strdup(split[0]);
	else
		path = find_executable_path(info->path, split[0]);
	free_split(split);
	return (path);
}
