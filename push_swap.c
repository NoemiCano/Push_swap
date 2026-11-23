/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:16:32 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/23 21:57:14 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;

	if (argc == 1)
		return (0);

	// Recibira el stack a con una lista de enteros
	// Un selector de estrategia (opcional)
	
	// 1. Comprobar que recibimos minimo dos argumentos
	// 2. Comprobar que el stack no viene vacio
	// 3. Si no se especifican parámetros, no mostrar nada y devolver el control al usuario
	// 4. En caso de error, deberá mostrar “Error” seguido de un \n en la salida de error estándar. Algunos de los posibles errores son, por ejemplo: argumentos que no son enteros, argumentos superiores a un número entero, y/o números duplicados.
	// 5. Asignar un indice de desorden.
}

// main inicializa A y B vacíos. Si no hay argumentos (argc == 1), termina sin imprimir nada.
// Parseo y construcción de A: acepta tanto ./push_swap 3 2 1 como ./push_swap "3 2 1". El parseo comprueba cada valor y crea los nodos.
// Validación: cada token debe tener un signo opcional y al menos un dígito; el resto deben ser dígitos. Comprueba el rango de int antes de convertirlo y detecta duplicados por su valor numérico —por ejemplo, 01 y 1 son duplicados—.
// Si algo falla, se libera lo que se haya reservado, se imprime Error\n por stderr y se devuelve un código distinto de cero. Si todo va bien, se asignan índices y se llama al algoritmo.
// Se liberan los stacks al terminar.