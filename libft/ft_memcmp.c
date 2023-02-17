/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:19:43 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/07 13:03:40 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*a;
	unsigned char		*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n > 0)
	{
		if (*a > *b)
		{
			return (*a - *b);
		}
		else if (*a < *b)
		{
			return (*a - *b);
		}
		a++;
		b++;
		n--;
	}
	return (0);
}
/*
int		main(void)
{
	char dest [] = "Andre";
	char src [] = "andre";
	printf("%d\n", ft_memcmp(dest, src, 2));
	printf("%d", memcmp(dest, src, 2));
}
*/