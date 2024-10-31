/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:35:38 by hbourlot          #+#    #+#             */
/*   Updated: 2024/10/31 10:33:10 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int		res;

	init_data(&data, argc, argv, envp);
	init_s_envp(&data);
	parsing_envp(&data);
	res = pipex(&data);
	return (res);
}
