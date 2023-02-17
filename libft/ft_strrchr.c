/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:30:43 by acanelas          #+#    #+#             */
/*   Updated: 2022/11/08 21:27:01 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (s[a])
	{
		a++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[a]);
	while (a >= 0)
	{
		if (s[a] == (char)c)
			return ((char *)s + a);
		a--;
	}
	return (NULL);
}
/*
int		main(void)
{
	char str [] = "abbbbbbb";
	printf("%s\n", ft_strrchr(str, 'a'));
	printf("%s\n", strrchr(str, 'a'));
}
*/
