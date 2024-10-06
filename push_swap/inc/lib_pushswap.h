/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pushswap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:56:02 by hbourlot          #+#    #+#             */
/*   Updated: 2024/08/25 13:23:32 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSHSWAP_H
# define LIB_PUSHSWAP_H

# include "../get_next_line/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include "../printf/inc/ft_printf.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ERROR "Error\n"

struct					s_stack
{
	int					content;
	struct s_stack		*next;
};

typedef struct s_stack	t_stack;

// functions in "/SRC/stack.c" file
t_stack					*stack_new(int value);
t_stack					*stack_last(t_stack **lst);
int						stack_add_back(t_stack **head, t_stack *node);
int						stack_add_front(t_stack **head, t_stack *node);

// functions in "/SRC/move.c" file
int						ft_swap(t_stack **stack, char *str);
int						ft_shift_up(t_stack **stack_1, char *str);
int						ft_shift_down(t_stack **stack_1, char *str);
int						ft_push(t_stack **stack_1, t_stack **stack_2,
							char *echo);
// functions in "/SRC/stack_math_utils.c" file
int						stack_min_nbr(t_stack **stack);
int						stack_max_nbr(t_stack **stack);
int						make_positive(int nbr);
int						get_min_value(int a, int b);

// functions in "/SRC/stack_operations.c" file
void					sort_three(int first, int second, int last,
							t_stack **stack);
int						move_min_top(t_stack **stack, char *str);
int						partition_stack_by_avg(t_stack **stack);
int						get_max_value(int a, int b);
int						free_all(t_stack **stack);

// functions in "/SRC/stack_utils.c" file
int						get_closest_max(int nbr, t_stack **stack);
int						get_closest_min(int nbr, t_stack **stack);
int						print_stack(t_stack **stack);
void					free_split(char **split);

// functions in "/SRC/stack_validation.c" file
int						ft_check_duplicate(t_stack **stack_a);
int						sort_checker(t_stack **stack);
int						stack_idx(t_stack **stack, int value);
int						stack_value(t_stack **stack, int idx);
int						stack_n_elements(t_stack **stack);

// functions in "/SRC/count_moves.c" file
int						to_go(int value_a, t_stack **stack_2, int cond);
int						best_to_send(t_stack **stack_1, t_stack **stack_2,
							int cond);

// functions in "/SRC/cal_moves.c" file
void					make_mvs(t_stack **stack_1, t_stack **stack_2,
							int cond);

// functions in "/SRC/checker.c" file
int						check_letter(char *argv[]);
int						check_int(char *argv[]);
int						validate_input(char **argv);
int						validate_numbers(char *argv[]);

// functions in "/SRC/algorithm.c" file
int						create_stack(t_stack **stack_1, char *argv[]);
int						algorithm(t_stack **stack_1, t_stack **stack_2);

// ----- BONUS -----

// functions in "/BONUS/tests_bonus.c" file
int						execute_move(char *src, t_stack **stack_a,
							t_stack **stack_b);

// functions in "/BONUS/tests_utils.c" file
int						check_movs(char *lines, t_stack **stack_a,
							t_stack **stack_b);

// functions in "/BONUS/process_moves.c" file
int						process_moves(t_stack **stack_a, t_stack **stack_b);

#endif