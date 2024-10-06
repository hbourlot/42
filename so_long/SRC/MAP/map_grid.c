/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:40:24 by hbourlot          #+#    #+#             */
/*   Updated: 2024/09/20 17:18:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libso_long.h"

/// @brief Joins two strings, freeing the first one.
/// @param src1 The first string to join.
/// @param src2 The second string to join.
/// @return A new string that is the concatenation of src1 and src2,
/// or NULL on failure.
static char	*ft_str_join_map(char *src1, char *src2)
{
	char	*temp;
	char	*result;
	int		i;

	if (!src1 && src2[0] == '\0')
		return (NULL);
	temp = malloc(sizeof(char) * (ft_strlen(src1) + ft_strlen(src2) + 1));
	if (!temp)
		return (NULL);
	result = temp;
	i = 0;
	while (src1 && src1[i])
		*temp++ = src1[i++];
	free(src1);
	i = 0;
	while (src2 && src2[i])
	{
		*temp++ = src2[i];
		i++;
	}
	*temp = '\0';
	return (result);
}

static char	*read_and_concat_lines(int fd)
{
	char	*line;
	char	*res;

	res = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		res = ft_str_join_map(res, line);
		free(line);
		if (!res)
			return (NULL);
		line = get_next_line(fd);
	}
	return (res);
}

static int	is_valid_map_format(char *res)
{
	if (res && res[ft_strlen(res) - 1] == '\n')
	{
		free(res);
		fprintf(stderr, "Error: Invalid map format.\n");
		return (0);
	}
	return (1);
}

char	**load_grid_map(int fd)
{
	char	**grid;
	char	*res;

	res = read_and_concat_lines(fd);
	close(fd);
	if (!res || !is_valid_map_format(res))
		return (NULL);
	grid = ft_split(res, '\n');
	if (!grid)
		return (NULL);
	free(res);
	return (grid);
}
