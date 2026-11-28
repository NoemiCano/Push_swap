/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 00:04:09 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/26 20:24:28 by frfaria          ###   ########.fr       */
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

int	no_target(t_stack *a, t_cost *new, t_node *small)
{
	t_node	*node_a;

	node_a = a->head;
	new->a = 0;
	while (node_a != small)
	{
		node_a = node_a->next;
		new->a++;
	}
	return (new->a);
}

int	find_target(t_stack *a, t_stack *b, t_node *node_b, t_cost *new)
{
	t_node	*node_a;
	t_node	target;
	t_node	*small;

	small = a->head;
	node_a = a->head;
	new->a = 0;
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
		return (no_target(a, new, small));
	return (target.value);
}

t_cost	ft_calc_cost(t_stack *a, t_stack *b, t_cost *new)
{
	t_cost	tmp;
	t_cost	best;

	tmp = (t_cost){0, 0, 0};
	if (new->b && b->size)	//calcula el coste de rotaciones inversas de a
		tmp.b = new->b - b->size;
	if (new->a && a->size)	//y de b
		tmp.a = new->a - a->size;
	best = (t_cost){new->a, new->b, (size_t)new->a};	//asume que el mejor caso es ra, rb, a siendo mayor que b
	if (new->b > new->a)	//comprueba si b es mayor que a
		best.total = (size_t)new->b;
	if ((size_t)(new->a - tmp.b) < best.total)	//comprueba si ra rrb es mejor 
		best = (t_cost){new->a, tmp.b, new->a - tmp.b};
	if ((size_t)(new->b - tmp.a) < best.total)	//comprueba si rra rb es mejor
		best = (t_cost){tmp.a, new->b, new->b - tmp.a};
	if ((tmp.a <= tmp.b) && (size_t)-tmp.a < best.total)	//comprueba si rra rrb es mejor
		best = (t_cost){tmp.a, tmp.b, -tmp.a};
	if ((tmp.b < tmp.a) && (size_t)-tmp.b < best.total)		//de nuevo pero si b rota mas que A
		best = (t_cost){tmp.a, tmp.b, -tmp.b};
	return (best);
}

t_cost	ft_find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*node_b;
	t_cost	cheap;
	t_cost	new;
	int		b_pos;

	cheap = (t_cost){0, 0, a->size + b->size + 1};
	new = (t_cost){0, 0, a->size + b->size + 1};
	node_b = b->head;
	b_pos = 0;
	while (1)
	{
		new.a = find_target(a, b, node_b, &new);
		new = ft_calc_cost(a, b, &new);
		if (cheap.total > new.total)
			cheap = new;
		node_b = node_b->next;
		if (node_b == b->head)
			break ;
		b_pos++;
		new.b = b_pos;
	}
	return (cheap);
}
