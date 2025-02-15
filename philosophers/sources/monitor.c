/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:46:29 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/14 14:50:16 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_has_died(t_philo *philo, t_data *table)
{
	size_t	time_since_last_meal;

	pthread_mutex_lock(&table->meal_lock);
	pthread_mutex_lock(&table->simulation_lock);
	time_since_last_meal = get_time() - philo->last_meal_time;
	if ((int)time_since_last_meal > table->time_to_die)
	{
		table->id_dead = philo->id;
		table->has_philo_dead = true;
		table->simulation = false;
		pthread_mutex_unlock(&table->meal_lock);
		pthread_mutex_unlock(&table->simulation_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->meal_lock);
	pthread_mutex_unlock(&table->simulation_lock);
	return (0);
}

int	eat_enough(t_philo *philo, t_data *table)
{
	t_philo	*tmp;
	int		meals_remaining;

	tmp = philo;
	pthread_mutex_lock(&table->meal_lock);
	while (true)
	{
		meals_remaining = tmp->had_meals < table->nbr_of_meals;
		if (meals_remaining || table->nbr_of_meals == NO_FOOD_PARAMETER)
		{
			pthread_mutex_unlock(&table->meal_lock);
			return (0);
		}
		tmp = tmp->next;
		if (tmp == philo)
			break ;
	}
	pthread_mutex_unlock(&table->meal_lock);
	pthread_mutex_lock(&table->simulation_lock);
	table->simulation = false;
	pthread_mutex_unlock(&table->simulation_lock);
	return (1);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	t_data	*table;

	philo = (t_philo *)arg;
	table = philo->data;
	delay_simulation(table);
	while (true)
	{
		if (philo_has_died(philo, table))
		{
			pthread_mutex_lock(&table->write_lock);
			printf("%ld %d died\n", get_time() - table->start_time,
				table->id_dead);
			pthread_mutex_unlock(&table->write_lock);
			break ;
		}
		if (eat_enough(philo, table))
			break ;
		usleep(500);
	}
	return (NULL);
}
