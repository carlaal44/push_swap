/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:53:58 by carfern2          #+#    #+#             */
/*   Updated: 2025/05/22 08:06:47 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_duplicate_arg(t_stack *stack)
{
	t_stack	*next_num;

	while (stack)
	{
		next_num = stack->next;
		while (next_num != NULL)
		{
			if (stack->num == next_num->num)
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(EXIT_SUCCESS);
			}
			next_num = next_num->next;
		}
		stack = stack->next;
	}
}

void	stack_add_node(t_stack **stack, char **nums, int *index)
{
	int		j;
	long	num;
	t_stack	*node;

	num = 0;
	if (!nums[1])
	{
		num = ft_atol_ps(nums[0]);
		if (num == (long)INT_MAX + 1)
			ft_putstr_fd("Error\n", STDERR_FILENO);
		node = new_node((*index)++, num);
		add_node_back(stack, node);
	}
	else
	{
		j = 0;
		while (nums[j])
		{
			num = ft_atol_ps(nums[j++]);
			if (num == (long)INT_MAX + 1)
				ft_putstr_fd("Error\n", STDERR_FILENO);
			node = new_node((*index)++, num);
			add_node_back(stack, node);
		}
	}
}

void	stack_creator(char *av[], t_stack **stack_a)
{
	int		i;
	int		index;
	char	**numbers;

	i = 0;
	index = 1;
	while (av[++i])
	{
		if (av[i][0] != '\0')
		{
			numbers = ft_split(av[i], ' ');
			stack_add_node(stack_a, numbers, &index);
			stack_duplicate_arg(*stack_a);
			free_matrix(numbers);
		}
		else
			ft_putstr_fd("Error\n", STDERR_FILENO);
	}
}
