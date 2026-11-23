/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:42:21 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/23 21:29:09 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	ft_sort3(t_stack *a)
{
	t_node	*tmp;
	size_t	ops;

	ops = 0;
	tmp = a->head;
	if (tmp->index < tmp->next->index && tmp->next->index < tmp->prev->index) // 0 1 2 (return)
		return (ops);
	if (tmp->index < tmp->next->index && tmp->index < tmp->prev->index) // 0 2 1 -> 2 0 1
		(sa(a), ops++);
	else if (tmp->index > tmp->next->index && tmp->index < tmp->prev->index) // 1 0 2 -> 0 1 2
		(sa(a), ops++);
	else if (tmp->index > tmp->next->index
			&& tmp->next->index > tmp->prev->index) // 2 1 0 -> 1 2 0
		(sa(a), ops++);
	if (a->head->prev->index < a->head->next->index) // 1 2 0 -> 0 1 2
		(rra(a), ops++);
	else if (a->head->index > a->head->next->index) // 2 0 1 -> 0 1 2
		(ra(a), ops++);
	return (ops);
}

t_node	find_target(t_stack *a, t_stack *b, t_node *tmp)
{
	t_node	*tmp1;
	t_node	tmp2;
	int		i;

	i = 0;
	tmp1 = a->head;
	tmp2 = (t_node){0, a->size + b->size, NULL, NULL};
	while (1)
	{
		if (tmp1->index > tmp->index && tmp1->index < tmp2.index)	//parsea y encuentra el nuevo index mas bajo que este
			tmp2 = (t_node){i, tmp1->index, NULL, NULL};			//por encima del nodo analizado de b
		tmp1 = tmp1->next;
		if (tmp1 == a->head)
			break ;
		i++;
	}
	if (tmp2.index == a->size + b->size) //en caso de no encontrar ninguno valido (tmp es mayor que todo el stack a)
	{
		i = 0;
		tmp1 = a->head;
		while (1)
		{
			if (tmp1->index < tmp2.index) //busca el index mas pequeño del stack a
				tmp2 = (t_node){i, tmp1->index, NULL, NULL};
			tmp1 = tmp1->next;
			if (tmp1 == a->head)
				break ;
			i++;
		}
	}
	return (tmp2);
}

void	ft_price(t_stack *a, t_stack *b, t_node *tmpb, int *cost)
{
	t_node	target;
	int		tmp[3];

	tmp[1] = 0;
	target = b->head;
	while (target != tmpb && ++tmp[1])
		target = target->next;
	target = find_target(a, b, tmp);
}

t_cost	ft_find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_cost	cheap;

	cheap = (t_cost){0, 0, a->size};
	tmp = b->head;
	while (1)
	{
		price(a, b, tmp, cost);
		tmp = tmp->next;
		if (tmp = b->head)
			break ;
	}
	return (cheap);
}

size_t	ft_simple_sort(t_stack *a, t_stack *b)
{
	t_cost	moves;
	size_t	total_ops;

	total_ops = ft_assign_index(a);
	while (a->size > 3)
		pb(a, b);
	total_ops += (size_t)b->size;
	ft_sort3(a);
	while (b->size)
	{
		moves = ft_find_cheapest(a, b);
		total_ops += moves.total;
		ft_insert(a, b, moves);
	}
	return (ops);
}
