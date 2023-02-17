/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:48:10 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/07 15:03:19 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		a;

	a = 0;
	while (n > a)
	{
		((char *)s)[a] = 0;
		a++;
	}
}
/*
int		main(void)
{
	char b [] = "aaaa";
	//printf("%s", b);
	ft_bzero(b, 2);
	printf("%i\n", *b);
	bzero(b, 2);
	printf("%i\n", *b);
}
*/