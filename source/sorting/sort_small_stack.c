/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:53:54 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/07 12:06:30 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	sort_two_elements(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap(stack);
}

static void	sort_three_elements(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap(stack);
	if (!is_sorted(stack))
		rotate(stack);
	if (stack->top->value > stack->top->next->value)
		swap(stack);
	if (!is_sorted(stack))
		reverse_rotate(stack);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		sort_two_elements(stack_a);
	else if (stack_a->size == 3)
		sort_three_elements(stack_a);
}
