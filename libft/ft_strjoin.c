/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:58:07 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/09 04:37:03 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*str;
	char	*str2;

	str2 = (char *)s2;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	if (!s1)
		return ((char *)s1);
	a = 0;
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (str2[b])
	{
		str[a++] = str2[b++];
	}
	str[a] = '\0';
	return (str);
}
/*
int		main(void)
{
	char	s1 [] = "andre ";
	char	s2 [] = "canelas";
	printf("%s\n", s1);
	printf("%s\n", ft_strjoin(s1, s2));
	//printf("%s", s1);	
}
*/

//return (&((char*)str)[a])(points for the adress instead)