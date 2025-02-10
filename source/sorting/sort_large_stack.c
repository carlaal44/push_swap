/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:53:51 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 15:18:31 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_median(t_stack *stack)
{
	int		*arr;
	int		size;
	int		median;

	arr = stack_to_array(stack);
	size = stack->size;
	quicksort(arr, 0, size - 1);
	median = arr[size / 2];
	free(arr);
	return (median);
}

static void	finalize_sort(t_stack *stack)
{
	while (!is_sorted(stack))
	{
		if (stack->top->value > stack->top->next->value)
			swap_stack(stack);
		else
			rotate(stack);
	}
}

void	sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		median;

	if (is_sorted(stack_a))
		return ;
	median = find_median(stack_a);
	while (stack_a->size > 3)
	{
		if (stack_a->top->value < median)
			push_node(stack_b, stack_a);
		else
			rotate(stack_a);
	}
	sort_small_stack(stack_a, stack_b);
	while (stack_b->size > 0)
		push_node(stack_a, stack_b);
	if (!is_sorted(stack_a))
		finalize_sort(stack_a);
}
