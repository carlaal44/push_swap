/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:05:10 by carfern2          #+#    #+#             */
/*   Updated: 2025/05/22 08:13:53 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_node(t_stack **stack)
{
	t_stack	*aux;
	int		num;

	aux = *stack;
	if (*stack)
	{
		num = aux->next->num;
		aux->next->num = aux->num;
		aux->num = num;
	}
}

void	swap(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == MOVESA)
	{
		swap_node(stack_a);
		ft_putstr(SA);
	}
	else if (move == MOVESB)
	{
		swap_node(stack_b);
		ft_putstr(SB);
	}
	else if (move == MOVESS)
	{
		swap_node(stack_a);
		swap_node(stack_b);
		ft_putstr(SS);
	}
}
