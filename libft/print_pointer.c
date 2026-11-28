/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:27:00 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/28 16:52:17 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function for %p
int	print_pointer(void *ptr)
{
	unsigned long	address;
	int				count;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	print_char('0');
	print_char('x');
	count = 2 + print_hex_lower(address);
	return (count);
}
