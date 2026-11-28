/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:41:04 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/28 17:36:01 by frfaria          ###   ########.fr       */
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

//  (swap a): Intercambia los dos primeros elementos del stack a. No hace nada si hay solo uno o ningún elemento.
void	sa(t_stack *a, t_ops *ops)
{
	if (!a || a->size < 2)
		return ;
	ft_putstr_fd("sa\n", 1);
	ft_swap(a);
	ops->sa++;
	ops->total++;
}

// (swap b): Intercambia los dos primeros elementos del stack b. No hace nada si hay solo uno o ningún elemento.
void	sb(t_stack *b, t_ops *ops)
{
	if (!b || b->size < 2)
		return ;
	ft_putstr_fd("sb\n", 1);
	ft_swap(b);
	ops->sb++;
	ops->total++;
}

// sa y sb a la vez.
void	ss(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !b || (a->size < 2 && b->size < 2))	//validacion
		return ;
	ft_putstr_fd("ss\n", 1);
	if (a->size >= 2)
		ft_swap(a);
	if (b->size >= 2)
		ft_swap(b);
	ops->ss++;
	ops->total++;
}
