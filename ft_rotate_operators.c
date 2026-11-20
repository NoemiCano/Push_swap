/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_operators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:00:28 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/20 18:35:01 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("ra\n", 1);
	a->head = a->head->next; 
}

void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("rra\n", 1);
	a->head = a->head->prev; 
}

void	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("rb\n", 1);
	b->head = b->head->next; 
}

void	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("rrb\n", 1);
	b->head = b->head->prev; 
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (a->size >= 2 || b->size >=2)	//verifica que alguno pueda rotar para imprimir
	ft_putstr_fd("rr\n", 1);
	if (a->size >= 2)
		a->head = a->head->next; 
	if (b->size >= 2)
		b->head = b->head->next; 
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
