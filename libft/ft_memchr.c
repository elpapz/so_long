/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:03:41 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/08 20:18:54 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			b;
	unsigned char	*a;

	b = 0;
	a = (unsigned char *)s;
	while (n > b)
	{
		if (a[b] == (unsigned char)c)
			return ((void *) a + b);
		b++;
	}
	return (NULL);
}
/*
int		main(void)
{
	char s [] = "andre!canelas";
    char *b;
	b = ft_memchr(s, '!', 15);
	printf("%s\n", b);
	//memchr(s, '!', 15);
	//printf("%s\n", s);
}
*/
//FIZ DE TODAS AS MANEIRAS QUE SABIA, ATÉ QUE DEU ASSIM... 
//FOI POR TENTATIVAS, NÃO ENTENDI A LÓGICA!
//NÃO ENTENDO O PORQUE DE TER QUE SER DESTA MANEIRA!