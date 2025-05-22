/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:10:55 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 15:21:29 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_node(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	prev_last = last_node(*stack)->prev;
	last = last_node(*stack);
	if (*stack)
	{
		last->prev = NULL;
		last->next = *stack;
		last->next->prev = last;
		prev_last->next = NULL;
		*stack = last;
	}
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVERRA)
	{
		reverse_rotate_node(stack_a);
		ft_putstr(RRA);
	}
	else if (move == MOVERRB)
	{
		reverse_rotate_node(stack_b);
		ft_putstr(RRB);
	}
	else if (move == MOVERRR)
	{
		reverse_rotate_node(stack_a);
		reverse_rotate_node(stack_b);
		ft_putstr(RRR);
	}
}
