/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:18:22 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/03 15:49:43 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	int		value;

	if (a->size == 0)
		return ;
	value = pop(a);
	push(b, value);
}
