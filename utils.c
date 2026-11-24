/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:17:03 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/24 13:38:56 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

// Calcular cuantos valores son mas pequeños
static int count_smaller(t_node *start, int target_value)
{
	t_node	*cmp;
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
void	ft_assign_index(t_stack *a)
{
	t_node	*current;

	if (!a || !a->head || a->size <= 0)
		return ;
	current = a->head;
	while (a)
	{
		current->index = count_smaller(a->head, current->value);
		current = current->next;
		if (!current || current == a->head)
			break ;
	}
}

void	write_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	free_stack(t_stack *stack)
{
    t_node	*node;

    if (!stack)
        return ;
    while (stack->head)
    {
        node = ft_detach_stack_head(stack);
        free(node);
    }
}



// En caso de error, deberá mostrar “Error” seguido de un \n en la salida de error estándar. Algunos de los posibles errores son, por ejemplo: argumentos que no son enteros, argumentos superiores a un número entero, y/o números duplicados.
// Asignar el index desde aquí
// ft_assign_index asigna a cada nodo el número de valores menores. Como no detecta duplicados, dos valores iguales recibirían el mismo índice; valida duplicados antes de llamar a esa función.