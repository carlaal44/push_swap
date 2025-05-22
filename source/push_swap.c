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

#include "./include/push_swap.h"

void	show_lst(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	while (aux != NULL)
	{
		printf("STACK NODE	->	%p\n", *stack);
		if (aux->prev)
			printf("PREV NUM[%d]	->	%ld\n", aux->prev->id, aux->prev->num);
		printf("NUM NODE[%d]	->	%ld\n", aux->id, aux->num);
		printf("COST NODE	->	%d\n", (*stack)->cost);
		printf("ABOVE MEDIAN	->	%d\n", aux->median);
		printf("MIN COST	->	%d\n", aux->min_cost);
		printf("TARGET NODE	->	%p\n", aux->target);
		printf("PREV NODE	->	%p\n", aux->prev);
		printf("NEXT NODE	->	%p\n\n\n", aux->next);
		aux = aux->next;
	}
}

int	main(int ac, char *av[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	if (ac > 1)
	{
		stack_creator(av, stack_a);
		if (!stack_sorted(*stack_a))
		{
			if (stack_len(*stack_a) == 2)
				swap(stack_a, stack_b, MOVESA);
			else if (stack_len(*stack_a) == 3)
				sort_stack_three(stack_a);
			else
				sort_stack(stack_a, stack_b);
		}
		free_list(stack_a);
		free_list(stack_b);
	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
}
