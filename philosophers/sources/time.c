/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:10:26 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/14 15:36:10 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_time(void)
{
	struct timeval	val;

	if (gettimeofday(&val, NULL))
		return (ft_putstr_fd("Error gettimeofday function.\n", 2), -1);
	return (val.tv_sec * 1000 + (val.tv_usec / 1000));
}

void	ft_wait(t_data *table, int time_to_wait)
{
	size_t	time;

	time = get_time() + time_to_wait;
	while (get_time() < time)
	{
		if (!simulation_is_running(table))
			break ;
		usleep(100);
	}
}

void	show_philo_event(t_data *table, int philo_id, t_state action_idx)
{
	const char	*actions[] = {"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died", NULL};

	if (!simulation_is_running(table))
		return ;
	pthread_mutex_lock(&table->write_lock);
	printf("%d %d %s\n", (int)(get_time() - table->start_time), philo_id,
		actions[action_idx]);
	pthread_mutex_unlock(&table->write_lock);
}
