/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:05:12 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/24 09:10:20 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	set_forks(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (true)
	{
		tmp->right_fork = tmp->next->left_fork;
		tmp = tmp->next;
		if (tmp == philo)
			break ;
	}
}

static t_philo	*allocate_philo(int *id, t_data *table)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->left_fork = malloc(sizeof(t_mutex));
	if (!philo->left_fork)
	{
		free(philo);
		return (NULL);
	}
	philo->id = (*id)++;
	philo->data = table;
	philo->last_meal_time = table->start_time;
	philo->next = NULL;
	return (philo);
}

t_philo	*create_philos(char *argv[], t_data *data)
{
	t_philo	*head;
	t_philo	*tmp;
	int		i;
	int		id;

	id = 1;
	head = allocate_philo(&id, data);
	if (!head)
		return (ft_putstr_fd("Error creating philosophers.\n", 2), NULL);
	tmp = head;
	i = 1;
	while (i < ft_atoi(argv[1]))
	{
		tmp->next = allocate_philo(&id, data);
		if (!tmp->next || !tmp->next->left_fork)
		{
			ft_putstr_fd("Error creating philosophers.\n", 2);
			return (cleanup_data(&head), NULL);
		}
		tmp = tmp->next;
		i++;
	}
	tmp->next = head;
	set_forks(head);
	return (head);
}
