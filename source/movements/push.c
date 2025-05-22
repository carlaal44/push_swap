/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:27:24 by carfern2          #+#    #+#             */
/*   Updated: 2025/05/22 08:13:39 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_node(t_stack **stack, t_stack **node)
{
	t_stack	*aux;

	if (!stack || !(*node))
		return ;
	aux = *node;
	*node = (*node)->next;
	if (!(*stack))
	{
		*stack = aux;
		(*stack)->next = NULL;
	}
	else
	{
		aux->next = *stack;
		aux->prev = NULL;
		if (*node)
			(*node)->prev = NULL;
		(*stack)->prev = aux;
		*stack = aux;
	}
}

void	push(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVEPA)
	{
		push_node(stack_a, stack_b);
		ft_putstr(PA);
	}
	else if (move == MOVEPB)
	{
		push_node(stack_b, stack_a);
		ft_putstr(PB);
	}
}
