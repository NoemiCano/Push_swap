/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 23:08:22 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/27 23:08:22 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	ft_iterate_bit(t_stack *a, t_stack *b, size_t bit)
{
	size_t	c;
	int		i;

	c = 0;
	i = a->size;
	while (i--)
	{
		if ((a->head->index >> bit) & 1)
			c += ra(a);
		else
			c += pb(a, b);
	}
	while (b->size)
		c += pa(a, b);
	return (c);
}

size_t	ft_complex_sort(t_stack *a, t_stack *b)
{
	size_t	c;
	size_t	bit;

	c = 0;
	bit = 0;
	while ((a->size - 1) >> bit)
		c += ft_iterate_bit(a, b, bit++);
	return (c);
}
