/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:16:32 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/26 17:48:10 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

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

	// Llamar al algoritmo correspondiente
	// Ejecutar el benchark si corresponde
	// Liberar los stacks
}

// main inicializa A y B vacíos. 
// OK - Si no hay argumentos (argc == 1), termina sin imprimir nada.
// OK - Parseo y construcción de A: acepta tanto ./push_swap 3 2 1 como ./push_swap "3 2 1". El parseo comprueba cada valor y crea los nodos.
// OK - Validación: cada token debe tener un signo opcional y al menos un dígito; el resto deben ser dígitos. Comprueba el rango de int antes de convertirlo y detecta duplicados por su valor numérico —por ejemplo, 01 y 1 son duplicados—.
// OK - Si algo falla, se libera lo que se haya reservado, se imprime Error\n por stderr y se devuelve un código distinto de cero. 
// Si todo va bien, se asignan índices y se llama al algoritmo.
// Se liberan los stacks al terminar.
// Benchmark