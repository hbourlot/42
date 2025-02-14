/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:32:35 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/24 08:58:33 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	cleanup_mutex(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	pthread_mutex_destroy(&tmp->data->meal_lock);
	pthread_mutex_destroy(&tmp->data->dead_lock);
	pthread_mutex_destroy(&tmp->data->write_lock);
	pthread_mutex_destroy(&tmp->data->simulation_lock);
	while (true)
	{
		if (tmp->left_fork && tmp->has_left_fork)
			pthread_mutex_destroy(tmp->left_fork);
		if (tmp->left_fork)
		{
			free(tmp->left_fork);
			tmp->left_fork = NULL;
		}
		tmp = tmp->next;
		if (tmp == philo)
			break ;
	}
}

void	free_philosophers(t_philo **philo)
{
	t_philo	*tmp;
	t_philo	*next;

	tmp = *philo;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
		if (tmp == *philo)
			break ;
	}
	*philo = NULL;
}

int	cleanup_data(t_philo **philo)
{
	t_philo	*tmp;

	tmp = *philo;
	while (true)
	{
		if (tmp->is_initialized && pthread_join(tmp->thread, NULL))
			write(2, "Error at pthread_join.\n", 23);
		tmp = tmp->next;
		if (*philo == tmp)
			break ;
	}
	cleanup_mutex(*philo);
	free_philosophers(philo);
	return (0);
}
