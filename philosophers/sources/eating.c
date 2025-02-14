/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:36:54 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/25 13:38:58 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	update_meal(t_philo *philo, t_data *table)
{
	pthread_mutex_lock(&table->meal_lock);
	philo->last_meal_time = get_time();
	philo->had_meals += 1;
	pthread_mutex_unlock(&table->meal_lock);
}

static int	lock_forks(t_philo *philo, t_data *table)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		show_philo_event(table, philo->id, FORK);
		pthread_mutex_lock(philo->left_fork);
		show_philo_event(table, philo->id, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		show_philo_event(table, philo->id, FORK);
		pthread_mutex_lock(philo->right_fork);
		show_philo_event(table, philo->id, FORK);
	}
	return (0);
}

void	eating(t_philo *philo, t_data *table)
{
	lock_forks(philo, table);
	show_philo_event(table, philo->id, EATING);
	ft_wait(table, table->time_to_eat);
	update_meal(philo, table);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
