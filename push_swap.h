/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:30:57 by carfern2          #+#    #+#             */
/*   Updated: 2025/01/17 20:30:57 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_nod
{
	int		value;
	struct	s_node *next;
} t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
} t_stack;

void sa(t_stack *a);
void sb(t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void push(t_stack *stack, int value);
void pop(t_stack *stack);
