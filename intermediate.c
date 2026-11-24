/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:01:54 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/24 13:47:32 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// Calcular el tamaño del chunk que sería la raiz cuadrada del número de elementos que hay en 'a'
static int	ft_square(int n)
{
	long	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i * i <= (long)n)
		i++;
	return ((int)(i - 1));
}

// Comprobar si hay indices menores de un límite
static int	has_index_below(t_stack *a, int limit)
{
	t_node	*current;
	int		i;

	if (!a || !a->head || a->size <= 0)
		return (0);
	current = a->head;
	i = 0;
	while (i < a->size && current)
	{
		if (current->index < limit)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

// Devuelve la posición del nodo con mayor index en 'b'
static int	find_max_pos(t_stack *b)
{
	t_node	*curr;
	int		pos;
	int		best_pos;
	int		max_idx;

	curr = b->head;
	pos = 0;
	best_pos = 0;
	max_idx = curr->index;
	while (pos < b->size)
	{
		if (curr->index > max_idx)
		{
			max_idx = curr->index;
			best_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (best_pos);
}

// Pasar elementos de 'a' a 'b'
static size_t pass_a_to_b(t_stack *a, t_stack *b, int size_chunk)
{
	size_t	movements;
	int		i;
	int		limit;

	movements = 0;
	i = 1;
	if (!a || !b || size_chunk <= 0)
		return (0);
	while (a->size > 0 && a->head)
	{
		limit = size_chunk * i;
		while (a->size > 0 && a->head && has_index_below(a, limit))
		{
			if(a->head->index < limit)
				pb(a, b);
			else
				ra(a);
			movements++;
		}
		i++;
	}
	return (movements);
}

// Pasar elementos de 'b' a 'a'
static size_t pass_b_to_a(t_stack *a, t_stack *b)
{
	size_t	movements;
	int		pos;

	movements = 0;
	if (!a || !b)
		return (0);
	while (b->size > 0 && b->head)
	{
		pos = find_max_pos(b);
		if (pos <= b->size / 2)
			while (pos-- > 0)
				(rb(b), movements++);
		else
		{
			pos = b->size - pos;
			while (pos-- > 0)
				(rrb(b), movements++);
		}
		pa(a, b);
		movements++;
	}
	return (movements);
}

// Orden basado en chunks dinamicos (algoritmo intermedio). Devuelve el número de movimientos realizados.
size_t dynamic_chunk(t_stack *a, t_stack *b)
{
	int		size_chunk;
	size_t	movements;

	movements = 0;
	if (!a || a->size <= 0)
		return (0);
	size_chunk = ft_square(a->size);	// Calcular el tamaño del chunk
	movements += pass_a_to_b(a, b, size_chunk);	// Mover elementos de 'a' a 'b'
	movements += pass_b_to_a(a, b); // Mover elementos de 'b' a 'a'
	return (movements);
}
