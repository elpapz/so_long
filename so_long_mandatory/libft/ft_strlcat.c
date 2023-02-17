/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 06:03:38 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/09 04:53:43 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	if ((!dst && size == 0))
		return (0);
	d = ft_strlen(src);
	b = ft_strlen(dst);
	c = b;
	a = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (size < b)
		return (d + size);
	while (src[a] && a < size - b - 1)
	{
		dst[c] = src[a];
		a++;
		c++;
	}
	dst[c] = '\0';
	return (b + d);
}
/*
int main (void)
{
	char src[] = " merda";
    	char dest [] = "andre";
    printf("%li \n", ft_strlcat(dest, src, 20));
    //ft_strlcat(dest, src, 20);
    printf("%s \n", dest);
	//SE EU RETIRAR O ESPAÇO ANTES DO "MERDA", ELE DÁ ME CORE DUMPED!
	// BASTA COLOCAR O ESPAÇO QUE NÃO DÁ ERRO NENHUM! MUITO ESTRANHO! 
	//NÃO FAÇO IDEIA DO PORQUE!
}

static size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
	{
		a++;
	}
	return (a);
}
*/