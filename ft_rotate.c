/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:00:28 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 16:01:03 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//  (rotate a): Desplaza hacia arriba todos los elementos del stack a una posición, convirtiendo el primer elemento en el último.
size_t	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return (0);
	ft_putstr_fd("ra\n", 1);
	a->head = a->head->next;
	return (1);
}

// (rotate b): Desplaza hacia arriba todos los elementos del stack b una posición, convirtiendo el primer elemento en el último.
size_t	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return (0);
	ft_putstr_fd("rb\n", 1);
	b->head = b->head->next;
	return (1);
}

// ra y rb a la vez.
size_t	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	if (a->size >= 2 || b->size >= 2)
		ft_putstr_fd("rr\n", 1);
	if (a->size >= 2)
		a->head = a->head->next;
	if (b->size >= 2)
		b->head = b->head->next;
	return (1);
}
