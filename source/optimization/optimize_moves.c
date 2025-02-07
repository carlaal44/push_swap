/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:53:42 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/07 12:02:29 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	optimize_rotations(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top && stack_b->top
		&& stack_a->top->value > stack_a->top->next->value
		&& stack_b->top->value > stack_b->top->next->value)
	{
		rotate_both(stack_a, stack_b);
	}
}

static void	optimize_swaps(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top && stack_b->top
		&& stack_a->top->value > stack_a->top->next->value
		&& stack_b->top->value > stack_b->top->next->value)
	{
		swap_both(stack_a, stack_b);
	}
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	optimize_moves(t_stack *stack_a, t_stack *stack_b)
{
	optimize_rotations(stack_a, stack_b);
	optimize_swaps(stack_a, stack_b);
}
