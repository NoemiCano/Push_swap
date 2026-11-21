/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:41:04 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/21 17:14:23 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_swap(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (a->size == 2)
	{
		a->head = a->head->next;
		return ;
	}
	tmp = a->head;				//valores temporales para hacer el cambio
	tmp2 = a->head->next;

	a->head->prev->next = tmp2;	//el next del ultimo elemento es asignado al 2o elm
	tmp2->next->prev = tmp;		//el prev del 3er elemento es asignado al primer elemento (que sera colocado en 2a pos)
	tmp->next = tmp2->next;		//next del primero se asigna al 3o
	tmp2->next = tmp;			//next del 2o se asigna al primero
	tmp2->prev = tmp->prev;		//prev del 2o se asigna al ultimo
	tmp->prev = tmp2;			//previo del primero se asigna al segundo
	a->head = tmp2;				//head se asigna al segundo, convirtiendolo en el nuevo primero
}

void	sa(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("sa\n", 1);
	ft_swap(a);
}

void	sb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("sb\n", 1);
	ft_swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b || (a->size < 2 && b->size < 2))	//validacion
		return ;
	ft_putstr_fd("ss\n", 1);
	if (a->size >= 2)
		ft_swap(a);
	if (b->size >= 2)
		ft_swap(b);
}
