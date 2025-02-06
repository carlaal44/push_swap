/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:54:04 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/03 15:36:17 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	error_and_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;

	while (*str == ' ' || (*str>= '\t' && *str <= '\r'))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while(*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	while (*s)
	{
		write(fd,s,1);
		s++;
	}
}

int	*stack_to_array(t_stack *stack)
{
	int			*arr;
	int			i;
	t_node		*current;

	arr = (int *)malloc(sizeof(int) * stack->size)
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

void	quicksort(int *arr, int low, int high)
{
	int		pivot;
	int		i;
	int		j;
	int		temp;

	if (low < high)
	{
		pivot = arr[high];
		i = (low - 1);
		j = low;
		while (j <= high -1)
		{
			if (arr[j] < pivot)
			{
				i++;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;
		quicksort(arr, low, i);
		quicksort(arr, i + 2, high);
	}
}
