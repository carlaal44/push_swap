/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:37:17 by carfern2          #+#    #+#             */
/*   Updated: 2025/01/17 20:37:17 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *a)
{
	t_node	*temp;
	t_node	*first;

	if (a->size < 2)
		return;
	first = a->top;
	a->top = a->top->next;
	temp = a->top;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}
