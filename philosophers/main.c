/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:08:45 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/25 15:39:24 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_data	data;

	if (parsing(argc, argv))
		return (1);
	if (init_data(&data, argc, argv))
		return (1);
	philo = create_philos(argv, &data);
	if (!philo)
		return (1);
	if (initialize_simulation(&philo))
		return (cleanup_data(&philo), 1);
	if (cleanup_data(&philo))
		return (1);
	return (0);
}

/*
		* ./philo nbr_of_philosophers || time_to_die || time_to_eat
		*	|| time_to_sleep
		*	|| nbr_of_times_each_philosophers_must_eat
		*
		*	argv[1] = number_of_philosophers
		*	argv[2] = time_to_die (in milliseconds)
		*		if a philosopher didn't start eating
		*           since beginning of simulation of their last meal 
		*			or beginning of the simulation
		*	argv[3] = time_to_eat (in milliseconds) // time eating
		*	argv[4] = time_to_sleep (in milliseconds) // time sleeping
		*	argv[5] = number_of_times_each_philosopher_must_eat
		*	 (optional argument)
*/
