/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:16:32 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/28 18:01:18 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

// No se como recibir el contador de cuantos sa sb... hacen
static void call_benchmark(t_flag *flag, t_ops *op, double disorder_index)
{
	ft_printf("disorder: %d%%", disorder_index);
	if (flag->strategy == "ADAPTIVE")
		ft_printf("Adaptive / O(n√n)");
	else if (flag->strategy == "COMPLEX")
		ft_printf("Complex / O(n log n)");
	else if (flag->strategy == "MEDIUM")
		ft_printf("Medium / O(n√n)");
	else if (flag->strategy == "SIMPLE")
		ft_printf("Simple / O(n^2)");
	ft_printf("total_ops: %i", op->total);
	ft_printf("sa: %i sb: %i ss: %i pa: %i pb: %i", op->sa, op->sb, op->ss, op->pa, op->pb);
	ft_printf("ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i", op->ra, op->rb, op->rr, op->rra, op->rrb, op->rrr);
}

// Llamar al algoritmo correspondiente
static void call_algorithm(t_stack *a, t_stack *b, t_flag *flag, double disorder_index)
{
	t_ops *op;

	*op = (t_ops){0};
	if (flag->strategy == "SIMPLE")
		ft_simple_sort(a, b, op);
	else if (flag->strategy == "MEDIUM")
		dynamic_chunk(a, b, op);
	else if (flag->strategy == "COMPLEX")
		ft_complex_sort(a, b, op);
	else if (flag->strategy == "ADAPTIVE")
		adaptive(a, b, &op, disorder_index);
	if (flag->bench == 1)
		call_benchmark(flag, &op, disorder_index);
	free_stack(&op);
}

static int check_flags(int argc, char **argv, t_flag *flag, int *start_index)
{
	int	i;
	int number_strat;
	
	i = 1;
	number_strat = 0;
	*flag = (t_flag){ADAPTIVE, 0};
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			flag->bench = 1;
		if ((ft_strcmp(argv[i], "--simple") == 00) && number_strat == 0)
		{
			flag->strategy = SIMPLE;
			number_strat = 1;
		}
		else if ((ft_strcmp(argv[i], "--medium") == 00) && number_strat == 0)
		{
			flag->strategy = MEDIUM;
			number_strat = 1;
		}
		else if ((ft_strcmp(argv[i], "--complex") == 00) && number_strat == 0)
		{
			flag->strategy = COMPLEX;
			number_strat = 1;
		}
		else if ((ft_strcmp(argv[i], "--adaptive") == 00) && number_strat == 0)
		{
			flag->strategy = ADAPTIVE;
			number_strat = 1;
		}
		else
			return (0);
		i++;
	}
	*start_index = i;
	return (1);
}

int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_flag	flag;
	double disorder_index;
	int	i;

	b = (t_stack){NULL, 0};
	if (argc == 1)
		return (0);
	if (!check_flags(argc, argv, &flag, &i)) 	// Revisar flags
		return (write_error(), 1);
	a = (t_stack){NULL, 0};		// Rellenar el stack 'a'
	if (!parse_input(argc, argv, &a, i)) // Parseo del stack y rellenaro
	{
		free_stack(&a);
		write_error();
		return (1);
	}
	ft_assign_index(&a);	// Asignar un índice a las posiciones
	disorder_index = compute_disorder(&a);	// Asignar el índice de deshorden
	call_algorithm(&a, &b, &flag, disorder_index); // Llamar al algoritmo correspondiente // Ejecutar el benchark si corresponde
	free_stack(&a); // Liberar los stacks
	free_stack(&b);
}
