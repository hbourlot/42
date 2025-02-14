/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:55:55 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/24 12:54:04 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;
# define DELAY_MS 50
# define NO_FOOD_PARAMETER -1

typedef enum state
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
}						t_state;

typedef struct s_data
{
	int					id_dead;
	bool				simulation;
	bool				has_philo_dead;
	t_mutex				write_lock;
	t_mutex				dead_lock;
	t_mutex				meal_lock;
	t_mutex				simulation_lock;
	size_t				start_time;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_of_meals;
}						t_data;

typedef struct philo
{
	int					id;
	int					had_meals;
	size_t				last_meal_time;
	t_state				status;
	pthread_t			thread;
	t_mutex				*left_fork;
	t_mutex				*right_fork;
	bool				is_initialized;
	bool				has_left_fork;
	t_data				*data;
	struct philo		*next;
}						t_philo;

// -- initialize
int						initialize_simulation(t_philo **philo);

// -- parsing
int						parsing(int argc, char *argv[]);

// -- process
void					*routine(void *arg);
void					*monitor(void *arg);
void					eating(t_philo *philo, t_data *table);

// -- pthread
int						init_data(t_data *table, int argc, char *argv[]);
t_philo					*create_philos(char *argv[], t_data *data);

// -- pthread_utils
int						simulation_is_running(t_data *table);

// -- time
size_t					get_time(void);
void					show_philo_event(t_data *table, int philo_id,
							t_state action_idx);
void					ft_wait(t_data *table, int time_to_wait);

// -- free
void					cleanup_mutex(t_philo *philo);
void					free_philosophers(t_philo **philo);
int						cleanup_data(t_philo **philo);

// -- Utils
void					delay_simulation(t_data *table);
int						ft_atoi(const char *nptr);
void					ft_putstr_fd(char *s, int fd);
int						get_think_time(int time_to_die, int time_to_eat,
							int time_to_sleep);
int						ft_isdigit(int c);

#endif