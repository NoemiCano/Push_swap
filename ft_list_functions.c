/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:27:36 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/20 16:27:36 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_front(t_stack *stack, t_list *new)
{
	if (!stack || !new)
		return ;
	if (stack->head) //para un stack con contenido
	{
		stack->head->prev->next = new;	//actualiza el next del ultimo elemento
		new->next = stack->head;		//actualiza next del nuevo elemento al que era primero
		new->prev = stack->head->prev;	//actualiza prev del nuevo elemento al ultimo
		stack->head->prev = new;		//actualiza al ultimo elemento para que apunte al nuevo con prev
		stack->head = new;				//asigna nueva cabeza del stack
	}
	else	//stack sin contenido
	{
		new->next = new;	//se apunta a si mismo en next y prev para crear la lista circular
		new->prev = new;	//asi si se añaden nuevos elementos pueden trabajar con los next/prev de stack->head
		stack->head = new;
	}
	stack->size++;					//aumenta tamaño del stack
}

void	ft_stack_add_back(t_stack *stack, t_list *new)
{
	if (!stack || !new)
		return ;
	if (stack->head) //para un stack con contenido
	{
		new->next = stack->head;		//actualiza next del nuevo elemento al primero
		new->prev = stack->head->prev;	//actualiza prev del nuevo elemento al antiguo ultimo
		stack->head->prev->next = new;	//actualiza el next del ultimo elemento
		stack->head->prev = new;		//actualiza el prev del primer elemento al ultimo
	}
	else	//stack sin contenido
	{
		new->next = new;	//se apunta a si mismo en next y prev para crear la lista circular
		new->prev = new;	//asi si se añaden nuevos elementos pueden trabajar con los next/prev de stack->head
		stack->head = new;
	}
	stack->size++;					//aumenta tamaño del stack
}
