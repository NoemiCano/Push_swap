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

static void	ft_insert(t_stack *a, t_stack *b, t_cost moves, t_ops *ops)
{
	while (moves.a > 0 && moves.b > 0)
	{
		rr(a, b, ops);
		moves.a--;
		moves.b--;
	}
	while (moves.a < 0 && moves.b < 0)
	{
		rrr(a, b, ops);
		moves.a++;
		moves.b++;
	}
	while (moves.a > 0)
		(ra(a, ops), moves.a--);
	while (moves.a < 0)
		(rra(a, ops), moves.a++);
	while (moves.b > 0)
		(rb(b, ops), moves.b--);
	while (moves.b < 0)
		(rrb(b, ops), moves.b++);
	pa(a, b, ops);
}

static void	ft_final_rotate(t_stack *a, t_ops *ops)
{
	t_node	*tmp;
	size_t	i;

	tmp = a->head;
	i = 0;
	while (tmp->index != 0)
	{
		tmp = tmp->next;
		i++;
	}
	while (a->head->index != 0)
	{
		if (i <= (size_t)a->size - i)
			ra(a, ops);
		else if (i > (size_t)a->size - i)
			rra(a, ops);
	}
}

void	ft_simple_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	t_cost	moves;

	while (a->size > 3)
		pb(a, b, ops);
	ft_sort3(a, ops);
	while (b->size)
	{
		moves = ft_find_cheapest(a, b);
		ft_insert(a, b, moves, ops);
	}
	ft_final_rotate(a, ops);
}
