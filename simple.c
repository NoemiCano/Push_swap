/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:42:21 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/24 00:01:08 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	ft_simple_sort(t_stack *a, t_stack *b)
{
	t_cost	moves;
	size_t	total_ops;

	total_ops = ft_assign_index(a);
	while (a->size > 3)
		pb(a, b);
	total_ops += (size_t)b->size;
	ft_sort3(a);
	while (b->size)
	{
		moves = ft_find_cheapest(a, b);
		total_ops += moves.total;
		ft_insert(a, b, moves);
	}
	return (ops);
}
