/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:54:03 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/09 05:04:41 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*dst;
	unsigned char	*s;

	if ((!src && !dest))
		return (NULL);
	dst = ((unsigned char *)dest);
	s = ((unsigned char *)src);
	a = 0;
	while (n > a)
	{
		dst[a] = s[a];
		a++;
	}
	return (dst);
}
/*
int		main(void)
{
	char dest [] = "andre";
	char src [] = "canelas";
	char *b;
	//b = ft_memcpy(dest, src, 2);
	//printf("%s\n", b);
	b = memcpy(dest, src, 2);
	printf("%s\n", b);
}
*/