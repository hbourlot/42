/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:52:34 by hbourlot          #+#    #+#             */
/*   Updated: 2024/07/14 22:28:01 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/get_next_line.h"

char	*get_next_line(int fd)
{
	char		*rest;
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (BUFFER_SIZE < 1)
		return (NULL);
	bytes = 42;
	rest = NULL;
	while (bytes != 0)
	{
		if (buffer[0] == 0)
			bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (rest)
				free(rest);
			return (NULL);
		}
		rest = ft_strjoin_mod(rest, buffer);
		if (set_buffer(buffer) == 1)
			return (rest);
	}
	return (rest);
}

// #include <stdio.h>

// int	main(void)
//{
//	int fd;
//	fd = open("laele.txt", O_RDONLY);
//	if (fd < 0)
//		return (1);
//    char    *pt = get_next_line(fd);
//    char    *pt1 = get_next_line(fd);
//    char    *pt2 = get_next_line(fd);
//    char    *pt3 = get_next_line(fd);
//	printf ("%s", pt);
//	printf ("%s", pt1);
//	printf ("%s", pt2);
//	printf ("%s", pt3);
//    free(pt);
//    free(pt1);
//    free(pt2);
//    free(pt3);
//}

// int	main(void)
// {
// 	int		fds;
// 	char	*a;
// 	int		cont;

// 	cont = 1;
// 	fds = open("test.txt", O_RDONLY);
//     //fds = open("laele.txt", O_RDONLY);
// 	printf("\n");
// 	while ((a = get_next_line(fds)) != NULL)
// 	{
// 		printf("%i - %s", cont, a);
// 		free(a);
// 		cont++;
// 	}

// 	printf("\n\n");
// 	return (0);
// }
