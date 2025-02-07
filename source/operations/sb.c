/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:11:23 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/07 13:31:09 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(t_stack *b)
{
	int		temp;

	if (b->size < 2)
		return (0);
	temp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = temp;
}
