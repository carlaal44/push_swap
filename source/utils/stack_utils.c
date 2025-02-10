/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:40:58 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 15:17:47 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h" 

void	quicksort(int *arr, int low, int high)
{
	int		pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

t_stack	*create_stack(void)
{
	t_stack		*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	t_node		*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current ->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
