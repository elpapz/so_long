/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 03:23:16 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/09 05:07:25 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	a;

	a = 0;
	if (s[a])
	{
		while (s[a])
		{
			f(a, (&(s)[a]));
			a++;
		}
	}
}

/*
int		main(void)
{
	char	str[] = "andre";
	ft_striteri(str, caralho);
	printf("%s", str);
	
}
static void	caralho(unsigned int a, char *s)
{
	if (s[a] == 'a')
		s[a] = s[a] - 32;
	else if (s[a] == 'n')
		s[a] = s[a] - 32;
	else if (s[a] == 'd')
		s[a] = s[a] - 32;
	else if (s[a] == 'r')
		s[a] = s[a] - 32;
	else if (s[a] == 'e')
		s[a] = s[a] - 32;
}
*/