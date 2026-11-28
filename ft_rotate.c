/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:00:28 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 17:14:09 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//  (rotate a): Desplaza hacia arriba todos los elementos del stack a una posición, convirtiendo el primer elemento en el último.
void	ra(t_stack *a, t_ops *ops)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("ra\n", 1);
	a->head = a->head->next;
	ops->ra++;
	ops->total++;
}

// (rotate b): Desplaza hacia arriba todos los elementos del stack b una posición, convirtiendo el primer elemento en el último.
void	rb(t_stack *b, t_ops *ops)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("rb\n", 1);
	b->head = b->head->next;
	ops->rb++;
	ops->total++;
}

// ra y rb a la vez.
void	rr(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b)
		return ;
	if (a->size >= 2 || b->size >= 2)
		ft_putstr_fd("rr\n", 1);
	if (a->size >= 2)
		a->head = a->head->next;
	if (b->size >= 2)
		b->head = b->head->next;
	ops->rr++;
	ops->total++;
}
