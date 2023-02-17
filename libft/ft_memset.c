/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:44:16 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/09 04:24:16 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*a;

	a = (unsigned char *)s;
	while (n > 0)
	{
		*a = (unsigned char)c;
		a++;
		n--;
	}
	return ((unsigned char *)s);
}
/*
int		main(void)
{
	char s [] = "andre";
	ft_memset(s, 'e', 5);
	printf("%s\n", s);
	memset(s, 'e', 5);
	printf("%s\n", s);
}
*/
