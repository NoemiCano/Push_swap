/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:17:03 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/28 18:08:41 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

// Calcular cuantos valores son mas pequeños
static int	count_smaller(t_node *start, int target_value)
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

// Calcula el índice de deshorden entre 0 y 1.
double compute_disorder(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;
	long	mistakes;
	int		i;
	int		j;

	i = 0;
	mistakes = 0;
	current = stack->head;
	if (!stack || stack->size <= 1 || !stack->head)
		return (0.0);
	while (i < stack->size - 1)
	{
		runner = current->next;
		j = i + 1;
		while (j++ < stack->size)
		{
			if (current->value > runner->value)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
		i++;
	}
	return ((double)mistakes / (((double)stack->size * (stack->size - 1)) / 2.0));
}
