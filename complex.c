/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 23:08:22 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 18:05:40 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_iterate_bit(t_stack *a, t_stack *b, size_t bit, t_ops *ops)
{
	int		i;

	i = a->size;
	while (i--)
	{
		if ((a->head->index >> bit) & 1)
			ra(a, ops);
		else
			pb(a, b, ops);
	}
	while (b->size)
		pa(a, b, ops);
}

void	ft_complex_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	size_t	bit;

	bit = 0;
	while ((a->size - 1) >> bit)
		ft_iterate_bit(a, b, bit++, ops);
}
