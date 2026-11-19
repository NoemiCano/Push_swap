/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfaria <frfaria@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:11:55 by frfaria           #+#    #+#             */
/*   Updated: 2026/11/19 18:29:15 by frfaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

void	sort(int *arr, int size)
{
	int	i = 0;
	int	j;
	int	tmp;

	while (++i < size)
	{
		j = i;
		tmp = arr[i];
		while (--j >= 0 && tmp < arr[j])
			arr[j + 1] = arr[j];
		arr[j + 1] = tmp;
	}
}

int	main(void)
{
	int	arr[] = {42, -17, 0, 83, -56, 12, 42, -91, 7, 64, -3, 28, 0, -45, 99, 13, -72, 5, 38, -17, 56, -100, 21, 8, 73, -29, 42, 1, -64, 90, 15, -8, 33, 67, -50, 4, 81, -23, 19, 55, -91, 36, 0, 72, -11, 48, 6, -37, 95, 14, -68, 27, 42, -5, 61, 3, -82, 88, 20, -14, 53, 9, -44, 76, 31, -99, 17, 62, -26, 40, 2, -57, 84, 11, -33, 69, 25, -76, 46, 0, 93, -19, 34, 58, -62, 16, 79, -41, 7, 51, -88, 23, 66, -12, 39, 97, -31, 10, 44, -70};

	int	size = sizeof(arr) / sizeof(arr[0]);

	int	i = 0;
	printf("Unordered array: ");
	while (i < size)
		printf("%d, ", arr[i++]);
	sort(arr, size);
	i = 0;
	printf("\nOrdered array: ");
	while (i < size)
		printf("%d, ", arr[i++]);
	printf("\n");
}
