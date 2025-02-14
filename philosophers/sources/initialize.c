/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:40:07 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/24 09:09:18 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	initialize_forks(t_philo **philo)
{
	t_philo	*tmp;

	tmp = *philo;
	while (true)
	{
		if (!tmp->left_fork || pthread_mutex_init(tmp->left_fork, NULL))
			return (ft_putstr_fd("Error initializing left fork mutex.\n", 2),
				-1);
		tmp->has_left_fork = true;
		tmp = tmp->next;
		if (tmp == *philo)
			break ;
	}
	return (0);
}

static int	initialize_threads(t_philo **philo, pthread_t *tracker)
{
	t_philo	*tmp;

	tmp = *philo;
	if ((*philo)->data->time_to_die != 0)
		if (pthread_create(tracker, NULL, &monitor, tmp))
			return (ft_putstr_fd("Error initializing pthread.\n", 2), -1);
	while (true)
	{
		if (pthread_create(&tmp->thread, NULL, &routine, tmp))
			return (ft_putstr_fd("Error initializing pthread.\n", 2), -1);
		tmp->is_initialized = true;
		tmp = tmp->next;
		if (tmp == *philo)
			break ;
	}
	return (0);
}

int	initialize_simulation(t_philo **philo)
{
	pthread_t	tracker;

	if (initialize_forks(philo) || initialize_threads(philo, &tracker))
		return (-1);
	pthread_join(tracker, NULL);
	return (0);
}

static int	init_data_mutex(t_data *table)
{
	if (pthread_mutex_init(&table->dead_lock, NULL))
		return (ft_putstr_fd("Error init mutex dead_lock.\n", 2), -1);
	if (pthread_mutex_init(&table->write_lock, NULL))
		return (pthread_mutex_destroy(&table->dead_lock),
			ft_putstr_fd("Error init mutex write_lock.\n", 2), -1);
	if (pthread_mutex_init(&table->meal_lock, NULL))
	{
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->write_lock);
		return (ft_putstr_fd("Error init mutex meal_lock.\n", 2), -1);
	}
	if (pthread_mutex_init(&table->simulation_lock, NULL))
	{
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->write_lock);
		pthread_mutex_destroy(&table->meal_lock);
		return (ft_putstr_fd("Error init mutex simulation_lock.\n", 2), -1);
	}
	return (0);
}

int	init_data(t_data *table, int argc, char *argv[])
{
	memset(table, 0, sizeof(t_data));
	if (init_data_mutex(table))
		return (-1);
	table->simulation = true;
	table->start_time = get_time() + DELAY_MS;
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->nbr_of_meals = ft_atoi(argv[5]);
	else
		table->nbr_of_meals = NO_FOOD_PARAMETER;
	return (0);
}
