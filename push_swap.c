/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:16:32 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/28 11:27:43 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

// No se como recibir el contador de cuantos sa sb... hacen
static void call_benchmark(t_flag *flag, int movements, double disorder_index)
{
	
}

// Llamar al algoritmo correspondiente
static void call_algorithm(t_stack *a, t_stack *b, t_flag *flag, double disorder_index)
{
	int	movements;

	movements = 0;
	
	if (flag->strategy == "SIMPLE")
		movements += simple(); //Linkear el algoritmo simple
	else if (flag->strategy == "MEDIUM")
		movements += dynamic_chunk(&a, &b);
	else if (flag->strategy == "COMPLEX")
		movements += complex(); //Linkear el algoritmo complejo
	else if (flag->strategy == "ADAPTIVE")
		movements += adaptive(); //Linkear el algoritmo adaptativo
	if (flag->bench == 1)
		call_benchmark(flag, movements, disorder_index);
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
	if (!parse_input(argc, argv, &a)) // Me va a faltar pasarle la posición del index para que sepa donde van los números...
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
