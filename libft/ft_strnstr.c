/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:08:45 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/03 23:32:09 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		a;
	size_t		b;
	size_t		c;

	if ((!haystack && len == 0))
		return (0);
	a = 0;
	b = 0;
	c = ft_strlen(needle);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[b] && len >= c)
	{
		while (needle[a] == haystack[a + b]
			&& haystack[a + b] && needle[a])
		a++;
		if (needle[a] == '\0')
		{
			return ((char *)haystack + b);
		}
		b++;
		len--;
		a = 0;
	}
	return (NULL);
}

/*
int		main(void)
{
	char haystack [] = "map1.ber";
	char needle [] = ".ber";
	int i = ft_strlen(haystack);
	//printf("%s    %s\n", haystack, needle);
	printf("%s\n", ft_strnstr(haystack, needle, i));
	//printf("%s", strstr(haystack, needle));
}
*/
//3 HORAS PARA PERCBER QUE TINHA DE SER COM && EM VEZ DE COM ||.
//PARECE ESTAR PERCEBIDO. 
//NÃO TÃO SIMPLES QUANTO PARECE!
//return ((char*)haystack + b);   //MAIS FAÇIL SE USAR FUNÇÕES AUXILIARES, 