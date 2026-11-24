/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 00:04:09 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/24 00:25:52 by frfaria          ###   ########.fr       */
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

t_node	no_target(t_stack *a, t_cost *new, t_node *small)
{
	t_node	*node_a;
	t_node	target;

	node_a = a->head;
	new->a = 0;
	while (node_a != small)
		(node_a = node_a->next, new->a++);
	target = (t_node){new->a, node_a->index, NULL, NULL};
	return (target);
}

t_node	find_target(t_stack *a, t_stack *b, t_node *node_b, t_cost *new)
{
	t_node	*node_a;
	t_node	target;
	t_node	*small;

	small = a->head;
	node_a = a->head;
	target = (t_node){0, a->size + b->size, NULL, NULL};
	while (1)
	{
		if (node_a->index > node_b->index && node_a->index < target.index)		//parsea y encuentra el nuevo index mas bajo que este
			target = (t_node){new->a, node_a->index, NULL, NULL};	//por encima del nodo analizado de b
		if (small->index > node_a->index)
			small = node_a;
		node_a = node_a->next;
		if (node_a == a->head)
			break ;
		new->a++;
	}
	if (target.index == a->size + b->size) //en caso de no encontrar ninguno valido (node_b es mayor que todo el stack a)
		target = no_target(a, new, small);
	return (target);
}

t_cost	ft_price(t_stack *a, t_stack *b, t_node *node_b, t_cost *cheap)
{
	t_node	*target;
	t_cost	new;

	new = (t_cost){0, 0, a->size + b->size + 1};
	target = b->head;
	while (target != node_b)
		(target = target->next, new.b++);
	target = find_target(a, b, node_b, &new);
	if (new.b)
}

t_cost	ft_find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_cost	cheap;

	cheap = (t_cost){0, 0, a->size + b->size + 1};
	tmp = b->head;
	while (1)
	{
		ft_price(a, b, tmp, &cheap);
		tmp = tmp->next;
		if (tmp == b->head)
			break ;
	}
	return (cheap);
}
