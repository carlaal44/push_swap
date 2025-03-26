/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:54:10 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/07 12:17:11 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*init_stack(int argc, char **argv)
{
	t_stack		*stack;
	int			i;

	stack = create_stack();
	if (!stack)
		error_and_exit("Error: No se pudo crear la pila\n");
	i = argc - 1;
	while (i > 0)
	{
		push_value(stack, ft_atoi(argv[i]));
		i--;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (!validate_input (argc, argv))
		error_and_exit("Error: Entrada no válida\n");
	stack_a = init_stack (argc, argv);
	stack_b = create_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		error_and_exit("Error: No se pudo crear la pila\n");
	}
	if (!is_sorted(stack_a))
	{
		if (stack_a->size <= 3)
			sort_small_stack(stack_a, stack_b);
		else
			sort_large_stack(stack_a, stack_b);
		optimize_moves(stack_a, stack_b);
	}
	free_stack (stack_a);
	free_stack (stack_b);
	return (0);
}
