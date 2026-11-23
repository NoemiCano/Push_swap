/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:17:03 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/23 21:57:29 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

void	write_error()
{
	ft_putstr_fd("Error\n", 2);
}

void	error_checking(t_stack *stack)
{
	
}

// En caso de error, deberá mostrar “Error” seguido de un \n en la salida de error estándar. Algunos de los posibles errores son, por ejemplo: argumentos que no son enteros, argumentos superiores a un número entero, y/o números duplicados.
// Asignar el index desde aquí
// ft_assign_index asigna a cada nodo el número de valores menores. Como no detecta duplicados, dos valores iguales recibirían el mismo índice; valida duplicados antes de llamar a esa función.