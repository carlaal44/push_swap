/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:10:55 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 15:21:29 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_rotate(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	second_last = stack->top;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
