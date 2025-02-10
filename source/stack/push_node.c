/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:27:24 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 15:21:34 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_node(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dest->top;
	dest->top = temp;
	src->size--;
	dest->size++;
}
