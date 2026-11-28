/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncano-co <ncano-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:31:23 by ncano-co          #+#    #+#             */
/*   Updated: 2026/11/28 16:52:14 by ncano-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function for %c
int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

// Function for %s
int	print_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	while (str[count])
		count++;
	return (count);
}

// Function for %%
int	print_percentage(char c)
{
	if (c == '\0')
		return (0);
	ft_putchar_fd('%', 1);
	return (1);
}
