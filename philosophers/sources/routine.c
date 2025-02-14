/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:42:27 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/25 15:49:33 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	sleeping_thinking(t_philo *philo, t_data *table)
{
	int	time_to_think;

	if (philo->status == THINKING || philo->status == EATING
		|| philo->status == 0)
	{
		philo->status = SLEEPING;
		show_philo_event(table, philo->id, SLEEPING);
		ft_wait(table, table->time_to_sleep);
	}
	time_to_think = get_think_time(table->time_to_die, table->time_to_eat,
			table->time_to_sleep);
	if (philo->status == SLEEPING || philo->status == EATING
		|| philo->status == 0)
	{
		philo->status = THINKING;
		show_philo_event(table, philo->id, THINKING);
		ft_wait(table, time_to_think);
	}
}

static int	is_only_one_philo(t_philo *philo, t_data *table)
{
	if (philo == philo->next)
	{
		pthread_mutex_lock(philo->left_fork);
		show_philo_event(table, philo->id, FORK);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*table;

	philo = (t_philo *)arg;
	table = philo->data;
	if (table->time_to_die == 0)
		return (NULL);
	delay_simulation(table);
	if (is_only_one_philo(philo, table))
		return (NULL);
	if (!(philo->id % 2))
		ft_wait(table, 20);
	while (simulation_is_running(table))
	{
		eating(philo, table);
		sleeping_thinking(philo, table);
	}
	return (NULL);
}
