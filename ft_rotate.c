/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:00:28 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/21 17:14:23 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("ra\n", 1);
	a->head = a->head->next; 
	return (1);
}

size_t	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("rb\n", 1);
	b->head = b->head->next; 
	return (1);
}

size_t	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (a->size >= 2 || b->size >=2)
		ft_putstr_fd("rr\n", 1);
	if (a->size >= 2)
		a->head = a->head->next; 
	if (b->size >= 2)
		b->head = b->head->next; 
	return (1);
}
