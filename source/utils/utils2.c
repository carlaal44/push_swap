/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:20:36 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 14:49:52 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int			*arr;
	int			i;
	t_node		*current;

	arr = (int *)malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

void	swap_int(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_int(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_int(&arr[i + 1], &arr[high]);
	return (i + 1);
}
