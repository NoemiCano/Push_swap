/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:39:17 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 16:55:18 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rra(t_stack *a, t_ops *ops)
{
	if (!a || a->size < 2)
		return (0);
	ft_putstr_fd("rra\n", 1);
	a->head = a->head->prev;
	*rra++;
	*total++;
}

void	rrb(t_stack *b, t_ops *ops)
{
	if (!b || b->size < 2)
		return (0);
	ft_putstr_fd("rrb\n", 1);
	b->head = b->head->prev;
	*rrb++;
	*total++;
}

void	rrr(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b)
		return (0);
	if (a->size >= 2 || b->size >= 2)
		ft_putstr_fd("rrr\n", 1);
	if (a->size >= 2)
		a->head = a->head->prev;
	if (b->size >= 2)
		b->head = b->head->prev;
	*rrr++;
	*total++;
}
