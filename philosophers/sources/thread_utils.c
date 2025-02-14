/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:17:14 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/23 18:10:55 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	simulation_is_running(t_data *table)
{
	int	condition;

	condition = 0;
	pthread_mutex_lock(&table->simulation_lock);
	if (table->simulation == true)
		condition = 1;
	pthread_mutex_unlock(&table->simulation_lock);
	return (condition);
}
