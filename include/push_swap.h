/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:30:57 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/07 13:23:42 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	push(t_stack *stack, int value);
void	pop(t_stack *stack);

void	error_and_exit(char *message);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		*stack_to_array(t_stack *stack);
void	quicksort(int *arr, int low, int high);

t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
void	push_value(t_stack *stack, int value);

void	sort_large_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	optimize_moves(t_stack *stack_a, t_stack *stack_b);

int		validate_input(int argc, char **argv);

int		is_sorted(t_stack *stack);

#endif
