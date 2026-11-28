/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:43:48 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/28 16:52:11 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function for %x
int	print_hex_lower(unsigned long nbr)
{
	int		count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (nbr >= 16)
		count += print_hex_lower(nbr / 16);
	count += write(1, &hex_digits[nbr % 16], 1);
	return (count);
}

// Function for %X
int	print_hex_upper(unsigned long nbr)
{
	int		count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789ABCDEF";
	if (nbr >= 16)
		count += print_hex_upper(nbr / 16);
	count += write(1, &hex_digits[nbr % 16], 1);
	return (count);
}
