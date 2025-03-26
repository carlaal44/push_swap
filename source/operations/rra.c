/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:17:27 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/07 13:30:57 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack *a)
{
	t_node	*temp;
	t_node	*last;
	t_node	*second_last;

	if (a->size < 2)
		return ;
	temp = a->top;
	while (temp->next != NULL)
	{
		second_last = temp;
		temp = temp->next;
	}
	last = temp;
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
}
