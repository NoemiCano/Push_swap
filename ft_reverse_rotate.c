/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:39:17 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/22 18:32:13 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//  (reverse rotate a): Desplaza hacia abajo todos los elementos del stack a una posición, convirtiendo el último elemento en el primero.
void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("rra\n", 1);
	a->head = a->head->prev; 
}

// (reverse rotate b): Desplaza hacia abajo todos los elementos del stack b una posición, convirtiendo el último elemento en el primero.
void	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("rrb\n", 1);
	b->head = b->head->prev; 
}

// rra y rrb a la vez.
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
