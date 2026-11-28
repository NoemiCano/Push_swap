/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psinsert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 18:12:25 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/22 16:00:20 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	insert(t_stack *a, t_stack *b)
{
	pb(a, b);
	print_stacks(a, b);
	if (a->head->value > a->head->next->value)
		sa(a);
	print_stacks(a, b);
	if (b->head->value < a->head->value)
	{
		pa(a, b);
		print_stacks(a, b);
	}
	else if(b->head->value < a->head->next->value)
	{
		pb(a, b);
		print_stacks(a, b);
		rb(b);
		print_stacks(a, b);
		pa(a, b);
		print_stacks(a, b);
		pa(a, b);
		print_stacks(a, b);
	}
	else
	{
		pa(a, b);
		print_stacks(a, b);
		ra(a);
		print_stacks(a, b);
	}
}

int	main(void)
{
	t_stack a = {NULL, 0}; //las llaves hacen que puedas iniciar los valores internos
	t_stack b = {NULL, 0};

	t_node	f = {2100000000, NULL, NULL};
	t_node	s = {-999, NULL, NULL};
	t_node	t = {1, NULL, NULL};

	ft_stack_add_front(&a, &f);
	ft_stack_add_back(&a, &s);
	ft_stack_add_back(&a, &t);
	printf("Before: {%d, %d, %d}\n", a.head->value, a.head->next->value, a.head->prev->value);
	insert(&a, &b);
	printf("After: {%d, %d, %d}\n", a.head->value, a.head->next->value, a.head->prev->value);
}
