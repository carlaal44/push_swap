/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:53:54 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 15:19:40 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two_elements(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap_stack(stack);
}

static void	sort_three_elements(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap_stack(stack);
	if (!is_sorted(stack))
		rotate(stack);
	if (stack->top->value > stack->top->next->value)
		swap_stack(stack);
	if (!is_sorted(stack))
		reverse_rotate(stack);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		sort_two_elements(stack_a);
	else if (stack_a->size == 3)
		sort_three_elements(stack_a);
}
