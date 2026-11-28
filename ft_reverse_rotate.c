/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:39:17 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 17:40:03 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//  (reverse rotate a): Desplaza hacia abajo todos los elementos del stack a una posición, convirtiendo el último elemento en el primero.
void	rra(t_stack *a, t_ops *ops)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("rra\n", 1);
	a->head = a->head->prev;
	ops->rra++;
	ops->total++;
}

// (reverse rotate b): Desplaza hacia abajo todos los elementos del stack b una posición, convirtiendo el último elemento en el primero.
void	rrb(t_stack *b, t_ops *ops)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("rrb\n", 1);
	b->head = b->head->prev;
	ops->rrb++;
	ops->total++;
}

// rra y rrb a la vez.
void	rrr(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b)
		return ;
	if (a->size >= 2 || b->size >= 2)
		ft_putstr_fd("rrr\n", 1);
	if (a->size >= 2)
		a->head = a->head->prev;
	if (b->size >= 2)
		b->head = b->head->prev;
	ops->rrr++;
	ops->total++;
}
