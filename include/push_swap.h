/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:30:57 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 15:14:40 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <unistd.h>

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
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	optimize_moves(t_stack *stack_a, t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

void	sort_large_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);

void	free_stack(t_stack *stack);
//aquí va init_stack cuando la cree si la necesito
int		pop(t_stack *stack);
void	push_node(t_stack *dest, t_stack *src);
void	push_value(t_stack *stack, int value);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap_stack(t_stack *stack);

void	quicksort(int *arr, int low, int high);
t_stack	*create_stack(void);
int		is_sorted(t_stack *stack);
void	error_and_exit(char *message);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		*stack_to_array(t_stack *stack);
void	swap_int(int *a, int *b);
int		partition(int *arr, int low, int high);

int		validate_input(int argc, char **argv);

#endif
