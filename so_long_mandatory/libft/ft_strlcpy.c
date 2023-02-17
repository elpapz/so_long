/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:33:28 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/06 23:46:44 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		a;

	a = 0;
	if (size > 0)
	{
		while (src[a] && (size - 1) > a)
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (ft_strlen(src));
}
/*
int		main(void)
{
	char src [] = "andre";
	char dst [] = "merda";
	printf("%s        %s\n", src, dst);
	printf("%d", ft_strlcpy(dst, src, 6));
	ft_strlcpy(dst, src, 6);
	printf("%s        %s\n", src, dst);
}
size_t		ft_strlen(const char *s)
{
	size_t		a;

	a = 0;
	while(s[a])
	{
		a++;
	}
	return (a);
}
*/