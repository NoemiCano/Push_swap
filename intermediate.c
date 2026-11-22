/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:01:54 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/22 18:20:09 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// Calcular el tamaño del chunk que sería la raiz cuadrada del número de elementos que hay en 'a'
int	ft_square(int n)
{
	long	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i * i <= (long)n)
		i++;
	return ((int)(i - 1));
}
// Calcular cuantos valores son mas pequeños
static int count_smaller(t_list *start, int target_value)
{
	t_list	*cmp;
	int		smaller;

	if (!start)
		return (0);
	smaller = 0;
	cmp = start;
	while (1)
	{
		if (cmp->value < target_value)
			smaller++;
		cmp = cmp->next;
		if (!cmp || cmp == start)
			break ;
	}
	return (smaller);
}

// Asignar un índice al stack
void	assign_index(t_stack *a)
{
	t_list	*start;
	t_list	*current;

	if (!a || !a->head || a->size <= 0)
		return ;
	start = a->head;
	current = start;
	while (a)
	{
		current->index = count_smaller(start, current->value);
		current = current->next;
		if (!current || current == start)
			break ;
	}
}

// Comprobar si hay indices menores de un límite
static int	has_index_below(t_stack *a, int limit)
{
	t_list	*start;
	t_list	*current;

	if (!a || !a->head || a->size <= 0)
		return (0);
	start = a->head;
	current = start;
	while (1)
	{
		if (current->index < limit)
			return (1);
		current = current->next;
		if (!current || current == start)
			break ;
	}
	return (0);
}

// Devuelve la posición del nodo con mayor index en 'b'
static int	find_max_pos(t_stack *b)
{
	t_list	*curr;
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
size_t pass_a_to_b(t_stack *a, t_stack *b, int size_chunk)
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
size_t pass_b_to_a(t_stack *a, t_stack *b)
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
	assign_index(a);	// Asignar un índice al stack
	size_chunk = ft_square(a->size);	// Calcular el tamaño del chunk
	movements += pass_a_to_b(a, b, size_chunk);	// Mover elementos de 'a' a 'b'
	movements += pass_b_to_a(a, b); // Mover elementos de 'b' a 'a'
	return (movements);
}
