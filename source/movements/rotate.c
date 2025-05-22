/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:11:21 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 15:21:22 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#
#include "../include/push_swap.h"

void	rotate_node(t_stack **stack)
{
	t_stack	*next;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	next = (*stack)->next;
	last = last_node(*stack);
	if (*stack)
	{
		next->prev = NULL;
		last->next = *stack;
		(*stack)->next = NULL;
		(*stack)->prev = last;
		*stack = next;
	}
}

void	rotate(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVERA)
	{
		rotate_node(stack_a);
		ft_putstr(RA);
	}
	else if (move == MOVERB)
	{
		rotate_node(stack_b);
		ft_putstr(RB);
	}
	else if (move == MOVERR)
	{
		rotate_node(stack_a);
		rotate_node(stack_b);
		ft_putstr(RR);
	}
}
