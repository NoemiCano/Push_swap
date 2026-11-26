/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:42:21 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/26 22:18:45 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	ft_insert(t_stack *a, t_stack *b, t_cost moves)
{
	while (moves.a > 0 && moves.b > 0)
	{
		rr(a, b);
		moves.a--;
		moves.b--;
	}
	while (moves.a < 0 && moves.b < 0)
	{
		rrr(a, b);
		moves.a++;
		moves.b++;
	}
	while (moves.a > 0)
		(ra(a), moves.a--);
	while (moves.a < 0)
		(rra(a), moves.a++);
	while (moves.b > 0)
		(rb(b), moves.b--);
	while (moves.b < 0)
		(rrb(b), moves.b++);
	pa(a, b);
	return (moves.total + 1);
}

size_t	ft_final_rotate(t_stack *a)
{
	t_node	*tmp;
	size_t	i;
	size_t	c;

	tmp = a->head;
	i = 0;
	c = 0;
	while (tmp->index != 0)
	{
		tmp = tmp->next;
		i++;
	}
	while (a->head->index != 0)
	{
		if (i <= (size_t)a->size - i)
			(ra(a), c++);
		else if (i > (size_t)a->size - i)
			(rra(a), c++);
	}
	return (c);
}

size_t	ft_simple_sort(t_stack *a, t_stack *b)
{
	t_cost	moves;
	size_t	total_ops;

	ft_assign_index(a);
	while (a->size > 3)
		pb(a, b);
	total_ops = (size_t)b->size;
	total_ops += ft_sort3(a);
	while (b->size)
	{
		moves = ft_find_cheapest(a, b);
		total_ops += ft_insert(a, b, moves);
	}
	total_ops += ft_final_rotate(a);
	return (total_ops);
}
