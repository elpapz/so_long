/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:52:00 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/07 00:54:49 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		a;

	a = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[a])
	{
		str[a] = f(a, s[a]);
		a++;
	}
	str[a] = '\0';
	return (str);
}
/*
int		main(void)
{
	//char *d;
	char str[] = "andre";
	//d = ft_strmapi(str,tua_mae);
	printf("%s\n",ft_strmapi(str, tua_mae));
}
static char	tua_mae(unsigned int a, char str)
{
	printf("%i       %c\n", a, str);
	if (str >= 'a' && str <= 'z')
	str = str - 32;
	return (str);

}
*/