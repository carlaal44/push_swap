/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:06:36 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/10 13:38:19 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *a)
{
	int		temp;

	if (a->size < 2)
		return ;
	temp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = temp;
}
