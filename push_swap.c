/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:16:32 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/24 16:17:36 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	double disorder_index;

	if (argc == 1)
		return (0);
	// Rellenar el stack 'a'
	a = (t_stack){NULL, 0}; // asi se puede inicializar
	if (!parse_input(argc, argv, &a))
	{
		free_stack(&a);
		write_error();
		return (1);
	}
	// Asignar un índice a las posiciones
	ft_assign_index(&a);

	// Asignar el índice de deshorden
	disorder_index = compute_disorder(&a);

	
	// Recibira el stack a con una lista de enteros
	// Un selector de estrategia (opcional)
	
	// OK - 1. Comprobar que recibimos minimo dos argumentos
	// OK - 2. Comprobar que el stack no viene vacio
	// OK - 3. Si no se especifican parámetros, no mostrar nada y devolver el control al usuario
	// OK - 4. En caso de error, deberá mostrar “Error” seguido de un \n en la salida de error estándar. Algunos de los posibles errores son, por ejemplo: argumentos que no son enteros, argumentos superiores a un número entero, y/o números duplicados.
	// OK - 5. Asignar un indice de desorden.
}

// main inicializa A y B vacíos. 
// OK - Si no hay argumentos (argc == 1), termina sin imprimir nada.
// OK - Parseo y construcción de A: acepta tanto ./push_swap 3 2 1 como ./push_swap "3 2 1". El parseo comprueba cada valor y crea los nodos.
// OK - Validación: cada token debe tener un signo opcional y al menos un dígito; el resto deben ser dígitos. Comprueba el rango de int antes de convertirlo y detecta duplicados por su valor numérico —por ejemplo, 01 y 1 son duplicados—.
// OK - Si algo falla, se libera lo que se haya reservado, se imprime Error\n por stderr y se devuelve un código distinto de cero. 
// Si todo va bien, se asignan índices y se llama al algoritmo.
// Se liberan los stacks al terminar.