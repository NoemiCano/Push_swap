/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:39:17 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/20 19:39:17 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("rrb\n", 1);
	b->head = b->head->prev; 
}

void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("rra\n", 1);
	a->head = a->head->prev; 
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (a->size >= 2 || b->size >=2)	//verifica que alguno pueda rotar para imprimir
		ft_putstr_fd("rrr\n", 1);
	if (a->size >= 2)
		a->head = a->head->prev; 
	if (b->size >= 2)
		b->head = b->head->prev; 
}
